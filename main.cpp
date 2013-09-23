#include <iostream>
#include <string>
#include "PolStr.h"
#include <string.h>
#include "newton.h"
#include "diho.h"
#include "combined.h"
#include "chord.h"
#include "golden.h"
#include <cmath>
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
    double x,y;
    try {
        t=CreatePolStr(t,0);
        if (n==1)
            x = findDiho(t,a,b,eps,y);
        if (n==2)
            x = findChord(t,a,b,eps,y);
        if (n==3)
            x = findNewton(t,a,b,eps,y);
        if (n==4)
            x = findCombined(t,a,b,eps,y);
        if (n==6)
            x = findGolden(t,a,b,eps,y);
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
    cout.precision(-log10(eps));
    cout << "x : " << x << "; f(x) : " << y << "; eps: " << eps << endl;
    return 0;
}
