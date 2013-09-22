#include "PolStr.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
//t -- expression
double findCombined(char *t, double a, double b, double eps) {
    cout << "Combined method : \n";
    double acur = a, bcur = b;
    while (1) {
        double difference = EvalPolStr(t,bcur,0)-EvalPolStr(t,acur,0);
        if (difference==0) throw invalid_argument("0 devision by difference");
        double ccur = acur - EvalPolStr(t,acur,0)/difference*(bcur-acur);
        if (EvalPolStr(t,acur,0)*EvalPolStr(t,acur,2)>0) {
            double derivative = EvalPolStr(t,acur,1);
            if (derivative==0) throw invalid_argument("0 devision by derivative");
            acur -= EvalPolStr(t,acur,0)/derivative;
            bcur = ccur;
        }
        else {
            acur = ccur;
            double derivative = EvalPolStr(t,bcur,1);
            if (derivative==0) throw invalid_argument("0 devision by derivative");
            bcur -= EvalPolStr(t,bcur,0)/derivative;
        }
        double result = EvalPolStr(t,(acur+bcur)/2,0);
        if (fabs(bcur-acur)/2<eps || fabs(result)<eps) {
            cout << "x : " << (acur+bcur)/2 << "; f(x) : " << result << "; eps: " << eps << endl;
            return (acur+bcur)/2;
        }
    }
}
