#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define loop(n) for(int i = 0; i < n; i++)
#define loop(l,n) for(l; l < n; l++)
#define pi2 pair<int, int>
#define pi3 pair<int, pair<int,int> >
#define pi4 pair<pair<int, int>, pair<int, int> >
#define pi 3.1415926535897932384626433832795
#define eps 0.01

using namespace std;

ll P_x, P_y;

double dist(double x, double y)
{
    double ans = (x-P_x)*(x-P_x) + (y-P_y)*(y-P_y);
    return ans;
}
bool cache_flag = 0;
pair <double, double> point_on_line(double x1, double y1, double x2, double y2)
{
    cache_flag = 0;
    double x3 = P_x, y3 = P_y;
    double u = (double)((x3 - x1)*(x2-x1) + (y3-y1)*(y2-y1))/(double)((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
    double x = x2*u + x1*(u-1);
    double y = y2*u + y1*(u-1);
    pair <double, double> ans = mp(x, y);
    if(u < 0 || u > 1.0)
        cache_flag = 1;
    return ans;
}

double dist(double x1, double y1, double x2, double y2)
{
    double ans = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return ans;
}

int main()
{
    int n;
    cin >> n >> P_x >> P_y;
    double min_rad = 99999999999999999, max_rad = 0;
    vector <double> x_list;
    vector <double> x_list2;
    vector <double> y_list2;
    vector <double> y_list;
    for(int i = 0; i < n; i++)
    {
        double t_x, t_y;
        sf("%lf%lf", &t_x, &t_y);
        x_list.pb(t_x); y_list.pb(t_y);
    }
    for(int i = 0; i < n; i++)
    {
        double x_1 = x_list[i], y_1 = y_list[i], x_2 = x_list[(i-1+n)%n], y_2 = y_list[(i-1+n)%n];
        pair<double, double> tmp = point_on_line(x_1, y_1, x_2, y_2);
        double x_3 = tmp.first, y_3 = tmp.second;
        x_list2.pb(x_1);
        y_list2.pb(y_1);
        x_list2.pb(x_2);
        y_list2.pb(y_2);
        if(!cache_flag)
        {
            x_list2.pb(x_3);
            y_list2.pb(y_3);
        }
    }
    for(int i = 0; i < x_list2.size(); i++)
    {
        double d = dist(x_list2[i], y_list2[i]);
        if(d < min_rad)
            min_rad = d;
        if(d > max_rad)
            max_rad = d;
    }
    double ans = pi*(double)(max_rad - min_rad);
    pf("%0.12lf", ans);
    return 0;
}
