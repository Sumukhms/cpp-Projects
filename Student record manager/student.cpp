#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    int id;
    string name;
    float cgpa;

    Student() {}

    Student(int id, string name, float cgpa) {
        this->id = id;
        this->name = name;
        this->cgpa = cgpa;
    }

    void display() const {
        cout << "ID: " << id 
             << " | Name: " << name 
             << " | CGPA: " << cgpa << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;
    string filename = "students.txt";

    bool idExists(int id) {
        for (auto &s : students)
            if (s.id == id) return true;
        return false;
    }

    int safeIntInput(string msg) {
        int x;
        while (true) {
            cout << msg;
            if (cin >> x) return x;
            cout << " Invalid number! Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    float safeFloatInput(string msg) {
        float x;
        while (true) {
            cout << msg;
            if (cin >> x && x >= 0 && x <= 10) return x;
            cout << " Enter valid CGPA (0–10).\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

public:
    StudentManager() {
        loadFromFile();
    }

    void addStudent() {
        cout << "\n--- Add Student ---\n";

        int id;
        while (true) {
            id = safeIntInput("Enter ID: ");
            if (!idExists(id)) break;
            cout << " ID already exists! Enter a unique ID.\n";
        }

        cin.ignore();
        string name;
        cout << "Enter Name: ";
        getline(cin, name);

        float cgpa = safeFloatInput("Enter CGPA (0–10): ");

        students.push_back(Student(id, name, cgpa));
        saveToFile();
        cout << " Student added successfully!\n";
    }

    void displayAll() {
        if (students.empty()) {
            cout << "\n⚠ No records available.\n";
            return;
        }
        cout << "\n--- All Students ---\n";
        for (auto &s : students) s.display();
    }

    void searchStudent() {
        int id = safeIntInput("\nEnter ID to search: ");
        for (auto &s : students) {
            if (s.id == id) {
                cout << "\n Student Found:\n";
                s.display();
                return;
            }
        }
        cout << " Student not found!\n";
    }

    void deleteStudent() {
        int id = safeIntInput("\nEnter ID to delete: ");
        auto it = remove_if(students.begin(), students.end(),
                            [id](Student &s) { return s.id == id; });

        if (it != students.end()) {
            students.erase(it, students.end());
            saveToFile();
            cout << "Student deleted successfully!\n";
        } else {
            cout << "Student not found!\n";
        }
    }

    void saveToFile() {
        ofstream fout(filename);
        for (auto &s : students)
            fout << s.id << "," << s.name << "," << s.cgpa << "\n";
    }

    void loadFromFile() {
        ifstream fin(filename);
        students.clear();
        string line;

        while (getline(fin, line)) {
            if (line.empty()) continue;

            stringstream ss(line);
            string idStr, name, cgpaStr;

            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, cgpaStr, ',');

            try {
                int id = stoi(idStr);
                float cg = stof(cgpaStr);
                students.push_back(Student(id, name, cg));
            } catch (...) {
                // corrupted line → skip
                continue;
            }
        }
    }
};

int main() {
    StudentManager sm;
    int choice;

    while (true) {
        cout << "\n===== Student Record Manager =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (!cin) {
            cout << "Invalid input! Numbers only.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: sm.addStudent(); break;
            case 2: sm.displayAll(); break;
            case 3: sm.searchStudent(); break;
            case 4: sm.deleteStudent(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << " Invalid choice! Try again.\n";
        }
    }
}
