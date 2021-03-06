#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int ct[300001];
	memset(ct, 0, sizeof(ct));
	set<pair<int, int> > edges;
	for(int i = 0; i < m; i++)
	{
		int a, b;
		sf("%d%d", &a, &b);
		ct[a]++;
		ct[b]++;
		//cout << "What";
		if(b < a)
			swap(a, b);
		edges.insert(mp(a, b));
	}
	for(int i = 1; i <= n; i++)
	{
		ct[i] = (n-1) - ct[i];
		//pf("Count[%d] == %d\n", i, ct[i]);
	}
	int flag = 1;
	ll sum1 = k - (ct[1] - k);
	vector<int> m_v;	m_v.pb(30001);	m_v.pb(ct[2]);
	sort(m_v.begin(), m_v.end());
	for(int i = 2; i <= n; i++)
	{
		sum1 += ct[i];
		if(ct[i] == 0)
			flag = 0;
		else if(ct[i] == 1)
		{
			auto it = edges.find(mp(1, i));
			if(it == edges.end())
			{
				it = edges.find(mp(i, 1));
				if(it == edges.end())
					flag = 0;
			}
		}
		if(ct[i] < m_v[1])
		{
			if(ct[i] < m_v[0])
			{
				m_v[1] = m_v[0];
				m_v[0] = ct[i];
			}
			else
				m_v[1] = ct[i];
		}
	}
	//sum -= (m_v[0] + m_v[1] - 2);
	if(sum1 < 2*(n-1) + (m_v[0] + m_v[1] - 2))
		flag = 0;
	if(ct[1] < k || k == 0)
		flag = 0;
	if(flag)
		cout << "possible";
	else
		cout << "impossible";
	return 0;
}
