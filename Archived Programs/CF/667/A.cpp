#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define PI 3.14159265359

using namespace std;

double conv_cm_ml(int cm, int d)
{
    double cm3 = (PI*d*d*cm)/4;
    return cm3;
}

int main()
{
    int d, h, v, e;
    cin >> d >> h >> v >> e;
    double area = PI*d*d*0.25*h;
    double inc_rate = conv_cm_ml (e, d);
   // cout << "Rate of decrease is : " << inc_rate << endl;
    double rate_ch = inc_rate - v;
    if(rate_ch > 0.00001)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    double time_take = area/abs(rate_ch);
    cout << setprecision(9) << time_take;
    return 0;
}
