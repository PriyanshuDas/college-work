#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define loop(i,l,r) for(int i = l; i < r; i++)
#define N_max 500001

using namespace std;

int N, C;
vector<int> V[N_max];
vector <int> V2[500001];
int l_max = 0;

int main()
{
	cin >> N >> C;
	for(int i = 0; i < N; i++)
	{
		int li;	sf("%d", &li);
		for(int l = 0; l < li; l++)
		{
			int tmp;	sf("%d", &tmp);
			tmp--;
			V[i].pb(tmp);
			V2[i].pb(tmp);
			//cout << tmp << endl;
		}
		l_max = max(li, l_max);
	}
	//cout << l_max << endl;
	ll rot = 0, max_rot = 9999999999;
	for(int i = 1; i < N; i++)
	{
		int c_rot = 0;
		int c_max_rot = 0;
		for(int j = 0; j < V[i].size(); j++)
		{
			V[i][j] = (V2[i][j] + rot)%C;
		}
		for(int j = 0; j < V[i].size(); j++)
		{
			if(V[i-1].size() == j)
			{
				break;
			}
			if(V[i-1][j] == V[i][j])
				continue;
			if(V[i-1][j] > V[i][j])
			{
				c_rot = max(c_rot, C-V[i-1][j]);
			}
		}
		//cout << endl;
		max_rot = min(max_rot, rot + c_max_rot);
		rot = rot + c_rot;
		for(int j = 0; j < V[i].size(); j++)
		{
			V[i][j] = (V2[i][j] + rot)%C;
			//cout << V[i][j] << ' ';
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < V2[i].size(); j++)
		{
			V2[i][j] = (V2[i][j] + rot)%C;
		}
	}
	int flg = 0;
	for(int i = 1; i < N; i++)
	{
		for(int j = 0; j < V2[i].size(); j++)
		{
			if(V2[i-1].size() <= j)
				break;
			if(V2[i-1][j] > V2[i][j])
				flg = 1;
		}
	}
	if(flg == 1)
	{
		cout << -1;
	}
	else
		cout << rot;
	return 0;
}
