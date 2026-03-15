QR-Based Inventory Management System
Overview

This project implements a QR Code–based Inventory Management System designed to replace traditional paper-based record keeping used in small retail and spare-part outlets. Manual record systems are prone to misplacement, human errors, and document forgery, which can lead to financial discrepancies.

The proposed system digitizes inventory tracking using a QR code scanner connected to an ESP8266 microcontroller. The scanned product data is transmitted through Wi-Fi to a Google Sheets database, enabling real-time inventory logging and remote monitoring.

Problem Statement

Many small businesses still maintain inventory using paper registers, which can be easily lost, damaged, or manipulated. These issues lead to inaccurate stock tracking and possible financial scams.

The goal of this project is to design a cost-effective digital inventory tracking system using QR codes and IoT technology to ensure reliable and transparent data management.

Features

• QR code–based product identification
• Real-time inventory logging
• Wi-Fi–enabled data transmission using ESP8266
• Cloud-based storage using Google Sheets
• Reduced risk of data loss or record forgery
• Simple and low-cost hardware implementation

System Architecture

The system consists of the following components:

QR Code Scanner Module
Scans product QR codes and outputs the encoded data through serial communication.

ESP8266 Microcontroller
Receives scanned data and processes it using Arduino firmware.

Wi-Fi Communication
The ESP8266 connects to the internet and sends the scanned data to a cloud database.

Google Sheets Database
Stores product details, timestamps, and transaction logs for inventory tracking.

Hardware Requirements

ESP8266 (NodeMCU / ESP-12 based board)

MH-ET LIVE QR / 1D / 2D Barcode Scanner V3.0

USB cable for programming

Power supply

Internet connection

Software Requirements

Arduino IDE

ESP8266 Board Package for Arduino

Google Sheets Web API / Google Apps Script

Serial communication libraries

Working Principle

Each inventory item is assigned a unique QR code containing product information.

The QR scanner reads the code and sends the encoded data to the ESP8266 via serial communication.

The ESP8266 processes the scanned data using Arduino firmware.

Using its built-in Wi-Fi capability, the ESP8266 sends the data to a Google Sheets spreadsheet.

The spreadsheet automatically logs product ID, timestamp, and transaction details, creating a real-time inventory database.

Project Setup
1. Clone the Repository
git clone https://github.com/yourusername/qr-inventory-management.git
cd qr-inventory-management
2. Install ESP8266 Board in Arduino IDE

Open Arduino IDE

Go to File → Preferences

Add the ESP8266 board manager URL

http://arduino.esp8266.com/stable/package_esp8266com_index.json

Install ESP8266 Boards from the Boards Manager

3. Upload the Firmware

Connect the ESP8266 board to your computer.

Select the correct COM port and board type.

Upload the Arduino code from the repository.

4. Configure Google Sheets Integration

Create a Google Sheet for storing inventory logs.

Use Google Apps Script to create a Web API endpoint.

Insert the Web App URL inside the ESP8266 Arduino code.

Example Logged Data
Timestamp	Product ID	Action
2026-03-12 10:12	SP001	Added
2026-03-12 11:05	SP002	Removed
Applications

Retail inventory tracking

Spare parts store management

Warehouse stock monitoring

Small business digital inventory systems

Future Improvements

Web dashboard for real-time analytics

Mobile application for inventory monitoring

Automatic stock alerts when items run low

Integration with barcode/QR printing systems

Author

Jyotiradiya Bhosale
Prince Eppakayal
Vedant Jagdale
Om Rajbhar

License

This project is developed for academic and educational purposes.
