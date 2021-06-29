#include <iostream>
#include <cmath>
using namespace std;
//3 o + ecuaciones y depende de cual sea el x,y,z con coeficiente mas grande en esa ecuacion es la que despejas
double fx(double y, double z) {
    
    return (4 + 2*y - z)/3;
}

double fy(double x, double z) {
    
    return (6 - x - 2*z)/5;
}

double fz(double x, double y) {
    
    return (1 + 2*x - 3*y)/6;
}

int main() {
    
    double x, y, z, tx, ty, tz;
    double error = pow(10, -12);
    int i=0;
    x = y = z = 0.0;
    
    do {
        
        tx = fx(y, z);
        ty = fy(x, z);
        tz = fz(x, y);
        x=tx;
        y=ty;
        z=tz;
        i++;
        cout << x << " | " << y << " | " << z << " | " << i << endl;
    }
    while(abs(3*x - 2*y + z - 4)>error || abs(x + 5*y + 2*z - 6)>error || abs(-2*x + 3*y + 6*z - 1)>error);
    //x + y + z - 12 error absoluto
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "iteraciones = " << i << endl;
    
}
