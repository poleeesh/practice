#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;


class Point{
public:
    double x;
    double y;

    Point(double x, double y){
        this->x = x;
        this->y = y;
    }

    double distance() const{
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    friend bool operator< (const Point &p1, const Point &p2){
        double s1 = p1.distance();
        double s2 = p2.distance();

        if (s1 < s2){
            return true;
        }
        return false;
    }

    friend ostream& operator<< (ostream &out, const Point &p){
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};


int main()
{
    std::vector<Point> v;
    v.push_back(Point(1,2));
    v.push_back(Point(10,12));
    v.push_back(Point(21,7));
    v.push_back(Point(4,8));
    std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для

// класса Point

    for (auto &point : v)
        std::cout << point << '\n'; // требуется перегрузка оператора << для

// класса Point

    return 0;
}
