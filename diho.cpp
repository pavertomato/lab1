#include <iostream>
#include <string>
#include <math.h>
#include "PolStr.h"
#include "diho.h"
#include <string.h>
using namespace std;
double findDiho(char *t, double a, double b, double eps, double& value, double& result) {
    cout << "Dihotomy method : \n";
        double c;
        do
        {
            c=(a+b)/2;
            //cout<<a<<' '<<b<<' '<<c<<' '<<EvalPolStr(t,c)<<endl;
            if(EvalPolStr(t,a)*EvalPolStr(t,c)<=0)
                b=c;
            else
                a=c;
            result = fabs(EvalPolStr(t,(a+b)/2));
            value = fabs((b-a)/2);
        }
        while(result>eps||value>eps);
        return c;
}

