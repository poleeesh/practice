#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const int N = 10;
    int a[N]={ 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями

    ofstream out ("test", ios::out | ios::binary);  // Сначала записываем старый массив
    if (!out) {
        cout << "Файл открыть невозможно\n";
        return 1;
    }
    out.write((char *) a, sizeof(a));

    for (int i = 0; i < N; i++){  // Используем сортировку
        min = i; // номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < N; j++)
            min = ( a[j] < a[min] ) ? j : min;
        // перестановка этого элемента, поменяв его местами с текущим
        if (i != min){
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }

    out.write((char *) a, sizeof(a));  // Теперь записываем новый массив
    out.close();

    ifstream in("test", ios::in | ios::binary);  // Теперь читаем файл
    if(!in) {
        cout << "Файл открыть невозможно";
        return 1;
    }
    in.read((char *) &a, sizeof(a));  // Сначала читаем столько байтов сколько занимал один массив и выводим

    int k = sizeof(a)/sizeof(double);
    for (int i=0; i<k; i++){
        cout << a[i] <<' ';
    }

    cout << endl;
    in.read((char *) &a, sizeof(a));  // Теперь читаем оставшуюся половину файла

    for (int i=0; i<k; i++){
        cout << a[i] <<' ';
    }
    in.close();
}
