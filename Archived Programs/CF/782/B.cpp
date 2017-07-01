#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define ins insert
#define max_x 1000000000
#define delta 0.000001
#define maxt 1000000000000000
using namespace std;

vector <ll> x;
vector <ll> v;

double bin_search()
{
	double l = 0;
	double r = max_x;
	double m = (l+r)*0.5;
	double t_ans = maxt;
	while(l+delta <= r)
	{
		m = (l+r)*0.5;
		vector <pair<double, int> > time;
		//(time, 0(left) 1 (right))
		double max_t = 0;
		int dir = 0;
		for(int i = 0; i < x.size(); i++)
		{
			double t = (abs((double)x[i]-m))/((double)v[i]);
			if(t > max_t)
			{
				max_t = t;
				if(x[i] > m)
					dir = 1;
				else
					dir = 0;
			}
		}
		//pf("(%lf, %lf, %lf)\t%lf\n", l, m, r, max_t);
		if (dir == 1)
		{
			l = m;
		}
		else
		{
			r = m;
		}
		t_ans = min(t_ans, max_t);
	}
	return t_ans;
}

int main()
{
	int n;	cin >> n;
	for(int i = 0; i < n; i++)
	{
		ll xi;	sf("%lld", &xi);
		x.pb(xi);
	}
	for(int i = 0; i < n; i++)
	{
		ll vi;	sf("%lld", &vi);
		v.pb(vi);
	}
	double ans = bin_search();
	pf("%0.9lf", ans);
	return 0;
}