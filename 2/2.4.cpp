#include <iostream>
#include <ctime>
#include <cmath>

int main(){
    srand(time(NULL));  // Задаём рандом
    int x, y, counter = 0, s = 0;  // Задаём переменные для координат выстрела, счётчика выстрелов и суммы очков
    std::string rang;  // Переменная для ранга стрельбы
    int c1 = 0, c2 = 0, c3 = 0;  // Переменные считающие сколько раз попали в области мишени

    int x_center = rand() % 4;  // Задаём случайные центр координат и меткость
    int y_center = rand() % 4;
    int x_obstacle = rand() % 3 - 1;
    int y_obstacle = rand() % 3 - 1;

    while (s < 30){  // Пока сумма очков не превысит 30
        counter++;  // + 1 выстрел
        std::cout << "Введите координаты х и у: ";  // Вводим координаты
        std::cin >> x;
        std::cin >> y;
        // В завивимости от области в которой окажется выстрел добавляем очки
        if ((pow((x + x_obstacle - x_center), 2) + pow((y + y_obstacle - y_center), 2)) <= 1){
            s += 10;
            c1++;
        }
        else if ((pow((x + x_obstacle - x_center), 2) + pow((y + y_obstacle - y_center), 2)) <= 2){
            s += 5;
            c2++;
        }
        else if ((pow((x + x_obstacle - x_center), 2) + pow((y + y_obstacle - y_center), 2)) <= 8){
            s += 1;
            c3++;
        }
    }
    // Выводим количество выстрелов и ранг
    std::cout << "Количество ваших выстрелов: " << counter << std::endl;
    if (c1 > c2 && c1 > c3){
        rang = "Снайпер";
    }
    else if (c2 >= c1 && c2 > c3){
        rang = "Стрелок";
    }
    else {
        rang = "Новичок";
    }
    std::cout << "Вы - " << rang << std::endl;
    return 0;
}
