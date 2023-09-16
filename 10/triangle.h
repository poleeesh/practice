#include "dot.h"


class Triangle{
private:  // Приватные переменные - точки треугольника
    Dot a;
    Dot b;
    Dot c;
public:
    Triangle(Dot a, Dot b, Dot c);  // Конструктор
    void show_sides();  // Функция, показывающая длины сторон треугольника
    double perimetr();  // Функция возвращает периметр
    double square();  // Функция возвращает площадь
};
