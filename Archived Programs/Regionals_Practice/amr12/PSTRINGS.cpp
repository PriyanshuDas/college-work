#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ins insert
#define ull unsigned ll
#define p_max 410
#define m_max 2048
#define MOD 1000000007
#define k_max 10

using namespace std;

int N, K;
ull memo[410][m_max];
int cl_mask;

void give_bool(int n)
{
	cout << n << " : ";
	for(int i = 10; i >= 0; i--)
	{
		if((1<<i)&n)
			pf("1");
		else
			pf("0");
	}
	cout << endl;
}

bool not_pal(int n, int K)
{
	//pf("For %d\n", n);
	for(int i = 0; i < K; i++)
	{
		if((((1<<i)&n) == 0 && ((1<<(K-1-i))&n) != 0) || (((1<<i)&n) != 0 && ((1<<(K-1-i))&n) == 0))
			return true;
	}
	return false;
}

ull dp(int pos, int mask)
{
	int new_mask = mask;
	if(pos == N)
		return 1;
	
	if(memo[pos][mask] != -1)
		return memo[pos][mask];
	
	//pf("@ %d\t", pos);	give_bool(mask);	pf("\n");
	
	new_mask = (mask<<1)&cl_mask; 
	
	//pf("New mask : ");	give_bool(new_mask);
	
	ull ans = 0;
	if((not_pal(new_mask, K) || pos < K-1) && (not_pal(new_mask, K-1) || pos < K-2))
		ans = (ans + dp(pos+1, new_mask))%MOD;
	
	if((not_pal(new_mask|1, K) || pos < K-1) && (not_pal(new_mask|1, K-1) || pos < K-2))
		ans = (ans + dp(pos+1, (new_mask|1)))%MOD;
	memo[pos][mask] = ans;
	return ans;
}

int main()
{
	int T;	sf("%d", &T);
	
	for(int t = 0; t < T; t++)
	{
		sf("%d%d", &N, &K);
		K++;
		cl_mask = 0;
		for(int i = 0; i < K; i++)
		{
			cl_mask |= (1<<i);
		}
		memset(memo, -1, sizeof(memo));
		ll ans = dp(0, 0);
		cout << ans << endl;
	}
	return 0;
}
