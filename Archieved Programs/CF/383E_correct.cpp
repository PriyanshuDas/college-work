#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define m_max 16777215
#define n_max 24

using namespace std;

int arr[10001];
int F[m_max+10] = {0};

int main()
{
	int N;	cin >> N;
	int t_mask = 0;
	for(int i = 31; i > 23; i--)
	{
		t_mask = t_mask|(1<<i);
	}
	for(int n = 0; n < N; n++)
	{
		string s;
		cin >> s;
		int mask = 0;
		for(int i = 0; i < s.size(); i++)
		{
			mask = mask|((1<<(s[i]-'a')));
		}
		arr[n] = mask;
		//cout << arr[n] << endl;
		F[arr[n]]++;
	}
	for(int i = 0;i <= n_max; ++i)
		for(int mask = 0; mask < (1<<n_max); ++mask)
		{
			if(mask & (1<<i))
				F[mask] += F[mask^(1<<i)];
		}
	ll ans = 0;
	for(int mask = 1; mask <= m_max; mask++)
	{
		int tmp = (~mask)^t_mask;
		ll a = (N - F[tmp]);
		ans = (ans^(a*a));
	}
	cout << ans;
	return 0;
}
