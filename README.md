Electrical Load Monitoring and Billing Simulator

Student Name: [Offei Benjamin Kumi] Index Number: [01241400D] Course: EEE 227 (PT)

Project Overview

This C++ application allows users to manage electrical appliances, calculate energy consumption, and estimate billing costs.

Week 1 Progress

Created core C++ application structure.
Implemented appliance search and registration logic.
Set up data logging files (appliance.txt and billing_summary.txt).
Configured GitHub repository for version control.
Electrical Load Monitoring System

A C++ application that calculates daily energy consumption and generates a monthly billing report.

How to use

Add appliances to appliance.txt (Format: Name Watts Hours).
Note: Use underscores for multi-word names (e.g., Water_pump).
Run the program and select Option 5 to generate billing_summary.txt.
How to Run the Simulator

Prerequisites: Ensure you have a C++ compiler (like MinGW) installed.
Compilation: Open your terminal in this folder and run: g++ main.cpp -o Loadmonitor
Execution: Run the program by typing: ./LoadMonitor
Data Persistence:
Appliance data is automatically saved to appliance.txt.
The billing report is generated in billing_summary.txt.
The electricity tariff is saved in config.txt.g++ main.cpp -o LoadMonitor