#include <iostream>
#include <string>
#include "PolStr.h"
#include <string.h>
#include "newton.h"
#include "diho.h"
#include "combined.h"
#include "chord.h"
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
        //cout<<t<<endl;
        if (n==1)
            findDiho(t,a,b,eps);
        if (n==2)
            findChord(t,a,b,eps);
        if (n==3)
            findNewton(t,a,b,eps);
        if (n==4)
            findCombined(t,a,b,eps);
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
    return 0;
}
