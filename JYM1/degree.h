#ifndef DEGREE_H
#define DEGREE_H

// Enum to define the degree programs
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

static const char* degreeProgramToString(DegreeProgram degreeProgram) {
    switch (degreeProgram) {
    case SECURITY:
        return "SECURITY";
    case NETWORK:
        return "NETWORK";
    case SOFTWARE:
        return "SOFTWARE";
    default:
        return "UNKNOWN";
    }
}

#endif
#pragma once

