#include <iostream>
#include <cmath>

double cube_root1(double a){  // Первая функция использующая библиотечную функцию
    return pow(a, 1.0/3);
}

double cube_root2(double a){  // Вторая функция использующая итерационную формулу
    double x1;
    double x = a;
    do {
        x1 = x;
        x = 1.0 / 3 * (a / x / x + 2 * x);
    } while (abs(x1 - x) > 1.0/10000);
    return x;
}

int main(){
    double a;
    std::cout << "Введите число: ";
    std::cin >> a;

    std::cout << "Кубический корень числа согласно двум функциям: " << std::endl;
    std::cout << cube_root1(a) << " " << cube_root2(a);
}
