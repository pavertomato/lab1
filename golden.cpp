#include "PolStr.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
//t -- expression
double findGolden(char *t, double a, double b, double eps, double& value, double& result) {
    cout << "Golden Ratio method : \n";
    double acur = a, bcur = b;
    const double ratio = (sqrt(5)+1)/2;
    while (1) {
        double dcur = acur+(bcur-acur)/ratio;
        double ccur = bcur+acur-dcur;
        if (EvalPolStr(t,acur,0)*EvalPolStr(t,dcur,0)<=0)
            bcur = dcur;
        else
            acur = ccur;
        result = fabs(EvalPolStr(t,(acur+bcur)/2,0));
        value = fabs(bcur-acur)/2;
        if (result<eps && value<eps) {
            return (acur+bcur)/2;
        }
    }
}
