#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back
#define pi2 pair<ll,ll>
#define pi3 pair<ll, pair<ll, ll> >

using namespace std;

vector <pair<double, int> > by_time;
vector <pair<int, double> > by_y;

int main()
{
    int n, w, u, v; cin >> n >> w >> v >> u;
    int before = 1;
    // w is width, n points, u - speed of pedestrian
    for(int i = 0; i < n; i++)
    {
        int xi, yi; cin >> xi >> yi;
        if(xi <= 0)
        {
            before = 0;
            continue;
        }
        double t = (double)xi/(double)v;
        by_time.pb(mp(t, yi));
        by_y.pb(mp(yi, t));
    }
    sort(by_y.begin(), by_y.end());
    for(int i = 0; i < by_y.size(); i++)
    {
        double t = by_y[i].second;
        double y = u*t;
        if(y < by_y[i].first)
        {
            //cout << y << " < " << by_y[i].first;
            before = 0;
        }
    }
    //cout << "Before : " << before << endl;
    if(before == 1)
    {
        double t = (double)w/(double)u;
        pf("%0.9lf", t);
        return 0;
    }
    double c_y = 0, c_t = 0;
    for(int i = 0; i < by_y.size(); i++)
    {
        double y = by_y[i].first, t = by_y[i].second;
        if(t < c_t)
            continue;
        double p_y = c_y + u*(t-c_t);
        if(p_y > y)
        {
            p_y = y;
        }
        c_y = p_y;
        c_t = t;
        //pf("Currently @ (%lf) with time (%lf)\n", c_y, c_t);
    }
    c_t = c_t + (w-c_y)/(double)u;
    pf("%0.9lf", c_t);
    return 0;
}
