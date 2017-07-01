#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ins insert
#define n_max 1000001

using namespace std;

typedef vector<int> VI;
typedef vector <VI> VVI;
typedef long long L;
typedef vector <L> VL;
typedef vector <VL> VVL;
typedef pair <int, int> PII;
typedef vector <PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

L ans = INF;

struct MinCostMaxFlow
{
	int N;
	VVL cap, flow, cost;
	VI found;
	VL dist, pi, width;
	VPII dad;
	
	MinCostMaxFlow(int N): N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)), found(N), dist(N), pi(N), width(N), dad(N){}
	
	void addedge(int from, int to, L cap, L cost)
	{
		this -> cap[from][to] = cap;
		this -> cost[from][to] = cost;
	}
	
	void Relax(int s, int k, L cap, L cost, int dir)
	{
		L val = dist[s] + pi[s] - pi[k] + cost;
		if(cap && (val < dist[k]))
		{
			dist[k] = val;
			dad[k] = make_pair(s,dir);
			width[k] = min(cap,width[s]);
		}
	}
	
	L Dkstra(int s, int t)
	{
		fill(found.begin(), found.end(), false);
		fill(dist.begin(), dist.end(), INF);
		fill(width.begin(), width.end(),0);
		dist[s] = 0;
		width[s] = INF;
		
		while(s != -1)
		{
			int best = -1;
			found[s] = true;
			for(int k=0;k<N;k++)
			{
				if(found[k])
					continue;
					
				Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
				Relax(s, k, flow[k][s], -cost[k][s], -1);
				if(best == -1 || (dist[k] < dist[best]))
					best = k;
			}
			s = best;
		}
		for(int k =0;k<N;k++)
			pi[k] = min(pi[k] + dist[k], INF);
			
		return width[t];
	}
	
	pair <L, L> GetMaxFlow(int s, int t)
	{
		L totflow = 0, totcost = 0;
		while(L amt = Dkstra(s,t))
		{
			totflow += amt;
			for(int x = t; x != s; x = dad[x].first)
			{
				if(dad[x].second == 1)
				{
					flow[dad[x].first][x] += amt;
					totcost += amt * cost[dad[x].first][x];
					if( amt * cost[dad[x].first][x] > 0)
					ans = min(ans, amt * cost[dad[x].first][x]);
				}
				else
				{
					flow[x][dad[x].first] -= amt;
					totcost -= amt * cost[x][dad[x].first];
				}
			}
		}
		return mp(totflow, totcost);
	}
	
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ans = INF;
		L n,m,k,c,a;
		cin>>n>>m>>k>>c;
		MinCostMaxFlow mcmf(n+m+m+10);
		int source,sink,source1;
		
		source=n+m+m+3;
		source1=source+1;
		sink=source+2;
		
		//hob to first hole
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a;
				mcmf.addedge(i,n+j,1,a);
			}
		}
		
		//hole to hole2 and hole to sink and hole2 to sink
		for(int j=0;j<m;j++)
		{
			mcmf.addedge(n+j,sink,1,0);
			
			mcmf.addedge(n+j,n+m+j,1,c);
			
			mcmf.addedge(m+n+j,sink,1,0);
		}
		
		//source1 to j
		for(int j=0;j<n;j++)
		{
			mcmf.addedge(source1,j,1,0);
		}
		
		//source to source1
		mcmf.addedge(source,source1,k,0);
		
		pair<L,L> res=mcmf.GetMaxFlow(source,sink);
		cout<<ans<<endl;
	}	
	return 0;
}


