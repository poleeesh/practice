#include <iostream>
#include <string>

using namespace std;

int main(){
    string snils;
    string control_sum;
    cout << "Введите номер снилса: ";
    cin >> snils;  // Номер снился хранится в этой переменной
    if (snils.length() != 11){  // Если в нём не 11 символов то выводим ошибку
        cout << "Неправильный номер снилса";
    }
    else {
        int summ = 0, counter = 0;
        char pred = 10, curr;
        for (int i = 9; i > 0; i--){
            summ = summ + ((int(snils[i - 1]) - 48) * (10 - i));  // Создаём контрольную сумму согласно указанным условиям
            curr = snils[i - 1];
            if (pred == curr){  // Проверяем равна ли предыдущая цифра текущей
                counter++;  // Если это происходит больше 2х раз подряд то выводим ошибку
                if (counter > 1){
                    cout << "Неправильный номер снилса";
                    return 0;
                }
            }
            else {
                counter = 0;  // Если не равна то обновляем счётчик заново
            }
            pred = snils[i - 1];
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

        string snils_sum = snils.substr(9, 2);  // Выводим действительную сумму и сравниваем с нашей
        if (snils_sum == control_sum){
            cout << "True";
        }
        else {
            cout << "False";
        }
        return 0;
    }
}
