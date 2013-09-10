#include <iostream>
#include <string>
#include "PolStr.h"
#include <string.h>
#include "newton.h"
using namespace std;
int main(int argc, char **argv) {

    int n;
    string spol;
    double a,b,eps;
    cin >> n;
    getline(cin,spol);
    getline(cin,spol);
    cin >> a >> b;
    cin >> eps;
    char* t = new char[1024+1];
    strcpy(t,spol.c_str());
    try {
        t=CreatePolStr(t,0);
        cout<<EvalPolStr(t,5)<<endl;
        if (n==2)
            cout<<findNewton(t,a,b,eps);
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
    return 0;
}
