#include <iostream>
#include <string>

using namespace std;


template<typename T>
void Print(const T& t, const string& s){
    bool f = true;
    for (const auto& v : t){
        if (!f){
            cout << s;
        }
        f = false;
        cout << v;
    }
    cout << "\n";
}


int main(){
    int arr[] = {9,3,17,6,5,4,31,2,12};
    Print(arr, ", ");
}
