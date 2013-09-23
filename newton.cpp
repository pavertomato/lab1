#include "PolStr.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
//t -- expression
double findNewton(char *t, double a, double b, double eps, double& result) {
    cout << "Newton method : \n";
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
        result = EvalPolStr(t,x,0);
        //cerr << x << ' ' << result << ' ' << derivative << endl;
        double newx = x-result/derivative;
        if (fabs(newx-x)<eps || fabs(result)<eps) {
            return newx;
        }
        x = newx;
    }
}
