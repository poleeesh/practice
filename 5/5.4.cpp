#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 4){  // Проверяем количество параметров
        cout << "Параметров меньше 4" << endl;
        return 0;
    }
    if (strncmp(argv[1], "-a", 2) != 0 && strncmp(argv[1], "-m", 2) != 0){  // Проверяем формат
        cout << "Неправильный формат" << endl;
        return 0;
    }

    // Если всё ок то выводим соответственно сумму/произведение
    if (strncmp(argv[1], "-a", 2) == 0){
        cout << (atoi(argv[2]) + atoi(argv[3])) << endl;
    }

    if (strncmp(argv[1], "-m", 2) == 0){
        cout << (atoi(argv[2]) * atoi(argv[3])) << endl;
    }
}
