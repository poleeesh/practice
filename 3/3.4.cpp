#include <iostream>

int summa(int n){
    if (n == 0){  // Если наше число - 0 то к сумме добавляется 0
        return 0;
    }
    else {  // В другом случае добавляем 5 * n и сумму всех меньших значений > 0
        return (5 * n + summa(n - 1));
    }
}

int main(){
    int n;
    std::cout << "Введите число: ";
    std::cin >> n;
    std::cout << "Сумма ряда равна " << summa(n);
}
