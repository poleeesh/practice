#include <iostream>
#include <cmath>

double square(double a){  // Функция, вычисляющая площадь равностороннего треугольника
    double s = sqrt(3)/ 4 * pow(a, 2);
    return s;
}

double square(double a, double b, double c){  // Перегруженная функция, вычисляющая площадь разностороннего треугольника
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    return s;
}

int main(){
    int x;
    double a, b, c;
    // Просим пользователя выбрать тип треугольника
    std::cout << "Если вам нужна площадь равностороннего треугольника, введите 1, разностороннего - 2: ";
    std::cin >> x;

    if (x == 1){  // В зависимости от его выбора выводим результат соответствующей функции
        std::cout << "Введите сторону треугольника: ";
        std::cin >> a;
        std::cout << "Площадь треугольника равна: " << square(a);
        return 0;
    }
    else if (x == 2){
        std::cout << "Введите стороны треугольника: ";
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
        std::cout << "Площадь треугольника равна: " << square(a, b, c);
        return 0;
    }
    else {
        std::cout << "Вы ввели что-то не то";
        return 0;
    }
}
