//
//  main.cpp
//  Newton-raphson
//
//  Created by Floreth Gonzalez on 02/02/17.
//  Copyright © 2017 Floreth Gonzalez. All rights reserved.
//

#include <iostream>
#include <cmath>
#define FUNCTION  x*x
#define FUNCTION2 2x
//x*x*x+5*x-10 derivada 3*x*x+5*x

float recursion (float x0,float TOL, int maxIterations){
    float x1=0, fx,fpx, h;
    int i =1;
    do {
        //FUNCION ORIGINAL EVALUADA
        //fx=pow (x0, 3.0)+5*(x0)-10;
        //fx=pow (x0, 2.0);
        fx=(log(x0))/x0;

        //DERIVADA DE LA FUNCION ORIGINAL EVALUADA
        //fpx=3*pow (x0, 2.0)+5;
        //fpx=2*(x0);
        fpx=(1-log(x0))/pow(x0,2.0);

        h=fx/fpx;
        x1= x0-h;
        std::cout << "iteración: "<<i<< "\n";
        std::cout << "xi: "<<x1<< "\n";


        if(fabs(x1-x0)<=TOL){
            //std::cout << "error: "<<fabs((x1-x0)/x1)<< "\n";
            return x1;
        }else{
            x0 = x1;
        }
        i ++;
        }while( i<maxIterations);
    return x1;
}

int main() {
    // insert code here...
    float x0,x;

    std::cout << "Dame tu Xo: ";
    std::cin >> x0;
    
    x = recursion(x0,0.00000001,90);
    std::cout << "respuesta: "<< x << "\n";
    
}

