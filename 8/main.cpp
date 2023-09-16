#include <iostream>
#include "t_ime.h"

using namespace std;

int main() {
    const Time t1(23, 53, 34);
    const Time t2(28, 40, 12);

    Time t3;
    t3 = t3.add_time(t1, t2);

    t3.show_time();

    try {
        Time t4(2, 78, 4);
        t4.show_time();
    }
    catch (TimeException& error){
        cout << "ОШИБКА: ";
        error.printMessage();
    }

    Time t5;

    try{
        Time t6;
        t6 = t6.add_time(t1, t5);
        t6.show_time();
    }
    catch (TimeException& error){
        cout << "ОШИБКА: ";
        error.printMessage();
    }
    return 0;
}
