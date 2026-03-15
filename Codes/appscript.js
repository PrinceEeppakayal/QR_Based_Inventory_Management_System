function doGet(e) {
  var sheet = SpreadsheetApp.openById("YOUR_ID").getActiveSheet();

  if (!e.parameter.id) {
    return ContentService.createTextOutput("No data received");
  }

  var productId = e.parameter.id.trim();
  var timestamp = new Date();

  var data = sheet.getRange("B:B").getValues();
  var targetRow = data.findIndex(row => row[0] === "");

  if (targetRow === -1) {
    return ContentService.createTextOutput("Error: No empty row found.");
  }

  sheet.getRange(targetRow + 1, 1).setValue(timestamp);  // Date
  sheet.getRange(targetRow + 1, 2).setValue(productId);  // Product ID

  return ContentService.createTextOutput("Success");
}

function submitInvoice() {
  var ss = SpreadsheetApp.getActiveSpreadsheet();
  var invoiceSheet = ss.getSheetByName("Invoice");
  var mainSheet = ss.getSheetByName("Main");

  // Generate Invoice Number automatically
  var invoiceNoCell = invoiceSheet.getRange("B3");
  var currentInvoiceNo = invoiceNoCell.getValue();
  var newInvoiceNo = "INV-" + new Date().getTime(); // or any other logic you want
  invoiceNoCell.setValue(newInvoiceNo);

  var lastRow = invoiceSheet.getLastRow();
  var data = invoiceSheet.getRange("A9:E" + lastRow).getValues();

  for (var i = 0; i < data.length; i++) {
    var row = data[i];
    if (row[0] !== "") {
      mainSheet.appendRow([
        new Date(),   // Timestamp
        row[0],       // Product ID
        row[1],       // Product Name
        row[2],       // Price
        row[3],       // Quantity
        row[4]        // Amount
        // Exclude status, name, phone, invoice no
      ]);
    }
  }

  // Clear scanned items (A9:E)
  invoiceSheet.getRange("A9:E" + lastRow).clearContent();

  // Clear customer details (Name, Phone, Invoice No)
  invoiceSheet.getRange("B1:B3").clearContent();

  SpreadsheetApp.getUi().alert("Invoice submitted successfully!");
}


function printInvoice() {
  SpreadsheetApp.flush();
  SpreadsheetApp.getUi().alert("Use File → Print or press Ctrl+P to print this invoice.");
}
