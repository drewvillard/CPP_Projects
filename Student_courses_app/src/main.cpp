#include <iostream>
#include <string>
#include <vector>
#include "../Student.h"
//author Drew Villard w0468787
using namespace std;
//main method drives created student class first creates one object then fills with inputed info from there
//demonstrated knowledge or implementation of copy constructor, operator overload, and destructor.
int main() {
    bool progLoop=true;

    while(progLoop) {
        string studentName;
        std::string*  courses;
        Student student1;
        // Ask for student's name
        cout << "Enter student name: ";
        getline(cin, studentName);
        student1.setName(studentName);

        // Ask for student's courses
        while (true) {
            string course;
            cout << "Enter a course (or 'Q' to finish): ";
            getline(cin, course);

            if (course == "Q"||course=="q") {
                break;
            } else if (course.empty()) {
                cout << "Invalid input. Please enter a course or 'Q'." << endl;
                continue;
            } else {
                student1.addCourse(course);
            }
        }

        // Print out student's name and courses
        cout << "Student name: " << student1.getName() << endl;
        cout << "Number of courses: " << student1.getNumCourses() << endl;
        cout << "Courses: ";
        const string *courseList = student1.getCourseList();
        for (int i = 0; i < student1.getNumCourses(); i++) {
            cout << courseList[i] << " ";
        }
        cout << endl;


// Create a new student object using the copy constructor
        Student student2(student1);
// ask for students name
        string name2;
        cout << "Enter the name of the second student: ";
        getline(cin, name2);
        //set new name
        student2.setName(name2);

// Print out the name and course list of the new student object
        cout << "Student name: " << student2.getName() << endl;
        cout << "Number of courses: " << student2.getNumCourses() << endl;
        cout << "Course list: ";
        courseList = student2.getCourseList();
        for (int i = 0; i < student2.getNumCourses(); i++) {
            cout << courseList[i] << " ";
        }
        cout << endl;

        //call reset function on student 1
        student1.resetCourses();
        cout<<endl;
        cout<<"RESET STUDENT 1"<<endl;
        //print out student 1 information
        cout << "Student name: " << student1.getName() << endl;
        cout << "Number of courses: " << student1.getNumCourses() << endl;
        cout << "Courses:";
        courseList = student1.getCourseList();
        for (int i = 0; i < student1.getNumCourses(); i++) {
            cout << courseList[i] << " ";
        }
        cout << endl;

        //print out student2 information to show that a deep copy took place
        cout<<"\nDEEP COPY PROOF"<<endl;
        cout << "Student name: " << student2.getName() << endl;
        cout << "Number of courses: " << student2.getNumCourses() << endl;
        cout << "Course list: ";
        courseList = student2.getCourseList();
        for (int i = 0; i < student2.getNumCourses(); i++) {
            cout << courseList[i] << " ";
        }
        cout <<"\n"<< endl;

// Use the overloaded assignment operator to create a new student object
        Student student3;
        student3 = student2;

// Print out the name and course list of the new student object
        cout << "\nStudent name: " << student3.getName() << endl;
        cout << "Number of courses: " << student3.getNumCourses() << endl;
        cout << "Course list: ";
        courseList = student3.getCourseList();
        for (int i = 0; i < student3.getNumCourses(); i++) {
            cout << courseList[i] << " ";
        }
        string loopChoice;
        cout <<"\n\nContinue loop? [Y/N]" <<endl;
        getline(cin, loopChoice);
        if(loopChoice=="Y"||loopChoice=="y"){
            continue;
        }else{
            progLoop= false;
        }
    }
    return 0;
}
