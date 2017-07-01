#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define ins insert

#define NMax 400000000001
using namespace std;

vector<int> addj[200010]; // declare the space needed 
ll vis[200010],aval[200010], bval[200010], abval[200010]; // SIZE

void dfs(int a)
	{
		int next;
		vis[a]=-1;
		for (int i = 0; i < addj[a].size(); ++i)
		{	
			next=addj[a][i];
			if(vis[next]==-1) 
				continue;
				
			else if (vis[next]==0)
			{
				dfs(next);
			}
			aval[a]=min(aval[a],aval[next]+(ll)1);
			bval[a]=min(bval[a],bval[next]+(ll)1);
			abval[a]=min(abval[a],abval[next]+(ll)1);
		}
		abval[a]=min(abval[a],aval[a]+bval[a]);
		aval[a] = min((ll)NMax, aval[a]);
		bval[a] = min((ll)NMax, bval[a]);
		abval[a]= min((ll)NMax, abval[a]);
		vis[a]=1;
		//pf("@(%d)\t(%lld\t%lld\t%lld\n", a, aval[a], bval[a], abval[a]);
	}
	
int main()
{
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	int y,u;
	
	for(int i=0;i<n+1;i++)
	{
		vis[i] = 0;
		bval[i]=NMax;
		aval[i]=NMax;
		abval[i]=NMax;
	}
	aval[a]=0;
	bval[b]=0;
	for(int i=0;i<m;i++)
	{
		cin>>y>>u;
		addj[y].pb(u);
	}
	ll ans = NMax;
	for(int i = 0; i <= n; i++)
	{
		if(vis[i] == 0)
		{
			dfs(i);
			if(i != 0)
				ans = min(ans, abval[i]+1);
			else
				ans = min(ans, abval[i]);
				
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
