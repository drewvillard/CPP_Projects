#include "../Student.h"
#include <iostream>
#include <cstring>
//author Drew Villard w0468787
// Default constructor
Student::Student() {
    name = "";
    courseList = nullptr;
    numCourses = 0;
}

// Constructors
// Copy constructor
Student::Student(const Student &other) {
    std::cout << "\n*****Copy constructor called****" << std::endl;
    // Copy the name
    name = other.name;

    // Copy the number of courses
    numCourses = other.numCourses;

    // Allocate memory for the new course list
    if (numCourses > 0) {
        courseList = new std::string[numCourses];

        // Copy each course from the other object
        for (int i = 0; i < numCourses; i++) {
            courseList[i] = other.courseList[i];
        }
    } else {
        courseList = nullptr;
    }
}

// Overloaded assignment operator
Student &Student::operator=(const Student &other) {
    std::cout << "***Overloaded assignment operator called***" << std::endl;
    if (this != &other) {
        setName(other.name);
        numCourses = other.numCourses;
        delete[] courseList;
        courseList = nullptr;
        if (numCourses > 0) {
            courseList = new std::string[numCourses];
            for (int i = 0; i < numCourses; i++) {
                courseList[i] = other.courseList[i];
            }
        }
    }
    return *this;
}

// Destructor
Student::~Student() {
    std::cout << "***Destructor called***" << std::endl;
    name.clear();
    if (courseList != nullptr) {
        delete[] courseList;
        courseList = nullptr;
    }
}

// Mutator methods
void Student::setName(const std::string &name) {
    this->name = name;
}

void Student::addCourse(const std::string &course) {
    // If the list is empty, create a new dynamic array with 1 element
    if (numCourses == 0) {
        courseList = new std::string[1];
        courseList[0] = course;
        numCourses++;
    }
        // If the list is not empty, create a new dynamic array with 1 more element
    else {
        std::string *temp = new std::string[numCourses + 1];
        // Copy the old list to the new list
        for (int i = 0; i < numCourses; i++) {
            temp[i] = courseList[i];
        }
        // Add the new course to the end of the new list
        temp[numCourses] = course;
        numCourses++;
        // Delete the old list and update courseList to point to the new list
        delete[] courseList;
        courseList = temp;
    }
}

// Accessor methods
const std::string &Student::getName() const {
    return name;
}

int Student::getNumCourses() const {
    return numCourses;
}

const std::string *Student::getCourseList() const {
    return courseList;
}

// Other methods
void Student::resetCourses() {
    delete[]courseList;
    numCourses = 0;
    courseList = nullptr;
}
