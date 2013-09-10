#include <iostream>
#include <string>
#include "PolStr.h"
#include <string.h>
using namespace std;
int main(int argc, char **argv) {

    int n;
    string spol;
    double a,b,eps;
    cin >> n;
    getline(cin,spol);
    getline(cin,spol);
    cin >> a,b;
    cin >> eps;
    char* t = new char[1000];
    strcpy(t,spol.c_str());
    t=CreatePolStr(t,0);
    cout<<t;
    for(int i=0;i<3;i++)
        cout<<EvalPolStr(t,i);
    return 0;
}
