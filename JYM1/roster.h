#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <string>

class Roster {
private:
    int lastIndex = -1;  // Keeps track of the last index of classRosterArray
    const static int numStudents = 5;  // Fixed number of students
    Student* classRosterArray[numStudents];  // Array of pointers to Student objects

public:
    // Constructor and destructor
    Roster() = default;
    ~Roster();

    // Parse data and add student
    void parse(string row);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    string getStudentID(int index);
};

#endif
