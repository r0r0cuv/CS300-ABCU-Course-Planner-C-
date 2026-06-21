//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Rosalie Reblora
// Description : CS 300 Project Two - ABCU Course Planner
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold course information
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Structure for each node in the binary search tree
struct Node {
    Course course;
    Node* left;
    Node* right;

    Node(Course aCourse) {
        course = aCourse;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Search Tree class
class BinarySearchTree {
private:
    Node* root;

    void addNode(Node* node, Course course) {
        if (course.courseNumber < node->course.courseNumber) {
            if (node->left == nullptr) {
                node->left = new Node(course);
            }
            else {
                addNode(node->left, course);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new Node(course);
            }
            else {
                addNode(node->right, course);
            }
        }
    }

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->course.courseNumber << ", " << node->course.courseTitle << endl;
            inOrder(node->right);
        }
    }

    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    ~BinarySearchTree() {
        clear();
    }

    void clear() {
        deleteTree(root);
        root = nullptr;
    }

    void Insert(Course course) {
        if (root == nullptr) {
            root = new Node(course);
        }
        else {
            addNode(root, course);
        }
    }

    void InOrder() {
        inOrder(root);
    }

    Course Search(string courseNumber) {
        Node* current = root;

        while (current != nullptr) {
            if (current->course.courseNumber == courseNumber) {
                return current->course;
            }
            else if (courseNumber < current->course.courseNumber) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        Course course;
        return course;
    }
};

// Convert user input to uppercase
string toUpperCase(string input) {
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    return input;
}

// Remove extra spaces from beginning and end of text
string trim(string text) {
    size_t start = text.find_first_not_of(" \t\r\n");
    size_t end = text.find_last_not_of(" \t\r\n");

    if (start == string::npos) {
        return "";
    }

    return text.substr(start, end - start + 1);
}

// Split one CSV line by comma
vector<string> splitLine(string line) {
    vector<string> tokens;
    string token;
    stringstream ss(line);

    while (getline(ss, token, ',')) {
        tokens.push_back(trim(token));
    }

    return tokens;
}

// Load course data from file into the binary search tree
bool loadCourses(string fileName, BinarySearchTree* courseTree) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return false;
    }

    courseTree->clear();

    string line;

    while (getline(file, line)) {
        if (trim(line).empty()) {
            continue;
        }

        vector<string> tokens = splitLine(line);

        if (tokens.size() < 2) {
            cout << "Error: Invalid course data format." << endl;
            continue;
        }

        Course course;
        course.courseNumber = toUpperCase(tokens[0]);
        course.courseTitle = tokens[1];

        for (unsigned int i = 2; i < tokens.size(); i++) {
            if (!tokens[i].empty()) {
                course.prerequisites.push_back(toUpperCase(tokens[i]));
            }
        }

        courseTree->Insert(course);
    }

    file.close();
    cout << "Course data loaded successfully." << endl;
    return true;
}

// Display one course and its prerequisites
void displayCourse(Course course) {
    if (course.courseNumber.empty()) {
        cout << "Course not found." << endl;
        return;
    }

    cout << course.courseNumber << ", " << course.courseTitle << endl;

    if (course.prerequisites.empty()) {
        cout << "Prerequisites: None" << endl;
    }
    else {
        cout << "Prerequisites: ";

        for (unsigned int i = 0; i < course.prerequisites.size(); i++) {
            cout << course.prerequisites[i];

            if (i < course.prerequisites.size() - 1) {
                cout << ", ";
            }
        }

        cout << endl;
    }
}

// Main program
int main() {
    BinarySearchTree* courseTree = new BinarySearchTree();

    string fileName;
    string courseNumber;
    int choice = 0;
    bool isLoaded = false;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {
        cout << endl;
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "What would you like to do? ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter the file name: ";
            cin.ignore();
            getline(cin, fileName);
            isLoaded = loadCourses(fileName, courseTree);
            break;

        case 2:
            if (!isLoaded) {
                cout << "Please load the course data first." << endl;
            }
            else {
                cout << "Here is a sample schedule:" << endl;
                courseTree->InOrder();
            }
            break;

        case 3:
            if (!isLoaded) {
                cout << "Please load the course data first." << endl;
            }
            else {
                cout << "What course do you want to know about? ";
                cin >> courseNumber;
                courseNumber = toUpperCase(courseNumber);
                displayCourse(courseTree->Search(courseNumber));
            }
            break;

        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;

        default:
            cout << choice << " is not a valid option." << endl;
            break;
        }
    }

    delete courseTree;
    return 0;
}