# QR-Based Inventory Management System

## Overview
This project implements a **QR Code–based Inventory Management System** using an **ESP8266 microcontroller** and **Arduino firmware**. The system scans QR codes and sends the data via Wi-Fi to a **Google Sheets database**, enabling real-time inventory tracking.

## Problem Statement
Small retail stores often use **manual paper records** for inventory management. These records are prone to loss, damage, and manipulation, leading to inaccurate stock tracking.

This project proposes a **low-cost IoT-based solution** that automates inventory logging using QR codes.

## Features
- QR code based product identification
- Real-time inventory logging
- Wi-Fi data transmission using ESP8266
- Cloud storage using Google Sheets
- Cost-effective system for small businesses

## Hardware Used
- ESP8266 (NodeMCU)
- MH-ET LIVE QR / Barcode Scanner
- Power supply
- Internet connection

## Software Used
- Arduino IDE
- ESP8266 WiFi libraries
- Google Apps Script
- Google Sheets

## Working Principle
1. Each product is assigned a **unique QR code**.
2. The **QR scanner reads the code**.
3. The ESP8266 processes the data.
4. Data is sent through **Wi-Fi** to Google Sheets.
5. The spreadsheet stores **product ID and timestamp**.

## Project Structure
```
qr-inventory-management
│
├── Codes
│   ├── IMS.ino
│   └── appscript.js
│
├── Videos
│   ├── Interview Video.mp4
│   └── Demonstration Video.mp4
│
├── Images
│   ├── Interview image.jpg
│   ├── Observation image.jpg
│   ├── Organization Visit Image.jpg
│   └── Block Digram.jpg
│
├── Documents
│   ├── QR Code.docx
│   ├── REPORT_FIELD_PROJECT.docx
│   ├── Comparative Analysis of QR Code.docx
│   ├── Field Project Synopsis.docs
│   └── QR BASED INVENTORY MANAGEMENT SYSTEM.pptx
│
└── README.md
```

## Future Improvements
- Web dashboard for inventory analytics
- Mobile application integration
- Automatic low-stock alerts

## Author
Jyotiraditya Bhosale
Prince Eppakayal
Vedant Jagdale
Om Rajbhar

## License
Educational project.
