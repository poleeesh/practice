#include <iostream>

using namespace std;

int search(int key, int arr[], int n) {  // Функция для поиска с алгоритмом транспонирования
    int ans = -1;  // Переменная которую возвращаем с индексом найденного ключа
    for (int i = 0; i < n; i++){
        if (arr[i] == key){  // Если мы нашли значение то меняем его местами с предыдущим
            ans = i;
            if (ans == 0){  // Кроме случая когда это самый первый член массива
                break;
            }
            swap(arr[i], arr[i - 1]);
        }
    }
    return ans;
}

int main() {
    int a[]={1,2,3,4,5,6,7,12};
    // Задали массив, и теперь проверяем что алгоритм работает
    cout << search(7, a, 8) << endl;
    cout << search(5, a, 8) << endl;
    cout << search(7, a, 8) << endl;
    cout << search(5, a, 8) << endl;
    cout << search(7, a, 8) << endl;
}
