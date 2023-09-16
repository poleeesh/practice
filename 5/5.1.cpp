#include <iostream>

using namespace std;

int array_sum(const int n, int Arr[]) {  // Функция для суммы массива
    int s = 0;
    for (int i=0; i<n; i++)
    {
        s += Arr[i];
    }
    return s;
}

double array_average(const int n, int Arr[]) {  // Функция для вычисления среднего в массиве
    int s = 0;
    for (int i=0; i<n; i++)
    {
        s += Arr[i];
    }
    return s / n;
}

int array_sum_positive(const int n, int Arr[]) {  // Функция для суммы положительных чисел массива
    int s = 0;
    for (int i=0; i<n; i++)
    {
        if (Arr[i] > 0){
            s += Arr[i];
        }
    }
    return s;
}

int array_sum_negative(const int n, int Arr[]) {  // Функция для суммы отрицательных чисел массива
    int s = 0;
    for (int i=0; i<n; i++)
    {
        if (Arr[i] < 0){
            s += Arr[i];
        }
    }
    return s;
}

int array_sum_even(const int n, int Arr[]) {  // Функция для суммы чётных чисел массива
    int s = 0;
    for (int i=0; i<n; i++)
    {
        if (Arr[i] % 2 == 0){
            s += Arr[i];
        }
    }
    return s;
}

int array_sum_odd(const int n, int Arr[]) {  // Функция для суммы нечётных чисел массива
    int s = 0;
    for (int i=0; i<n; i++)
    {
        if (Arr[i] % 2 != 0){
            s += Arr[i];
        }
    }
    return s;
}

void sort_selection(const int n, int a[]) {  // Функция для сортировки массива выбором
    int min;
    int buf;

    for (int i = 0; i < n; i++){
        min = i;
        for (int j = i + 1; j < n; j++){
            min = ( a[j] < a[min] ) ? j : min;}
        if (i != min){
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }
}

int main() {
    const int n = 10;  // Задаём длину массива и сам массив
    int a[n]={ 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

    // Выводим результат всех функций с этим массивом :)
    cout << array_sum(n, a) << endl;
    cout << array_average(n, a) << endl;
    cout << array_sum_positive(n, a) << endl;
    cout << array_sum_negative(n, a) << endl;
    cout << array_sum_even(n, a) << endl;
    cout << array_sum_odd(n, a) << endl;
    sort_selection(n, a);
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}
