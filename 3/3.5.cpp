#include <iostream>
#include <string>

std::string perevod(int num){
    if (num / 2 != 0){  // Если число больше не делится на 2 целочисленно, то возвращаем 1
        return perevod(num / 2) + std::to_string(num % 2);
        // Иначе делим число на 2 и передаём в функцию, прибавляя к ней остаток от старого числа
    }
    else {
        return "1";
    }
}

int main(){
    int n;
    std::cout << "Введите число: ";
    std::cin >> n;
    std::cout << "Это число в двоичной системе будет равно " << perevod(n);
}
