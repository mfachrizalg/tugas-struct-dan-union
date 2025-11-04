# Student Grading System

A C++ program that manages student academic records, automatically assigns letter grades based on test scores, and identifies top-performing students.

## Overview

This program demonstrates the implementation of structured data types in C++ by managing academic records for 20 students. It processes student information, assigns letter grades based on standardized scoring thresholds, and generates comprehensive reports with statistical analysis.

## Program Structure

### Data Structure

```cpp
struct studentType {
    string studentFName;    // Student's first name
    string studentLName;    // Student's last name
    int testScore;          // Test score (0-100)
    char grade;             // Letter grade (A-F)
};
```

### Core Functions

| Function | Purpose |
|----------|---------|
| `readStudentData()` | Reads and validates student information from user input |
| `assignGrades()` | Assigns letter grades based on numerical scores |
| `findHighestScore()` | Determines the highest test score in the class |
| `printHighestScorers()` | Displays students who achieved the highest score |
| `printStudentData()` | Generates formatted report of all student records |

## Grading Scale

| Score Range | Letter Grade |
|-------------|--------------|
| 90 - 100    | A            |
| 80 - 89     | B            |
| 70 - 79     | C            |
| 60 - 69     | D            |
| 0 - 59      | F            |

## How It Works

```mermaid
flowchart TD
    Start([Start Program]) --> Init[Initialize 20 students array]
    Init --> Input[Read Student Data<br/>First Name, Last Name, Test Score]
    Input --> Validate{Input Valid?<br/>Score 0-100}
    Validate -->|No| Input
    Validate -->|Yes| Assign[Assign Grades<br/>A: >=90, B: >=80<br/>C: >=70, D: >=60, F: less than 60]
    Assign --> Print1[Print Student Report<br/>Name, Score, Grade]
    Print1 --> FindMax[Find Highest Score]
    FindMax --> Print2[Print Highest Score<br/>and Students with Highest Score]
    Print2 --> End([End Program])

    classDef startEnd fill:#4CAF50,stroke:#2E7D32,stroke-width:3px,color:#fff
    classDef process fill:#2196F3,stroke:#1565C0,stroke-width:2px,color:#fff
    classDef decision fill:#FF9800,stroke:#E65100,stroke-width:2px,color:#fff
    classDef output fill:#9C27B0,stroke:#6A1B9A,stroke-width:2px,color:#fff

    class Start,End startEnd
    class Init,Assign,FindMax process
    class Validate decision
    class Input,Print1,Print2 output
```

## Usage Example

### Input Format

```
Enter data for 20 students:
Format: FirstName LastName TestScore
----------------------------------------
Student 1: John Doe 95
Student 2: Jane Smith 88
Student 3: Alice Johnson 92
...
```

### Sample Output

```
============================================================
STUDENT GRADE REPORT
============================================================
Student Name             Test Score     Grade
------------------------------------------------------------
Doe, John                95             A
Smith, Jane              88             B
Johnson, Alice           92             A
...
============================================================

Highest Test Score: 95

Students having the highest test score:
Doe, John
```

## Author
- **Name**: Muhammad Fachrizal Giffari
- **NIM**: 22/504570/TK/55192
- **Course**: Pemrograman Dasar
- **Class** : A
