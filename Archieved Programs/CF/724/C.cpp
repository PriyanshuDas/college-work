#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int
#define ull unsigned long long int
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define loop(l,r) for(int i = l; i < r; i++)
#define k_max 100001

using namespace std;

int n, m, k;
int M = 1, C = 0;
map <pair<int, int>, vector <int> > Mp;
ll m_tim[k_max+1];
vector <pair<int, int> > K;

bool satisfies(int x, int y)
{
	if(y - M*x + C == 0)
		return 1;
	return 0;
}

int collide_x(int x0)
{
	return (M*x0 + C);
}

int collide_y(int y0)
{
	return (y0 - C)*M;
}

int main()
{
	sf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++)
	{
		int xi, yi;	sf("%d%d", &xi, &yi);
		int c1 = yi-xi, c2 = yi+xi;
		Mp[mp(1, c1)].pb(i);
		Mp[mp(-1, c2)].pb(i);
		K.pb(mp(xi, yi));
	}
	int k2 = k;
	int flag = 0, c_x = 0, c_y = 0,inc_x = 1, inc_y = 1;
	ll c_tim = 0;
	memset(m_tim, -1, sizeof(m_tim));
	while(flag == 0)
	{
		//pf("(Y == %d*X + %d\n", M, C);
		if(satisfies(n, m) || satisfies(n, 0) || satisfies (m, 0) || k2==0)
		{
			flag = 1;
		}
		map <pair<int, int>, vector<int> >::iterator it;
		it = Mp.find(mp(M, C));
		if(it != Mp.end())
		{
			for(int i = 0; i < it->second.size(); i++)
			{
				int pos = it->second[i];
				ll t_tim = abs(c_x - K[pos].first);
				if(m_tim[pos] == -1)
				{
					k2--;
					m_tim[pos] = c_tim+t_tim;
				}
			}
			Mp.erase(it);	
		}
		int n_x = 0, n_y = 0;
		if(inc_x == 1 && inc_y == 1)	// going (x++, y++)
		{
			int x = collide_y(m);
			int y = collide_x(n);
			if(x >= 0 && x <= n)
			{
				n_x = x;
				n_y = m;
				c_tim = c_tim + abs(n_x - c_x);
				c_x = n_x;
				c_y = n_y;
				M = -1;
				C = c_y + c_x;
				inc_y = 0;
			}
			else if(y >= 0 && y <= m)
			{
				n_y = y;
				n_x = n;
				c_tim = c_tim + abs(n_y - c_y);
				c_x = n_x;
				c_y = n_y;
				M = -1;
				C = c_y + c_x;
				inc_x = 0;
			}
		}
		else if (inc_x == 1 && inc_y == 0)
		{
			int x = collide_y(0);
			int y = collide_x(n);
			if(x >= 0 && x <= n)
			{
				n_x = x;
				n_y = 0;
				c_tim = c_tim + abs(n_x - c_x);
				c_x = n_x;
				c_y = n_y;
				M = 1;
				C = c_y - c_x;
				inc_y = 1;
			}
			else if(y >= 0 && y <= m)
			{
				n_y = y;
				n_x = n;
				c_tim = c_tim + abs(n_x - c_x);
				c_x = n_x;
				c_y = n_y;
				M = 1;
				C = c_y - c_x;
				inc_x = 0;
			}
		}
		else if(inc_x == 0 && inc_y == 1)
		{
			int x = collide_y(m);
			int y = collide_x(0);
			if(x >= 0 && x <= n)
			{
				n_x = x;
				n_y = m;
				c_tim = c_tim + abs(n_y - c_y);
				c_x = n_x;
				c_y = n_y;
				M = 1;
				C = c_y - c_x;
				inc_y = 0;
			}
			else if(y >= 0 && y <= m)
			{
				n_y = y;
				n_x = 0;
				c_tim = c_tim + abs(n_y - c_y);
				c_x = n_x;
				c_y = n_y;
				M = 1;
				C = c_y - c_x;
				inc_x = 1;
			}
		}
		else if (inc_x == 0 && inc_y == 0)
		{
			int x = collide_y(0);
			int y = collide_x(0);
			if(x >= 0 && x <= n)
			{
				n_x = x;
				n_y = 0;
				c_tim = c_tim + abs(n_x - c_x);
				c_x = n_x;
				c_y = n_y;
				M = -1;
				C = c_y + c_x;
				inc_y = 1;
			}
			else if(y >= 0 && y <= m)
			{
				n_y = y;
				n_x = 0;
				c_tim = c_tim + abs(n_y - c_y);
				c_x = n_x;
				c_y = n_y;
				M = -1;
				C = c_y + c_x;
				inc_x = 1;
			}
		}
	}
	//cout << "BABA";
	for(int i = 0; i < k; i++)
	{
		pf("%lld\n", m_tim[i]);
	}
	return 0;
}
