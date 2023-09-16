#include "triangle.h"
#include <cmath>
#include <iostream>

using namespace std;


Triangle::Triangle(Dot a, Dot b, Dot c){
    this -> a = a;
    this -> b = b;
    this -> c = c;
}


void Triangle::show_sides() {
    double side1 = a.distanceTo(b);
    double side2 = a.distanceTo(c);
    double side3 = c.distanceTo(b);

    cout << "Стороны треугольника равны: " << side1 << ", " << side2 << ", " << side3 << endl;
}


double Triangle::perimetr(){
    double side1 = a.distanceTo(b);
    double side2 = a.distanceTo(c);
    double side3 = c.distanceTo(b);

    double p = side1 + side2 + side3;
    return p;
}


double Triangle::square(){
    double side1 = a.distanceTo(b);
    double side2 = a.distanceTo(c);
    double side3 = c.distanceTo(b);

    double p = perimetr();

    double s = sqrt(p * (p - side1) * (p - side2) * (p - side3));
    return s;
}
