#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define max_n 200000
#define del 0.001

using namespace std;

//  returns vector <a, b, c> satisfying ax + by + c = 0 for line passing
//  through (x1, y1) & (x2, y2)

vector <ll> find_eq (ll x1, ll y1, ll x2, ll y2)
{
    ll a, b, c;
    a = y2 - y1;
    b = x1 - x2;
    c = -b*y1 - a*x1;
    vector <ll> ret;   ret.pb(a);  ret.pb(b);  ret.pb(c);
    return ret;
}

//  returns true if (x, y) lies on ax+by+c = 0, given byeqn <a, b,c >

bool lies(vector<ll> eqn, ll x, ll y)
{
    ll ans = x*eqn[0] + y*eqn[1] + eqn[2];
    if(abs(ans) < del)
        return true;
    return false;

}

//  returns SQUARE of distance between (x1, y1) and (x2, y2)

double dist(ll x1, ll y1, ll x2, ll y2)
{
    double ret = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
    return ret;
}
int main()
{
    int k, n;   cin >> k >> n;
    vector<ll> st_x, st_y, m_x, m_y;
    for(int i = 0; i < k; i++)
    {
        ll ax, ay; sf("%lld%lld", &ax, &ay);
        st_x.pb(ax);    st_y.pb(ay);
    }
    for(int i = 0; i < n; i++)
    {
        ll ax, ay; sf("%lld%lld", &ax, &ay);
        m_x.pb(ax);    m_y.pb(ay);
    }
    int fear[1001] = {0};
    for(int i = 0; i < k; i++)
    {
        pf("@Stone %d : (%lld, %lld)\n", i, st_x[i], st_y[i]);
        ll x1 = st_x[i], y1 = st_y[i];
        for(int j = 0; j < n; j++)
        {
            ll x2 = m_x[j], y2 = m_y[j];
            vector<pair<double, int> > d_vec;
            pf("Processing Monster %d: (%lld, %lld)\n", j, m_x[j], m_y[j]);
            vector<ll> eqn = find_eq(x1, y1, x2, y2);
            pf("Eqn is : %lldx + %lldy + %lld == 0\n", eqn[0], eqn[1], eqn[2]);
            //double d1 = dist(x1, y1, x2, y2);
            //d_vec.pb(mp(d1, j));
            for(int k = 0; k < n; k++)
            {
                ll x3 = m_x[k], y3 = m_y[k];
                double d2 = dist(x1, y1, x3, y3);
                if(lies(eqn, x3, y3) == true)
                {
                    pair<double, int> tmp = mp(d2, k);
                    d_vec.pb(tmp);
                }
            }
            sort(d_vec.begin(), d_vec.end());
            for(int i = 0; i < d_vec.size(): i++)
            {
                if(fear[d_vec[i].second] == 0)
                {
                    fear[d_vec[0].second] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(fear[i] == 1)
            ans++;
    cout << ans;
    return 0;
}
