#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define ins insert
#define mp make_pair
#define pi2 pair <ll, ll>
#define pi3 pair <ll, pair<ll, ll> >
#define n_max 501

using namespace std;

int main()
{
	int N;	cin >> N;
	ll mat[n_max][n_max] = {0};
	ll r, c;	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			sf("%lld", &mat[i][j]);
			if(mat[i][j] == 0)
			{
				r = i;	c = j;
			}
		}
	}
	ll tot = 0;
	int flag = 0;
	for(int i = 0; i < N; i++)
	{
		if(i == r)
			continue;
		ll curr = 0;
		for(int j = 0; j < N; j++)
		{
			curr += mat[i][j];
		}
		if(tot == 0)
			tot = curr;
		if(tot != 0 && curr != tot)
			flag = 1;
	}
	ll r_tot = 0;
	for(int j = 0; j < N; j++)
	{
		r_tot += mat[r][j];
	}
	mat[r][c] = tot - r_tot;
	ll c_tot = 0;
	for(int i = 0; i < N; i++)
		c_tot += mat[i][c];
	
	if(c_tot != tot)
		flag = 1; 
		
	ll tot_l_r = 0;
	for(int i = 0; i < N; i++)
	{
		tot_l_r += mat[i][i];
	}
	
	ll tot_r_l = 0;
	for(int i = 0; i < N; i++)
	{
		tot_r_l += mat[i][N-1-i];
	}
	
	if(tot_r_l != tot || tot_l_r != tot)
		flag = 1;
	if(mat[r][c] == 0)
	{
		flag = 1;
	}
	if(flag == 1 && N != 1)
	{
		cout << "-1";
	}
	else
	{
		if(N == 1)
			cout << "1";
		else
		{
			pf("%lld", mat[r][c]);
		}
	}
	return 0;
}
