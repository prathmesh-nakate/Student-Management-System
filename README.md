# Student Management System
A simple C++ project to manage student records with automatic percentage calculation and grading.

## Overview
Manage student records efficiently with this lightweight CLI tool. All student data is automatically saved to a text file and persists between sessions.

## 📋 Features
- **View All Students** - Display complete student list with grades in formatted table
- **Add Student** - Register new students with manual roll number entry
- **Search Student** - Find student details by ID number
- **Update Student** - Modify existing student information and marks
- **Delete Student** - Remove student records with confirmation prompt
- **Auto-Grading** - Automatic grade calculation (A-F) based on percentage
- **Auto-Save** - All changes automatically saved to file

## Installation
```bash
# Clone the repository
git clone https://github.com/prathmesh-nakate/Student-Management-System
cd Student-Management-System

# Compile
g++ main.cpp -o student_mgmt

# Run
./student_mgmt        # Linux/Mac
student_mgmt.exe      # Windows
```

## Usage Example
```
============================================================
              Student Management System
============================================================

------ Menu ------
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit

Enter Your Choice : 1

==== Add New Student ====
Enter Student ID (Roll Number) : 13
Enter Name : Prathmesh Umesh Nakate
Enter Age : 18
Enter Marks for Subject 1 (out of 100) : 92
Enter Marks for Subject 2 (out of 100) : 96
Enter Marks for Subject 3 (out of 100) : 94

Student Added Successfully !
Percentage : 94.00 %
Grade : A

Enter Your Choice : 2

===============================================================================
                            All Students
===============================================================================
ID    Name                    Age   Sub1    Sub2    Sub3    Percent   Grade
===============================================================================
13    Prathmesh Umesh Nakate  18    92      96      94      94.00 %   A
111   Pranav R Nakate         19    95      89      92      92.00 %   A
===============================================================================
```

## How It Works
- Students are stored in `students.txt`
- Format per student:
  ```
  ID
  Name
  Age
  Subject1 Subject2 Subject3
  ```
- Users enter their own student ID/roll number
- Percentage calculated automatically: (Total Marks / 300) × 100
- Grades assigned automatically: A (90+), B (80-89), C (70-79), D (60-69), F (<60)
- All changes are automatically saved

## Project Structure
```
.
├── main.cpp          # Source code
├── README.md         # Documentation
├── .gitignore        # Git ignore rules
└── students.txt      # Student data storage (auto-generated)
```

## Technologies
- **Language:** C++
- **Libraries:** Standard Library (iostream, fstream, vector, string, iomanip)
- **Storage:** Text file
- **Grading System:** Automatic A-F calculation based on percentage

## What I Learned
- File I/O operations in C++
- Vector manipulation with structs
- Menu-driven program design
- Manual ID entry with duplicate validation
- Built-in methods in structs (getPercentage, getGrade)
- Data formatting with iomanip
- Percentage calculation from multiple subjects

## Contributing
Pull requests are welcome! For major changes, please open an issue first.

## Author
**Prathmesh Umesh Nakate**
- GitHub: [@prathmesh-nakate](https://github.com/prathmesh-nakate)
- Email: prathmeshnakate24@gmail.com

---
⭐ Star this repo if you found it helpful!