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
- Subjectwise number of students for each grade
- Optional skipping of invalid records

## Module Description

| Module | Files | Purpose |
|------|------|--------|
| Main | main.c | Controls program flow |
| Data | student.h | Student and subject structures |
| Compute | compute.c / compute.h | Grade and CGPA calculation |
| Validate | validate.c / validate.h | Input validation |
| Error | errorhandler.c / errorhandler.h | Error handling |
| Display | display.c / display.h | Result and statistics output |

## Build & Run

```
make result   #To compile all files 
./result input.txt output.txt #TO execute
cat output.txt   #To read output (optional)
```

## Notes

- Validates alphanumeric IDs, unique IDs, names with letters only, and marks (Minor: 0–40, Major: 0–60)
- Grade points are integers; grades assigned based on percentage
- Skips invalid records if user chooses
- Invalid marks are rejected
- CGPA is zero if any subject is failed

### Quality Characteristics

#### Usability

- Clear prompts and error messages
- Option to skip invalid records
- Readable tabular output

#### Efficiency

- Single-pass processing
- No dynamic memory allocation
- Minimal memory usage

#### Reusability

- Computation and validation modules are reusable
- Student structure shared across modules

#### Interoperability

- File-based input/output allows integration with other tools
- Input can be generated from scripts or other applications
