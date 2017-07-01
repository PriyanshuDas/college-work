#include<bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define ins insert
#define pb push_back
#define mp make_pair
#define max_pos 100001
#define max_par 501
#define INF 100000000
#define MAX_N 110
using namespace std;

int cap[MAX_N][MAX_N];
int flowp[MAX_N][MAX_N];
vector <int> adj[MAX_N];
int parent[MAX_N];
int cpc[MAX_N];

int bfs(int source, int sink)
{
	memset(parent, -1, sizeof(parent));
	memset(cpc, 0, sizeof(cpc));
	queue <int> q;
	q.push(source);
	cpc[source] = INF;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(int i=0;i<adj[cur].size();i++)
		{
			int to = adj[cur][i];
			if(parent[to] == -1)
			{
				if(cap[cur][to] - flowp[cur][to] > 0 )
				{
					parent[to] = cur;
					cpc[to] = min(cpc[cur], cap[cur][to] - flowp[cur][to]);
					if(to==sink)
						return cpc[sink];
						
					q.push(to);
				}
			}
		}
	}
	return 0;
}

int findflow(int source, int sink)
{
	int maxflow=0;
	while(true)
	{
		
		int flow = bfs(source, sink);
		//cout<<flow<<endl;
		if(flow == 0)
		{
			break;
		}
		maxflow += flow;
		int cur = sink;
		while(cur != source)
		{
			int prev = parent[cur];
			flowp[prev][cur] += flow;
			flowp[cur][prev] -= flow;
			cur = prev;
		}
	}
	return maxflow;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int suma=0,sumb=0,a,b,from,to,capa;
		int n,v,w,src=105,dest=106;
		cin>>n>>v>>w;
		
		int id[n+1],od[n+1],m1[n+1],m2[n+1];
		memset(id,0,sizeof id);
		memset(od,0,sizeof id);
		memset(m1,0,sizeof id);
		memset(m2,0,sizeof id);
		vector<int>vv[n+1],ww[n+1];
		
		for(int i=0;i<v;i++)
		{
			cin>>a>>b;
			od[a]++,id[b]++;
		}
		
		for(int i=0;i<w;i++)
		{
			cin>>a>>b;
			od[a]++,id[b]++;
			ww[a].pb(b);
		}
		
		for(int i=1;i<=n;i++)
		{
			if(od[i]>id[i])
			{
				m1[i]++;
				capa=od[i]-id[i];
				suma+=capa;
				from=src;
				to=i;
				cap[from][to] = capa;
				adj[from].pb(to);
				adj[to].pb(from);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(id[i]>od[i])
			{
				m2[i]++;
				capa=id[i]-od[i];
				sumb+=capa;
				from=i;
				to=dest;
				cap[from][to] = capa;
				adj[from].pb(to);
				adj[to].pb(from);
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<ww[i].size();j++)
			{
				a=ww[i][j];
				if(m1[i] && m2[a])
				{
					capa=1;
					from=i;
					to=a;
					cap[from][to] = capa;
					adj[from].pb(to);
					adj[to].pb(from);
				}	
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<vv[i].size();j++)
			{
				a=vv[i][j];
				if(m1[i] && m2[a])
				{
					capa=1;
					from=i;
					to=a;
					cap[from][to] = capa;
					adj[from].pb(to);
					adj[to].pb(from);
				}	
			}
		}
		
		
		int maxflow = findflow(src, dest);
		//cout<<99<<endl;
		if( maxflow== suma && suma ==sumb )
		{
			cout<<maxflow<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}	
		memset(cap,0,sizeof cap);
		memset(flowp,0,sizeof flowp);
		for(int i=0;i<n+1;i++)
			adj[i].clear();		
	}
	return 0;
}
