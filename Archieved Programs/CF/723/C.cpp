#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair <ll, pi2 >
#define pi4 pair<pi2, pi2>
#define loop(l,r) for(int i = l; i < r; i++)
#define ull unsigned long long int

using namespace std;

int main()
{
	int n, m;	cin >> n >> m;
	vector<int> Plist;
	map<int, int> ct;
	set<int> bad;
	map<int, set<int> > good;
	for(int i = 0; i < n; i++)
	{
		int tmp;	cin >> tmp;
		Plist.pb(tmp);
		ct[tmp]++;
		if(tmp > m)
			bad.ins(i);
		else
			good[tmp].ins(i);
	}
	map<int, set<int> > min_s;	//	(no of songs, singer)
	for(int i = 1; i <= m; i++)
	{
		//cout << ct[i] << ' ' << i << endl;
		min_s[ct[i]].ins(i);
	}
	int req = n/m;
	int del = 0;
	int c_m = (min_s.begin())->first;
	//cout << c_m << ' ' << req << endl;
	while(c_m < req)
	{
		del++;
		int c_s = *(min_s.begin()->second.begin());
		int c_ct = c_m;
		//cout << c_s << ' ' << c_ct << endl;
		min_s[c_ct].erase(c_s);
		min_s[c_ct+1].ins(c_s);
		if(min_s[c_ct].size() == 0)
			min_s.erase(c_ct);
		if(bad.size() > 0)
		{
			//cout << c_s << ' ' << c_ct << endl;
			int n_pos = *(bad.begin());
			Plist[n_pos] = c_s;
			bad.erase(bad.begin());
		}
		else
		{
			int n_s = *(min_s.rbegin()->second.begin());
			int n_ct= (min_s.rbegin()->first);
			min_s[n_ct].erase(n_s);
			min_s[n_ct-1].ins(n_s);
			if(min_s[n_ct].size() == 0)
				min_s.erase(n_ct);
			int n_pos= *good[n_s].begin();
			//cout << '\t' << n_s << ' ' << n_ct << ' ' << n_pos << endl;
			Plist[n_pos] = c_s;
			good[n_s].erase(good[n_s].begin());
		}
		c_m = (min_s.begin()->first);
	}
	cout << req << ' ' << del << endl;
	for(int i = 0; i < Plist.size(); i++)
	{
		pf("%d ", Plist[i]);
	}
	return 0;
}
