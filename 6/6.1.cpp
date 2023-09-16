#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string a[4];  // Создаём массив из 4х строк, просим пользователя ввести четверостишие
    cout << "Введите стихотворение из 4 строк: ";
    for (int i = 0; i < 4; i++){
        getline(cin, a[i]);
    }

    ofstream out ("test", ios::out | ios::binary);  // Создаём файл и записываем туда четверостишие
    if (!out) {
        cout << "Файл открыть невозможно\n";
        return 1;
    }
    out.write((char *) a, sizeof(a));
    out.close();  // Закрываем

    ifstream in("test", ios::in | ios::binary);  // Теперь открываем для чтения
    if(!in) {
        cout << "Файл открыть невозможно";
        return 1;
    }
    in.read((char *) &a, sizeof(a));

    for (int i = 0; i < 4; i++){  // Выводим то что прочитали
        cout << a[i] << endl;
    }
    in.close();
}
