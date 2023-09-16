/* t_ime.h */
#pragma once /* Защита от двойного подключения заголовочного файла */
#include <iostream>
#include <string>

using namespace std;


class TimeException{
public:
    TimeException(): message ("Неправильное использование класса") { }
    void printMessage ()    const {cout << message << endl;}
private: string message;
};


class Time
{
public:
    Time();

    Time(int, int, int);

    // Установка секунд
    void set_seconds(int);

    // Получение секунд
    int const get_seconds();

    // Установка минут
    void set_minutes(int);

    // Получение минут
    int const get_minutes();

    // Установка часов
    void set_hours(int);

    // Получение часов
    int const get_hours();

    // Вывод времени
    void const show_time();

    // Сложение двух объектов класса
    Time add_time(Time, Time);

private:
    int seconds;
    int hours;
    int minutes;
};
