#include <iostream>

int main(){
    int n;
    std::cout << "Введите сумму которую надо разменять: ";
    std::cin >> n;
    int n1 = 0, n2 = 0, n5 = 0, n10;
    // Вводим переменные, отвечающие за количество монет оперделённого достоинства для данного набора
    n10 = n / 10;  // Далее определяем их используя целочисленное деление, если есть остаток то делим дальше
    if (n % 10 != 0){
        n -= (n / 10) * 10;
        n5 = n / 5;
        if (n % 5 != 0){
            n -= (n / 5) * 5;
            n2 = n / 2;
            n1 = n % 2;
        }
    }
    // Выводим набор монет
    std::cout << "Для данной суммы вам нужен следующий набор: " << std::endl;
    if (n10 != 0){
        std::cout << n10 << " монет достоинством 10 рублей" << std::endl;
    }
    if (n5 != 0){
        std::cout << n5 << " монет достоинством 5 рублей" << std::endl;
    }
    if (n2 != 0){
        std::cout << n2 << " монет достоинством 2 рубля" << std::endl;
    }
    if (n1 != 0){
        std::cout << n1 << " монет достоинством 1 рубль" << std::endl;
    }
    return 0;
}
