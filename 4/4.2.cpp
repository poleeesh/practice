#include <iostream>

using namespace std;

bool Input(int &a, int &b) {
    cout << "Введите 2 числа: ";
    cin >> a;
    cin >> b;
    // Тут я сама придумала рандомные правила для чисел
    if (((a % 7 == 0 || a % 23 == 0) && (a < 500)) && ((b % 4 == 0 || b % 3 == 0) && (b < 200))){
        return true;
    }
    return false;
}

int main() {
    int a, b;
    if (!Input(a, b)){
        cerr << "error";
        return 1;
    }
    int s = a + b;
    return 0;
}
