# Student Result Processing System
Student: K S Harish Balagi  
Reg No: 25MCMI09  
Date: 14-Jan-2026

## Overview
A C program to process student results for 5 subjects:
- Input & validation of student details and marks
- Calculation of total, percentage, grade, and CGPA
- Display tabular report of students
- Compute class statistics (average, highest, lowest)
- Optional skipping of invalid records

## Files
| File                     | Description                                           |
|--------------------------|-------------------------------------------------------|
| main.c                   | Program entry point, file reading, flow control      |
| students.c               | Functions for computation, report, and statistics   |
| compute.c / compute.h    | Functions for marks, grade, and CGPA calculation    |
| validate.c / validate.h  | Validation functions for IDs, names, and marks      |
| errorhandler.c / errorhandler.h | Print errors and prompt to skip records     |

## Build & Run
```
$ make
$ ./result input.txt output.txt
```
## Notes
- Validates alphanumeric IDs, unique IDs, names with letters only, and marks (Minor: 0–40, Major: 0–60)
- Grade points are integers; grades assigned based on percentage
- Skips invalid records if user chooses
