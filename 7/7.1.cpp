#include <iostream>


struct Time  // Создаём структуру времени
{
    int hours;
    int minutes;
    int seconds;
};

int showSeconds(const Time &t) {  // Создаём функцию которая показывает всё время в секундах
    int sec = t.seconds;
    sec = sec + t.minutes * 60;
    sec = sec + t.hours * 3600;
    return sec;
}

Time addTime(const Time &t1, const Time &t2) {  // Функция для сложения 2х структур
    Time t3;  // Создаём структуру которую вернём в функции

    int sec = t1.seconds + t2.seconds;
    int mins = t1.minutes + t2.minutes;
    t3.seconds = sec % 60;
    t3.minutes = (sec / 60) + (mins % 60);
    t3.hours = t1.hours + t2.hours + (mins / 60);

    return t3;
}

Time substractTime(const Time &t1, const Time &t2) {  // Аналогичная функция для вычитания двух структур
    int sec1 = showSeconds(t1);
    int sec2 = showSeconds(t2);

    int sec3 = sec1 - sec2;
    Time t3;
    t3.hours = sec3 / 3600;
    t3.minutes = (sec3 % 3600) / 60;
    t3.seconds = (sec3 % 3600) % 60;
    return t3;
}

int main() {
    Time t0;  // Создаём структуру, которую будет задавать пользователь

    std::cout << "Введите часы, минуты и секунды: " << std::endl;
    std::cin >> t0.hours;
    std::cin >> t0.minutes;
    std::cin >> t0.seconds;

    std::cout << "Ваше время в секундах равно: " << showSeconds(t0) << std::endl;

    Time t1;
    t1.hours = 200;
    t1.minutes = 200;
    t1.seconds = 200;

    Time t3 = addTime(t0, t1);
    Time t4 = substractTime(t1, t0);
    std::cout << "Сложение структур равно: " << t3.hours << " часов, " << t3.minutes << " минут, " << t3.seconds << " секунд" << std::endl;

    std::cout << "Вычитание структур равно: " << t4.hours << " часов, " << t4.minutes << " минут, " << t4.seconds << " секунд" << std::endl;

    return 0;
}
