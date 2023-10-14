#include <iostream>

template<class T>
T average (T arr[], int size){
    T summ = 0;
    for (int i = 0; i < size; i++ ){
        summ = summ + arr[i];
    }
    return summ / size;
}


//int main(){
//    int arr[] = {9,3,17,6,5,4,31,2,12};
//    long longs[] = {1, 2, 3, 4, 5, 6};
//    double arrd[] = {2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2};
//    char arrc[] = "Hello, word";
//    int k1 = sizeof(arr)/sizeof(arr[0]);
//    int k2 = sizeof(arrd)/sizeof(arrd[0]);
//    int k4 = sizeof(longs)/sizeof(longs[0]);
//    int k3 = sizeof(arrc)/sizeof(arrc[0]) - 1;
//
//    std::cout << average(arr, k1) << std::endl;
//    std::cout << average(arrd, k2) << std::endl;
//    std::cout << average(arrc, k3) << std::endl;
//    std::cout << average(longs, k4) << std::endl;
//}
