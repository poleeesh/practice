#include <iostream>
#include "student.h"
#include "teacher.h"

int main() {
    unsigned int teacher_work_time = 40;
    teacher *tch = new teacher("Сергеев", "Дмитрий", "Сергеевич",
                               teacher_work_time);

    std::vector<int> scores;
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(4);
    scores.push_back(4);
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);

    student *stud = new student("Петров", "Иван", "Алексеевич", scores);

    tch->print_info();
    std::cout << std::endl;
    stud -> print_info();

    return 0;
}
