#include <iostream>
#include <string>
#include <math.h>
#include "PolStr.h"
#include <string.h>
using namespace std;
int diho(string input,double a,double b,double eps) {
    char* t = new char[1000];
    strcpy(t,input.c_str());
    t=CreatePolStr(t,0);
    double c;
    int i=10;
    do
    {
    
            c=(a+b)/2;
            
            cout<<a<<' '<<b<<'\n';
            if(EvalPolStr(t,a)*EvalPolStr(t,c)<=0)
                b=c;
            else
                a=c;
            i--;
    }
    while(fabs(EvalPolStr(t,c))>eps&&(b-a)/2>eps);
    cout<<"==========="<<c<<"=================";
    return 0;
}

