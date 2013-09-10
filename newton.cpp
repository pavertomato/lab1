#include "PolStr.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
//t -- expression
double findNewton(char *t, double a, double b, double eps) {
    double x;
    if (EvalPolStr(t,a,0)*EvalPolStr(t,a,2)>0)
        x = a;
    else if (EvalPolStr(t,b,0)*EvalPolStr(t,b,2)>0)
        x = b;
    else
        x = (a+b)/2;
    while (1) {
        double derivative = EvalPolStr(t,x,1);
        if (derivative==0) throw invalid_argument("0 devision");
        double newx = x-EvalPolStr(t,x,0)/derivative;
        if (fabs(newx-x)<eps) 
        {
        
            cout << "x : " << x << " -> " << EvalPolStr(t,x,0) << ' ' << eps<< endl;
            return newx;
        }
        x = newx;
    }
}
