#include "PolStr.h"
#include "chord.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
double findChord(char *t, double a, double b, double eps) {
        double c=0;
        double oldC=c+100;
        do
        {
        
            oldC=c;
            c=a-(EvalPolStr(t,a)/(EvalPolStr(t,b)-EvalPolStr(t,a)))*(b-a);
            cout<<a<<' '<<b<<' '<<c<<' '<<EvalPolStr(t,a)<<' '<<EvalPolStr(t,b)<<' '<<EvalPolStr(t,c)<<endl;
            if(EvalPolStr(t,a)*EvalPolStr(t,c)<=0)
                b=c;
            else
                a=c;
        }
        while(fabs(EvalPolStr(t,c))>eps||fabs(c-oldC)>eps);
        cout << "x : " << c << " -> " << EvalPolStr(t,c) <<' '<< eps<<endl;
        return c;

}
