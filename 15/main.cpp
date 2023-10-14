#include <iostream>
#include <string>
#include <map>

using namespace std;


struct StudentGrade{
    string name;
    char grade;
};


class Grades{
private:
    map <string, StudentGrade> grades;
public:
    void addGrade(const string& name, char mark) {
        grades[name] = StudentGrade{name, mark};
    };

    StudentGrade* find_grade(const string& name){
        if (auto iter = grades.find(name);
                iter != grades.end()) {
            return &iter->second;
        } else {
            return nullptr;
        }
    }
};


int main() {
    Grades grades;
    grades.addGrade("Mark", 'A');

    StudentGrade* grade1 = grades.find_grade("Mark");
    cout << "Name is " << grade1->name << ", grade is " << grade1->grade;

    StudentGrade* grade2 = grades.find_grade("Ivan");
    cout << "Name is" << grade2->name << ", grade is" << grade2->grade;

    return 0;
}
