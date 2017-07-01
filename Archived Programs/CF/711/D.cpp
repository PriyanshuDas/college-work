#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define ins insert
#define mp make_pair
#define pi2 pair <ll, ll>
#define pi3 pair <ll, pair<ll, ll> >
#define max_n 200001
#define M 1000000007

using namespace std;

/* Solution :
	Find no. of cycles, and no of edges (forming) the cycles
	ans = Prod(Ei) where Ei is the no of edges forming the cycle in ith cycle
*/

ll n;
vector <int> cyc_len;
ll nxt[max_n+1];
int visited[max_n+1];
ll	dep[max_n+1];
void dfs(int node, int c_dep)
{
	if(visited[node] == -1)
	{
		cyc_len.pb(c_dep - dep[node]);
		return;
	}
	visited[node] = -1;
	dep[node] = c_dep;
	if(visited[nxt[node]] != 1)
		dfs(nxt[node], c_dep+1);
	visited[node] = 1;
}

ll expon(ll num, ll p, ll mod)	//(num, pow, mod)
{
	ll pow_arr[64];
	ll tmp = num;
	for(int i = 0; i < 63; i++)
	{
		pow_arr[i] = tmp%mod;
		tmp = (tmp*tmp)%mod;
		//cout << pow_arr[i] << '\t';
	}
	tmp = 1;
	ll tmp2 = 1;
	for(int i = 0; i < 63; i++)
	{
		ll curr = tmp2<<i;
		//pf("@pos %d\t %lld\n", i, (p&curr));
	 	if((p&curr) > 0)
			tmp = (tmp*pow_arr[i])%mod;
	}
	if(tmp < 0)
		tmp += mod;
	return tmp;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		sf("%lld", &nxt[i]);
	}
	memset(visited, 0, sizeof(visited));
	for(int i = 1; i <= n; i++)
	{
		if(visited[i] == 0)
			dfs(i, 0);
	}
	ll ans = 1, tot = 0;
	for(int i = 0; i < cyc_len.size(); i++)
	{
		ll tmp = (expon(2, cyc_len[i], M) - 2)%M;
		//cout << tmp << endl;
		if(tmp < 0)
			tmp += M;
		ans = (ans*tmp)%M;
		tot += cyc_len[i];
	}
	ll tmp = expon(2, n - tot, M);
	ans = (ans*tmp)%M;
	if(cyc_len.size() == 0)
		cout << "0";
	else
		cout << ans;
	return 0;
}
