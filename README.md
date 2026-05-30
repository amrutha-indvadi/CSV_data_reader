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
2. Each line is read sequentially.
3. The record is split into:
   * Student ID
   * Student Name
   * Student Marks
4. The parsed data is stored in a structure.
5. The student information is displayed on the console.
