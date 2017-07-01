#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define ull unsigned ll
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2>
#define pi4 pair<pi2, pi2>

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int N;	sf("%d", &N);
		int vis[N+1];
		vector <int> chap;
		int flag = 0;
		for(int i = 0; i <= N; i++)
			vis[i] = 0;
		for(int i = 0; i < N; i++)
		{
			int tmp;	sf("%d", &tmp);
			if(tmp > N || vis[tmp] != 0)
			{
				flag = 1;
			}
			if(tmp <= N)
				vis[tmp]++;
			chap.pb(tmp);
		}
		int flag2 = 1;
		for(int i = 1; i < chap.size(); i++)
		{
			if(chap[i] != chap[i-1]+1)
				flag2 = 0;
		}
		if(flag == 0 && flag2 == 0)
			pf("yes\n");
		else
			pf("no\n");
	}
	return 0;
}
