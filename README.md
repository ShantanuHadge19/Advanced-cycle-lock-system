# Smart Cycle Lock System

A smart locking system for rental cycles that enables secure access using OTP-based authentication with time-based billing.

---

## System Overview

- User scans the QR code and makes payment based on usage time (e.g., ₹1 for 1 minute, ₹2 for 2 minutes, ₹3 for 3 minutes).  
- An OTP is sent to the registered mobile number after successful payment.  
- User enters the OTP using a keypad (up to 3 attempts allowed).  
- Upon successful verification, the cycle is unlocked.  
- The system tracks usage time and displays information on the LCD.  
- User can pause the ride when needed and resume later, or end the ride after completion.  
- An IR sensor ensures that the cycle is not locked while it is still in use.  
- If usage exceeds the paid time, extra time and additional cost are displayed on the LCD.  

---

## Features

- OTP-based secure access  
- Time-based billing system  
- LCD and keypad user interface  
- Safety mechanism using IR sensor  

---

## Software and Hardware Used

- ESP32  
- Embedded C  
- 3×4 Keypad  
- 16×2 LCD Display  
- IR Sensor  
- Servo Motor (Lock Mechanism)  
- 3.7V LiPo Battery  

---

## Project Structure

- `code/` → Microcontroller code for lock system  
- `hardware/` → Components and block diagram  

---

## Note

This project demonstrates a practical and secure rental cycle locking system with user authentication and time-based billing.

---

## Author

Shantanu Hadge
