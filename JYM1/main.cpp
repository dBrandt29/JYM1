#include "roster.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Header
    cout << "C867-Scripting & Programming: Applications\n";
    cout << "Language: C++\n";
    cout << "Student ID: 011558617\n";  // actual ID
    cout << "Name: Dylan Brandt\n";   // actual name
    cout << endl;

    Roster classRoster;

    // Student data
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,32,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,52,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,22,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,52,SECURITY",
        "A5,Dylan,Brandt,dbra415@wgu.edu,27,53,30,55,SOFTWARE"
    };

    // Parse and add each student to the roster
    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    }

    // Display all students
    cout << "Displaying all students:\n";
    classRoster.printAll();

    // Invalid emails
    cout << "\nDisplaying invalid emails:\n";
    classRoster.printInvalidEmails();

    // Average days in course for each student
    cout << "\nDisplaying average days in course:\n";
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.getStudentID(i));
    }

    // Display students in the SOFTWARE degree program
    cout << "\nShowing students in degree program: SOFTWARE\n";
    classRoster.printByDegreeProgram(SOFTWARE);

    // remove student with ID "A3"
    cout << "\nRemoving A3:\n";
    classRoster.remove("A3");

    // print all students
    classRoster.printAll();

    // removing A3 again to trigger the error
    cout << "\nRemoving A3 again:\n";
    classRoster.remove("A3");

    cout << "\nDONE.\n";

    return 0;
}



