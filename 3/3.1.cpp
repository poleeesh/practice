#include <iostream>
#include <string>

using namespace std;

bool check_snils(string snils){
    string control_sum;
    string normal_snils;  // Переменная для номера снилса без всяких символов
    for (int i = 0; i < snils.length(); i++){  // Создаём эту переменную
        if (snils[i] == ' ' || snils[i] == '-'){  // Пробел и дефис допустимы, ошибки не выводим
            continue;
        }
        if (isdigit(snils[i])) {  // Цифры добавляем в нашу переменную
            normal_snils += snils[i];
        }
        else {  // В других случаях выводим ошибку
            return false;
        }
    }
    if (normal_snils.length() != 11){  // Если в нём не 11 символов то выводим ошибку
        return false;
    }
    else {
        int summ = 0, counter = 0;
        char pred = 10, curr;
        for (int i = 9; i > 0; i--){
            summ = summ + ((int(normal_snils[i - 1]) - 48) * (10 - i));  // Создаём контрольную сумму согласно указанным условиям
            curr = normal_snils[i - 1];
            if (pred == curr){  // Проверяем равна ли предыдущая цифра текущей
                counter++;  // Если это происходит больше 2х раз подряд то выводим ошибку
                if (counter > 1){
                    return false;
                }
            }
            else {
                counter = 0;  // Если не равна то обновляем счётчик заново
            }
            pred = normal_snils[i - 1];
        }
        if (summ < 100){  // Далее определяем контрольную сумму согласно условиям
            control_sum = to_string(summ);
        }
        else if (summ == 100 || summ == 101){
            control_sum = "00";
        }
        else {
            int ostatok = summ % 101;
            if (ostatok < 100){
                control_sum = to_string(ostatok);
                if (control_sum.length() == 1){
                    control_sum = "0" + control_sum;
                }
            }
            else {
                control_sum = "00";
            }
        }

        string snils_sum = normal_snils.substr(9, 2);  // Выводим действительную сумму и сравниваем с нашей
        if (snils_sum == control_sum){
            return true;
        }
        else {
            return false;
        }
    }
}

int main(){
    string snils;
    std::cout << "Введите номер снилса: ";
    std::getline(std::cin, snils);

    bool is_ok = check_snils(snils);
    if (is_ok){
        std::cout << "Верный номер";
    }
    else {
        std::cout << "Неверный номер";
    }
    return 0;
}
