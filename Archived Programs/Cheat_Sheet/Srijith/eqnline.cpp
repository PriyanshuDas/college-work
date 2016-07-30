//To calculate the coefficients of a line equation ax+by+c=0 given two points

#include<bits/stdc++.h>
using namespace std;

vector<int> coeff(int x1, int y1, int x2, int y2)  //Two points given
{
    int a, b, c;
    y2=y2-y1;
    x2=x2-x1;
    if(y2<0)
    {
        x2=-x2;
        y2=-y2;
    }
    vector<int> v;
    v.push_back(y2), v.push_back(-x2), v.push_back(x2*y1 - y2*x1);
    return v;
}

//Driver Program
int main()
{
    vector<int> a;
    a=coeff(5, 1, 2, 3);
    for(int i=0;i<3;i++)
        cout<<a[i]<<" ";
    return 0;
}
