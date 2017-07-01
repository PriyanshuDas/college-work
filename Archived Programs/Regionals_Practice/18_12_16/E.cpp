#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back

using namespace std ;
int vis1[100010],vis0[100010],ans1,ans0,p1[100010],p0[100010];
vector<int>g[100010];
void dfs1(int cur,int state)
{
	vis1[cur]=1;
	if(state==1)
	{
		ans1++;
		p1[cur]=1;
	}
	int a;
	for(int i=0;i<g[cur].size();i++)
	{
		a=g[cur][i];
		if(vis1[a])
		continue;
		dfs1(a,!state);
	}
}
void dfs0(int cur,int state)
{
	vis0[cur]=1;
	if(state==1)
	{
		ans0++;
		p0[cur]=1;
	}
	int a;
	for(int i=0;i<g[cur].size();i++)
	{
		a=g[cur][i];
		if(vis0[a])
		continue;
		dfs0(a,!state);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,a,b;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			g[a].pb(b);
			g[b].pb(a);
		}
		ans1=0;
		ans0=0;
		for(int i=1;i<=n;i++)
		{
			if(vis1[i]==0)
			{
				dfs0(i,0);
				dfs1(i,1);
			}
		}				
		
		if(ans1<ans0)
		{
			swap(ans1,ans0);
			swap(p1,p0);
		}
		pf("%d\n",ans0);
		for(int i=1;i<=n;i++)
		{
			if(p0[i])
			printf("%d ",i);
		}
		pf("\n");
		for(int i=0;i<=n;i++)
		g[i].clear();
		memset(vis1,0,((sizeof (int))*(n+1)));
		memset(vis0,0,((sizeof (int))*(n+1)));
		memset(p1,0,((sizeof (int))*(n+1)));
		memset(p0,0,((sizeof (int))*(n+1)));
	}
	return 0;
}
