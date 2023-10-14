#include <iostream>
#include "t_ime.h"

using namespace std;

int main() {
    const Time t1(23, 53, 34);
    const Time t2(28, 40, 12);

    Time t3;

    t3 = t1 - t2;

    
    return 0;
}
