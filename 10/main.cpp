#include <iostream>
#include "triangle.h"

using namespace std;


int main() {
    // Композиция классов
    Triangle t = Triangle(Dot(), Dot(6.3, 4.38), Dot(4.72, 0.24));

    t.show_sides();
    cout << "Периметр треугольника равен: " << t.perimetr() << endl;
    cout << "Площадь треугольника равна: " << t.square() << endl;

    // Агрегация классов
    Dot d = Dot();
    Dot d2 = Dot(23, 78);
    cout << "Расстояние между двумя точками равно " << d.distanceTo(d2) << endl;

    Triangle t2 = Triangle(d, d2, Dot(-7, 9));
    t2.show_sides();
    cout << "Периметр треугольника равен: " << t2.perimetr() << endl;
    cout << "Площадь треугольника равна: " << t2.square() << endl;
    return 0;
}
