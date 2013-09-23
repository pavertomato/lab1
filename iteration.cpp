#include "PolStr.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
//t -- expression
double findIteration(char *t, double a, double b, double eps,double& result) {
    double lam;
    double x;
    if (fabs(EvalPolStr(t,a,1))<1)
        x=a;
    else if (fabs(EvalPolStr(t,b,1))<1)
        x=b;
    lam = EvalPolStr(t,x,0);
    while (1) {
        result = EvalPolStr(t,x,0);
        double newx = x-result/lam;
        if (fabs(newx-x)<eps || fabs(result)<eps) {
            return newx;
        }
        x = newx;
    }
}
