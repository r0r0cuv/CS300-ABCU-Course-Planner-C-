# CS300-ABCU-Course-Planner-C-
C++ academic course planner using a Binary Search Tree to efficiently load, search, and display course information and prerequisites.


# ABCU Course Planner

## Overview

The ABCU Course Planner is a C++ command-line application developed for Southern New Hampshire University's CS-300 Data Structures and Algorithms course.

The application assists academic advisors by loading course information from a file, organizing the data using a Binary Search Tree (BST), and providing efficient search and sorting capabilities.

This project demonstrates the practical application of data structures and algorithms to solve a real-world academic advising problem.

---

## Features

- Load course data from a CSV file
- Store course information in a Binary Search Tree
- Display all courses in alphanumeric order
- Search for individual courses
- Display course titles and prerequisites
- Error handling for invalid menu selections
- File validation and input checking

---

## Technologies Used

- C++
- Visual Studio 2022
- Binary Search Tree (BST)
- File I/O
- Object-Oriented Programming

---

## Data Structure Selection

A Binary Search Tree was selected because it provides:

### Efficient Searching

Average search time:

```text
O(log n)
```

### Natural Sorting

An in-order traversal automatically displays courses in alphanumeric order.

### Scalability

The BST can efficiently handle larger datasets compared to a simple vector-based approach.

---

## Program Menu

```text
1. Load Data Structure
2. Print Course List
3. Print Course
9. Exit
```

---

## Sample Output

```text
Welcome to the course planner.

1. Load Data Structure.
2. Print Course List.
3. Print Course.
9. Exit

What would you like to do? 2

Here is a sample schedule:

CSCI100, Introduction to Computer Science
CSCI101, Introduction to Programming in C++
CSCI200, Data Structures
CSCI300, Introduction to Algorithms
CSCI301, Advanced Programming in C++
CSCI350, Operating Systems
CSCI400, Large Software Development
MATH201, Discrete Mathematics
```

---

## Course Search Example

```text
What course do you want to know about?

CSCI400

CSCI400, Large Software Development

Prerequisites:
CSCI301, CSCI350
```

---

## Learning Outcomes

Through this project I gained experience with:

- Binary Search Trees
- Recursion
- Tree Traversal
- Searching Algorithms
- File Parsing
- Software Design
- Error Handling
- Algorithm Runtime Analysis

---

## Author

Rosalie Reblora

Bachelor of Science in Computer Science  
Southern New Hampshire University

Expected Graduation: 2027

GitHub:
https://github.com/r0r0cuv
