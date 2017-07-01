#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2>
#define pi4 pair<pi2,pi2>

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int N;	cin >> N;
		vector<int> A, D;
		set<pair<int,int> > S;
		for(int i = 0; i < N; i++)
		{
			int Ax, Dx;
			sf("%d%d", &Ax, &Dx);
			A.pb(Ax);
			D.pb(Dx);
			S.ins(mp(Ax, Dx));
		}
		set<pair<int, int> >::iterator s_it;
		int flag = 0;
		sort(A.begin(), A.end());
		sort(D.begin(), D.end());
		for(int i = A.size()-1; i >= 0; i--)
		{
			int a = A[i], d = D[i];
			s_it = S.find(mp(a, d));
			if(s_it != S.end())
			{
				flag = 1;
			}
			else
			{
				while(i-1 >= 0 && (A[i-1] == A[i] || D[i-1] == D[i]))
				{
					i--;
				}
			}
		}
		if(flag == 1)
		{
			pf("Case #%d: YES\n", t);
		}
		else
			pf("Case #%d: NO\n", t);
	}
	return 0;
}
