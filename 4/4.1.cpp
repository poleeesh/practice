#include <iostream>
#include <cmath>

using namespace std;

int Myroot(double a, double b, double c, double &x1, double &x2) {
    double D = b * b - 4 * a * c;  // Переменная для дискриминанта
    if (D < 0){  // Если меньше 0 то сразу завершаем
        return -1;
    }
    else if (D == 0){  // Если равно 0 то обновляем значения по указателю и завершаем
        x1 = (-b + sqrt(D)) / 2 / a;
        x2 = (-b - sqrt(D)) / 2 / a;
        return 0;
    }  // В другом случае то же самое, но возвращаем другую цифру
    x1 = (-b + sqrt(D)) / 2 / a;
    x2 = (-b - sqrt(D)) / 2 / a;

    return 1;
}

int main() {
    double a, b, c, x1, x2;

    cout << "Введите коэффициенты уравнения: ";
    cin >> a;
    cin >> b;
    cin >> c;

    int solve = Myroot(a, b, c, x1, x2);
    if (solve == 0){
        cout << "Корень уравнения один  -  " << x1;
    }
    else if (solve == 1){
        cout << "Корня уравнения два -  " << x1 << " и " << x2;
    }
    else {
        cout << "Корней уравнения нет";
    }
    return 0;
}
