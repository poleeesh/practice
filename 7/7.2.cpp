#include <iostream>
#include <cmath>
#include <csignal>


struct Root  // Создаём структуру решения квадратного уравнения
{
    double x1;
    double x2;
};

Root solveEquation(double a, double b, double c){  // Функция для решения
    Root r;  // Задаём структуру решения которую вернём
    double D = b * b - 4 * a * c;  // Считаем дискриминант
    if (D == 0){  // Если он равен 0 то корни будут одинаковые
        r.x1 = - b / (2 * a);
        r.x2 = - b / (2 * a);
    }
    else if (D > 0) {  // Если больше 0 то корни разные
        r.x1 = (- b + sqrt(D)) / (2 * a);
        r.x2 = (- b - sqrt(D)) / (2 * a);
    }
    else {  // Если меньше 0 то останавливаем программу возвращая сигнал
        std::raise(SIGFPE);
    }
    return r;
}

int main() {
    int a, b, c;  // Получаем коэффициенты уравнения
    std::cout << "Введите коэффициенты уравнения: ";
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    Root r0 = solveEquation(a, b, c);  // Используем нашу функцию и выводим решение

    std::cout << "Корни уравнения: " << r0.x1 << " и " << r0.x2;
    return 0;
}
