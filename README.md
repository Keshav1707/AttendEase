# Attendance Management System

## Overview

The Attendance Management System is a C++ application designed to track student attendance in various subjects. It allows users to add students, assign subjects to students, mark attendance, and retrieve attendance records. The system uses object-oriented programming (OOP) principles, including inheritance, polymorphism, abstraction, and encapsulation.

## Features

- **Add a New Student**: Create a new student with a unique ID and name.
- **Add a Subject to a Student**: Assign subjects to a student for attendance tracking.
- **Mark Attendance**: Record attendance for a student in a specific subject.
- **Get Attendance**: Retrieve the number of times a student has attended a specific subject.
- **Display All Students**: Show details and attendance records for all students.

## Classes

- **Entity**: Abstract base class representing an entity with an ID and a name.
- **AttendanceEntity**: Abstract class derived from `Entity`, used for entities that track attendance.
- **Subject**: Derived from `AttendanceEntity`, represents a subject with attendance tracking.
- **Student**: Derived from `Entity`, represents a student with subjects and attendance tracking.
- **AttendanceManager**: Manages student and subject records, and provides methods to manipulate and retrieve attendance data.


