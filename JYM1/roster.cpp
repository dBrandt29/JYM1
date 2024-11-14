#include "roster.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Roster::parse(string row) {
    stringstream ss(row);
    string token;
    string studentData[9]; 
    int index = 0;

    // Split the row by commas and store each in studentData array
    while (getline(ss, token, ',') && index < 9) {
        studentData[index++] = token;
    }

    // Parsed data from studentData array and call add()
    string studentID = studentData[0];
    string firstName = studentData[1];
    string lastName = studentData[2];
    string emailAddress = studentData[3];
    int age = stoi(studentData[4]);
    int daysInCourse1 = stoi(studentData[5]);
    int daysInCourse2 = stoi(studentData[6]);
    int daysInCourse3 = stoi(studentData[7]);

    DegreeProgram degreeProgram;
    if (studentData[8] == "SECURITY") {
        degreeProgram = SECURITY;
    }
    else if (studentData[8] == "NETWORK") {
        degreeProgram = NETWORK;
    }
    else if (studentData[8] == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

// Add student to classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    lastIndex++;
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

// Print all students in the roster
void Roster::printAll() {
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

// Print invalid email addresses
void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; i++) {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos) {
            cout << "Invalid email: " << email << endl;
        }
    }
}

// Print average days in course for a given student ID
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse();
            int average = (days[0] + days[1] + days[2]) / 3;
            cout << "Student ID: " << studentID << ", Average days in course: " << average << endl;
            return;
        }
    }
}

// Print students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

// Remove student by ID and check if its true
void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex];
            lastIndex--;
            break;
        }
    }
    if (!found) {
        cout << "Error: Student with ID " << studentID << " not found." << endl;
    }
}

// Destructor to release allocated memory
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

// New public method to get studentID by index
string Roster::getStudentID(int index) {
    if (index >= 0 && index <= lastIndex) {
        return classRosterArray[index]->getStudentID();
    }
    return "";  // Return empty if index is invalid
}

