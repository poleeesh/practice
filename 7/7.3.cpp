#include <iostream>
#include <cmath>
#include <tuple>

using Tuple = std::tuple<int, double, double>;  // Объявляем типы переменных в кортеже


Tuple solveEquation(double a, double b, double c){  // Функция по решению уравнения которая возвращает кортеж
    double D = b * b - 4 * a * c;
    int flag;
    double x1, x2;
    if (D == 0){  // В зависимости от дискриминанта задаём значения переменным
        flag = 0;
        x1 = - b / (2 * a);
        x2 = - b / (2 * a);
    }
    else if (D > 0) {
        flag = 1;
        x1 = (- b + sqrt(D)) / (2 * a);
        x2 = (- b - sqrt(D)) / (2 * a);
    }
    else {
        flag = -1;
        x1 = 0;
        x2 = 0;
    }
    auto t0 = std::make_tuple(flag, x1, x2);  // Помещаем эти переменные в кортеж и возвращаем его
    return t0;
}

int main() {
    int a, b, c;
    std::cout << "Введите коэффициенты уравнения: ";
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    auto r0 = solveEquation(a, b, c);

    if (std::get<0>(r0) == 1){
        std::cout << "Корни уравнения: " << std::get<1>(r0) << " и " << std::get<2>(r0);
    }
    else if (std::get<0>(r0) == 0){
        std::cout << "Корень уравнения: " << std::get<1>(r0);
    }
    else {
        std::cout << "Корней нет";
    }
    return 0;
}
