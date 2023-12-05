//
// Created by drew on 2023-03-08.
//
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class Student {
public:
    // Constructors
    Student();  // default constructor
    Student(const Student& other);  // copy constructor
    Student& operator=(const Student& other);  // overloaded assignment operator
    ~Student();  // destructor

    // Mutator functions
    void setName(const std::string& name);
    void addCourse(const std::string& course);

    // Accessor functions
    const std::string& getName() const;
    int getNumCourses() const;
    const std::string* getCourseList() const    ;

    // Other
    void resetCourses();

private:
    std::string name;
    int numCourses;
    std::string* courseList;
};

#endif  // STUDENT_H

