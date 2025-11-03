#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// studentType struct
struct studentType {
    string studentFName;
    string studentLName;
    int testScore{};
    char grade{};
};

// Function prototypes
void readStudentData(studentType students[], int size);
void assignGrades(studentType students[], int size);
int findHighestScore(const studentType students[], int size);
void printHighestScorers(const studentType students[], int size, int highestScore);
void printStudentData(const studentType students[], int size);

int main() {
    constexpr int NUM_STUDENTS = 20;
    studentType students[NUM_STUDENTS];

    readStudentData(students, NUM_STUDENTS);
    assignGrades(students, NUM_STUDENTS);
    printStudentData(students, NUM_STUDENTS);

    const int highestScore = findHighestScore(students, NUM_STUDENTS);
    cout << "\nHighest Test Score: " << highestScore << endl;
    cout << "\nStudents having the highest test score:" << endl;
    printHighestScorers(students, NUM_STUDENTS, highestScore);

    return 0;
}

// Function to read students' data into the array
void readStudentData(studentType students[], int size) {
    cout << "Enter data for " << size << " students:" << endl;
    cout << "Format: FirstName LastName TestScore" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        cout << "Student " << (i + 1) << ": ";
        cin >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;

        // Check if input failed
        while (cin.fail() || students[i].testScore < 0 || students[i].testScore > 100) {
            cin.clear();                    // Clear error flags
            cin.ignore(10000, '\n');        // Discard invalid input
            cout << "Invalid input! Please enter: FirstName LastName TestScore (0-100): ";
            cin >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;
        }
    }
}

// Function to assign the relevant grade to each student
void assignGrades(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore >= 90) {
            students[i].grade = 'A';
        } else if (students[i].testScore >= 80) {
            students[i].grade = 'B';
        } else if (students[i].testScore >= 70) {
            students[i].grade = 'C';
        } else if (students[i].testScore >= 60) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }
}

// Function to find the highest test score
int findHighestScore(const studentType students[], int size) {
    int highest = students[0].testScore;

    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest) {
            highest = students[i].testScore;
        }
    }

    return highest;
}

// Function to print the names of students having the highest test score
void printHighestScorers(const studentType students[], int size, int highestScore) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << left << setw(25) << (students[i].studentLName + ", " + students[i].studentFName) << endl;
        }
    }
}

// Function to print each student's name, test score, and grade
void printStudentData(const studentType students[], int size) {
    cout << "\n" << string(60, '=') << endl;
    cout << "STUDENT GRADE REPORT" << endl;
    cout << string(60, '=') << endl;
    cout << left << setw(25) << "Student Name" << setw(15) << "Test Score" << setw(10) << "Grade" << endl;
    cout << string(60, '-') << endl;

    for (int i = 0; i < size; i++) {
        string fullName = students[i].studentLName + ", " + students[i].studentFName;
        cout << left << setw(25) << fullName
             << setw(15) << students[i].testScore
             << setw(10) << students[i].grade << endl;
    }

    cout << string(60, '=') << endl;
}
