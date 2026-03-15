#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <SoftwareSerial.h>

// WiFi Credentials
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

// Google Script URL (Replace with your script URL)
const char* googleScriptURL = "https://script.google.com/macros/s/YOUR_SCRIPT_ID/exec";

// QR Scanner Serial Communication
SoftwareSerial qrSerial(D5, D6); // RX, TX

WiFiClientSecure client;

void setup() {
    Serial.begin(115200);
    qrSerial.begin(9600);

    // Connect to WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    // Disable SSL certificate verification (For Google Scripts)
    client.setInsecure();
}

void loop() {
    if (qrSerial.available()) {
        String qrData = qrSerial.readStringUntil('\n');
        qrData.trim();  // Remove extra spaces
        qrData.replace(",", ""); // Remove any extra commas

        Serial.print("Scanned QR Code: ");
        Serial.println(qrData);

        if (qrData.length() > 0) {
            sendDataToGoogleSheets(qrData);
        }
    }
    delay(1000);
}

String urlEncode(String str) {
    String encodedString = "";
    char c;
    char code0;
    char code1;
    for (int i = 0; i < str.length(); i++) {
        c = str.charAt(i);
        if (isalnum(c)) {
            encodedString += c;
        } else {
            code0 = (c >> 4) & 0xF;
            code1 = (c & 0xF);
            encodedString += '%';
            encodedString += "0123456789ABCDEF"[code0];
            encodedString += "0123456789ABCDEF"[code1];
        }
    }
    return encodedString;
}

void sendDataToGoogleSheets(String qrData) {
    if (client.connect("script.google.com", 443)) {
        String encodedData = urlEncode(qrData);
        String url = String(googleScriptURL) + "?id=" + encodedData;

        Serial.println("Sending data to Google Sheets...");
        Serial.println("Request URL: " + url); // Debugging

        client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                     "Host: script.google.com\r\n" +
                     "Connection: close\r\n\r\n");

        delay(1000);

        while (client.available()) {
            String response = client.readString();
            Serial.println("Server Response: " + response);
        }
        client.stop();
    } else {
        Serial.println("Failed to connect to Google Script");
    }
}
