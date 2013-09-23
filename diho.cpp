#include <iostream>
#include <string>
#include <math.h>
#include "PolStr.h"
#include "diho.h"
#include <string.h>
using namespace std;
double findDiho(char *t, double a, double b, double eps, double& result) {
    cout << "Dihotomy method : \n";
        double c;
        int i=10;
        do
        {
            c=(a+b)/2;
            //cout<<a<<' '<<b<<' '<<c<<' '<<EvalPolStr(t,c)<<endl;
            if(EvalPolStr(t,a)*EvalPolStr(t,c)<=0)
                b=c;
            else
                a=c;
            i--;
        }
        while(fabs(EvalPolStr(t,c))>eps||(b-a)/2>eps);
        result = EvalPolStr(t,c);
        return c;
}

