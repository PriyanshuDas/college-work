/*Equation of circle of the form A(x2 + y2) + Bx + Cy +D  when three points are given */

#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> coeff(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int A, B, C, D, a1, a2, a3;
    vector<int> v;
    a1= x1*x1 + y1*y1, a2 = x2*x2 + y2*y2, a3 = x3*x3 + y3*y3;
    A = x1*(y2 - y3) - y1*(x2 - x3) + (x2*y3 - y2*x3);
    B = a1*(y2-y3) - y1*(a2 - a3) + (y3*(a2) - y2*a3);
    C = a1*(x2 - x3) - x1*(a2 - a3) + (a2*x3 - a3*x2);
    D = a1*(x2*y3 - x3*y2) - x1*(a2*y3 - a3*y2) + y1*(a2*x3 - a3*x2);
    v.pb(1), v.pb(-B/A), v.pb(C/A), v.pb(-D/A);                         //To get the eqn in (x2 + y2) + B/A x + C/A y + D/A = 0
    return v;
}

int main()
{
    vector<int> coeff1;
    coeff1 = coeff(-6, 5, -3, -4, 2, 1);
    for(int i=0; i<4;i++)
        cout<<coeff1[i]<<" ";

    return 0;
}
