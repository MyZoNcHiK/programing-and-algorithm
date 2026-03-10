#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Course {
    int courseId;
    string courseName;
    int credits;

    void init(int id, const string& name, int cr) {
        courseId = id;
        courseName = name;
        credits = cr;
    }

    void print() const {
        cout << "Course ID: " << courseId << '\n'
             << "Course Name: " << courseName << '\n'
             << "Credits: " << credits << '\n';
    }
};

bool parseLine(const string& line, int& id, string& name, int& cr) {
    size_t p1 = line.find(';');
    size_t p2 = line.find(';', p1 + 1);
    if (p1 == string::npos || p2 == string::npos) return false;

    id = stoi(line.substr(0, p1));
    name = line.substr(p1 + 1, p2 - p1 - 1);
    cr = stoi(line.substr(p2 + 1));
    return true;
}

int loadCourses(const string& filename, Course*& courses) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Помилка: не вдалося відкрити файл.\n";
        return 0;
    }

    int n;
    fin >> n;
    fin.ignore(1, '\n');

    courses = new Course[n];
    for (int i = 0; i < n; ++i) {
        string line;
        getline(fin, line);
        int id, cr;
        string name;
        if (parseLine(line, id, name, cr)) {
            courses[i].init(id, name, cr);
        } else {
            cerr << "Помилка формату в рядку #" << i + 1 << '\n';
            courses[i].init(0, "", 0);
        }
    }
    return n;
}

Course* findCourseById(Course* courses, int n, int id) {
    for (int i = 0; i < n; ++i) {
        if (courses[i].courseId == id) return &courses[i];
    }
    return nullptr;
}

int main() {
    Course* courses = nullptr;
    int n = loadCourses("courses.txt", courses);
    if (n == 0) return 1;

    cout << "Введіть Course ID для пошуку: ";
    int targetId;
    cin >> targetId;

    const Course* found = findCourseById(courses, n, targetId);
    if (found) {
        cout << "\n=== Знайдено курс ===\n";
        found->print();
    } else {
        cout << "Курс з ID " << targetId << " не знайдено.\n";
    }

    delete[] courses;
    return 0;
}

