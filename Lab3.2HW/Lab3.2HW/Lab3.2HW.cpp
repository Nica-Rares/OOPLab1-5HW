//This file has been created as a merger of 3.2 and 3.3 for easy access.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int grade;
};

class StudentManager {
private:
    vector<Student> students;

public:
    // Constructor
    StudentManager() {}

    // Add a student
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Find students with the highest grade
    vector<Student> findHighestGradeStudents() const {
        if (students.empty()) {
            return {};
        }

        // Find the maximum grade using lambda
        auto maxGrade = max_element(students.begin(), students.end(),
            [](const Student& s1, const Student& s2) { return s1.grade < s2.grade; });

        // Find all students with the maximum grade using lambda
        vector<Student> highestGradeStudents;
        for_each(students.begin(), students.end(),
            [&highestGradeStudents, maxGrade](const Student& student) {
                if (student.grade == maxGrade->grade) {
                    highestGradeStudents.push_back(student);
                }
            });

        return highestGradeStudents;
    }

    // Search for a student by name
    Student* searchStudentByName(const string& name) {
        // Use lambda to search for the student
        auto it = find_if(students.begin(), students.end(),
            [&name](const Student& student) { return student.name == name; });

        // If found, return a pointer to the student
        if (it != students.end()) {
            return &(*it);
        }
        else {
            return nullptr;
        }
    }
};

int main() {
    StudentManager studentManager;

    // Add some students
    studentManager.addStudent({ "Alice", 90 });
    studentManager.addStudent({ "Bob", 85 });
    studentManager.addStudent({ "Charlie", 90 });
    studentManager.addStudent({ "David", 80 });
    studentManager.addStudent({ "Eve", 90 });

    // Find students with the highest grade
    vector<Student> highestGradeStudents = studentManager.findHighestGradeStudents();
    cout << "Students with the highest grade:" << endl;
    for (const auto& student : highestGradeStudents) {
        cout << "Name: " << student.name << ", Grade: " << student.grade << endl;
    }

    // Search for a student
    string searchName = "Charlie";
    Student* foundStudent = studentManager.searchStudentByName(searchName);
    if (foundStudent) {
        cout << "Found student: " << foundStudent->name << ", Grade: " << foundStudent->grade << endl;
    }
    else {
        cout << "Student not found." << endl;
    }

    return 0;
}
