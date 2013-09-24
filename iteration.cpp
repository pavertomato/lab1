#include "PolStr.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
//t -- expression
double findIteration(char *t, double a, double b, double eps, double& value, double& result) {
    cout << "Iteration method : \n";
    double lam;
    double x;
    double max=-1;
    for(double i=a;i<b;i+=0.0001) {
        if(fabs(EvalPolStr(t,i,1))>max)
            max=i;
    }
    x=max;
    lam = EvalPolStr(t,x,1);    
    while (1) {
        result = EvalPolStr(t,x,0);
        double newx = x-result/lam;
        result = fabs(result);
        value = fabs(newx-x);
        cerr << x << ' ' << result << ' ' << value << endl;
        if (result<eps && value<eps) {
            return newx;
        }
        x = newx;
    }
}
