#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int score;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter Student Name: ";
    cin >> s.name;
    cout << "Enter Score (0-100): ";
    cin >> s.score;
    students.push_back(s);
    cout << "Student added successfully!\n";
}

void viewStudents() {
    cout << left << setw(15) << "Name" << setw(10) << "Score" << endl;
    for (const auto& s : students) {
        cout << left << setw(15) << s.name << setw(10) << s.score << endl;
    }
}

void bubbleSortByScore() {
    for (int i = 0; i < students.size() - 1; i++) {
        for (int j = 0; j < students.size() - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                swap(students[j], students[j + 1]);
            }
        }
    }
    cout << "Students sorted by score (Bubble Sort).\n";
}

void insertionSortByName() {
    for (int i = 1; i < students.size(); i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
    cout << "Students sorted by name (Insertion Sort).\n";
}

void binarySearchByName() {
    insertionSortByName();
    string name;
    cout << "Enter name to search: ";
    cin >> name;
    int l = 0, r = students.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (students[mid].name == name) {
            cout << "Student Found: " << students[mid].name << " - Score: " << students[mid].score << endl;
            return;
        } else if (students[mid].name < name) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << "Student not found.\n";
}

void showGradeDistribution() {
    int gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0, gradeF = 0;
    for (const auto& s : students) {
        if (s.score >= 90) gradeA++;
        else if (s.score >= 80) gradeB++;
        else if (s.score >= 70) gradeC++;
        else if (s.score >= 60) gradeD++;
        else gradeF++;
    }
    cout << "Grade Distribution:\n";
    cout << "A (90-100): " << gradeA << endl;
    cout << "B (80-89):  " << gradeB << endl;
    cout << "C (70-79):  " << gradeC << endl;
    cout << "D (60-69):  " << gradeD << endl;
    cout << "F (<60):    " << gradeF << endl;
}

void showTopBottom() {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }
    bubbleSortByScore();
    cout << "\nTop 3 Scorers:\n";
    for (int i = 0; i < min(3, (int)students.size()); i++) {
        cout << students[i].name << " - " << students[i].score << endl;
    }
    cout << "\nBottom 3 Scorers:\n";
    for (int i = students.size() - 1; i >= max(0, (int)students.size() - 3); i--) {
        cout << students[i].name << " - " << students[i].score << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Score Analyzer ---\n";
        cout << "1. Add Student\n2. View All Students\n3. Sort by Score\n4. Sort by Name\n5. Search by Name\n6. Grade Distribution\n7. Top & Bottom Scorers\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: bubbleSortByScore(); break;
            case 4: insertionSortByName(); break;
            case 5: binarySearchByName(); break;
            case 6: showGradeDistribution(); break;
            case 7: showTopBottom(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 8);
    return 0;
}