# Student Record Parser
A C application that reads student records from a CSV file, parses the data, and displays student information in a structured format.

## Features
* Read student records from a CSV file
* Parse comma-separated values
* Store records using structures
* Dynamic memory allocation using realloc
* Display student information in a formatted output

## How It Works
1. The program opens the CSV file.
   (A sample CSV file (Records.csv) is included in the repository so you can run and test the program immediately.)
3. Each line is read sequentially.
4. The record is split into:
   * Student ID
   * Student Name
   * Student Marks
5. The parsed data is stored in a structure.
6. The student information is displayed on the console.
