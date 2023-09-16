#include <iostream>
#include <cmath>

using namespace std;


class NonExistentTriangle{  // Класс исключения для несуществующего треугольника
public:
    NonExistentTriangle(): message ("Одна сторона больше двух других") { }
    void printMessage ()    const {cout << message << endl;}
private: string message;
};


class Triangle{  // Класс треугольника
public:
    Triangle(double x, double y, double z) {  // Конструктор
        set_sides(x, y, z);
    };

    void set_sides(double x, double y, double z){  // Функция чтобы задать стороны
        if ((x > (y + z)) || (y > (x + z)) || (z > (x + y))){
            throw NonExistentTriangle();
        }
        a = x;
        b = y;
        c = z;
    };

    double square(){  // Функция для расчёта площади
        double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        return s;
    }

private:  // Переменные-стороны
    double a;
    double b;
    double c;
};


int main(){
    Triangle t = Triangle(5, 3, 4);  // Вариант с обычным треугольником
    cout << "Площадь треугольника равна: " << t.square() << endl;

    try {  // Вариант где мы ловим ошибку
        Triangle t3 = Triangle(21, 6, 7);
        cout << "Площадь треугольника равна: " << t3.square() << endl;
    }
    catch (NonExistentTriangle& error){
        cout << "ОШИБКА: ";
        error.printMessage();
    }

    Triangle t2 = Triangle(1, 2, 6);  // Вариант где мы не ловим ошибку
    cout << "Площадь треугольника равна: " << t2.square() << endl;
}
