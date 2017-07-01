#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll> >
#define lim 50000


using namespace std;

map <ll, ll> root;

int main()
{
	ll x;	cin >> x;
	ll n, m;
	int flag = 0;
	for(int i = 1; i <= lim; i++)
	{
		ll tmp = i*i;
		root[i*i] = i;
	}
	for(int i = 1; i <= lim; i++)
	{
		ll sq = i*i;
		if(root[x+sq] != 0 && flag == 0 && root[x+sq] > i)
		{
			ll curr = i;
			ll n1 = min(curr, root[x+sq]);
			ll m1 = max(curr, root[x+sq]);
			//cout << "n : " << n1 << " m : " << m1 << endl;
			if(m1 == 0 || n1 == 0)
				continue;
			n = n1;	m = m1;
			flag = 1;
		}
		else if (root[x-sq] != 0 && flag == 0)
		{
			ll n1 = min((ll)i, root[x-sq]);
			ll m1 = max((ll)i, root[x-sq]);
			if(m1 == 0 || n1 == 0)
				continue;
			n = n1;
			m = m1;
			flag = 1;
		}
		else if (x%i == 0 && (x/i)%2 == 0 && flag == 0)
		{
			ll n1 = min((ll)i, x/(2*i));
			ll m1 = max((ll)i, x/(2*i));
			if(m1 == 0 || n1 == 0)
				continue;
			n = n1;
			m = m1;
			flag = 1;
		}
	}
	//cout << m << ' ' << n << endl;
	ll a = m*m - n*n, b = 2*m*n, c = (m*m + n*n);
	if(flag == 0)
		cout << "-1";
	else
	{
		if(x != a)
			cout << a << ' ';
		if(x != b)
			cout << b << ' ';
		if(x != c)
			cout << c << ' ';
	}
	return 0;
}
