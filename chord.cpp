#include "PolStr.h"
#include "chord.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
double findChord(char *t, double a, double b, double eps, double& value, double& result) {
    cout << "Chord method : \n";
        double c;
        double oldC;
        do
        {
        
            c=a-(EvalPolStr(t,a)/(EvalPolStr(t,b)-EvalPolStr(t,a)))*(b-a);
            //cout<<a<<' '<<b<<' '<<c<<' '<<EvalPolStr(t,a)<<' '<<EvalPolStr(t,b)<<' '<<EvalPolStr(t,c)<<endl;
            
            
            if(EvalPolStr(t,a)*EvalPolStr(t,c)<=0)
            {
                oldC=b;
                b=c;
            }
            else
            {
                oldC=a;
                a=c;
            }
            result = fabs(EvalPolStr(t,c));
            value = fabs(c-oldC);
        }
        while(result>eps||value>eps);
        return c;

}
