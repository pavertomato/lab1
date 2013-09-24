#include "PolStr.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
//t -- expression
double findIteration(char *t, double a, double b, double eps,double& result) {
    cout << "Iteration method : \n";
    double lam;
    double x;
    double max=-1;
    for(double i=a;i<b;i+=1e-100)
        if(fabs(EvalPolStr(t,i,1))>max)
                x=i;
    lam = fabs(EvalPolStr(t,x,0));
    while (1) {
        result = EvalPolStr(t,x,0);
        double newx = x-result/lam;
        if (fabs(newx-x)<eps && fabs(result)<eps) {
            return newx;
        }
        x = newx;
    }
}
