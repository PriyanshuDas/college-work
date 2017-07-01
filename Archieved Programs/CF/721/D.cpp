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

using namespace std;

int main()
{
	ll n, k, x;
	cin >> n >> k >> x;
	vector <ll> V;
	map <ll, set<int> > S;
	int n_c = 0, m_pos = 0;
	for(int i = 0; i < n; i++)
	{
		ll tmp;	sf("%lld", &tmp);
		V.pb(tmp);
		if(tmp < 0)
			n_c++;
		if(abs(V[i]) < abs(V[m_pos]))
			m_pos = i;
	}
	//cout << n_c << endl;
	int flag = 0;	// 0- inc abs, 1 - dec abs
	if(n_c%2 == 0)
	{
		ll ct = abs(V[m_pos])/x;
		ll del = x*k;
		if(abs(V[m_pos]) - del >= 0)
		{
			if(V[m_pos] < 0)
				V[m_pos] = V[m_pos] + del;
			else
				V[m_pos] = V[m_pos] - del;
			k = 0;
		}
		else
		{
			ll fl = 1;
			if(V[m_pos] >= 0)
				fl = -1;
			if(ct <= k)
			{
				k -= ct;
				ll del = ct*x;
				V[m_pos] = V[m_pos] + fl*del;
			}
			if(k > 0)
			{
				k--;
				V[m_pos] = V[m_pos] + fl*x;
			}
		}
	}
	for(int i = 0; i < V.size(); i++)
	{
		ll t = abs(V[i]);
		S[t].insert(i);
	}
	while(k > 0)
	{
		map<ll, set<int> >::iterator it = S.begin();
		ll val = it->first;
		//cout << val << endl;
		int pos = *((it->second).begin());
		ll del = x;
		k--;
		if(flag == 1)
			del = -x;
		if(V[pos] >= 0)
			V[pos] = V[pos] + del;
		else if(V[pos] < 0)
			V[pos] = V[pos] - del;
		S[val].erase(S[val].begin());
		if(S[val].size() == 0)
		{
			S.erase(val);
		}
		(S[abs(V[pos])]).ins(pos);
	}
	for(int i = 0; i < V.size(); i++)
	{
		pf("%lld ", V[i]);
	}
	return 0;
}
