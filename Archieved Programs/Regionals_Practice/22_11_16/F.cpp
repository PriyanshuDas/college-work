#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back
#define MAX_NODES 510
#define INF 2147483646
#define UNINITIALIZED -1

using namespace std;
int capacities[MAX_NODES][MAX_NODES];
int flowPassed[MAX_NODES][MAX_NODES];
vector<int >graph[MAX_NODES];
int currentPathCapacity[MAX_NODES];
int parentsList[MAX_NODES];

int bfs(int startNode,int endNode)
{
	memset(parentsList,UNINITIALIZED,sizeof parentsList);
	memset(currentPathCapacity,0,sizeof currentPathCapacity);
	queue<int>q;
	q.push(startNode);
	parentsList[startNode]=-2;
	currentPathCapacity[startNode]=INF;
	while(!q.empty())
	{
		int currentNode = q.front();q.pop();
		for(int i=0;i<graph[currentNode].size();i++)
		{
			int to=graph[currentNode][i];
			if(parentsList[to]==-1)
			{
				if(capacities[currentNode][to]-flowPassed[currentNode][to]>0)
				{
					parentsList[to]=currentNode;
					currentPathCapacity[to]=min(currentPathCapacity[currentNode],capacities[currentNode][to]-flowPassed[currentNode][to]);
					if(to == endNode)
					return currentPathCapacity[endNode];
					q.push(to);
				}
			}
		}
	}
	return 0;
}
int edmondsKarp(int startNode , int endNode)
{
	int maxFlow=0;
	while(true)
	{
		int flow=bfs(startNode,endNode);
		if(flow==0)
		break;
		maxFlow+=flow;
		int currentNode=endNode;
		while(currentNode!=startNode)
		{
			int previousNode = parentsList[currentNode];
			flowPassed[previousNode][currentNode]+=flow;
			flowPassed[currentNode][previousNode]-=flow;
			currentNode=previousNode;
				
		}
	}
	return maxFlow;
}
int main()
{
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		int h,g,k,a,b;
		ll c;
		
		memset(capacities,0,sizeof capacities);
		memset(flowPassed,0,sizeof flowPassed);
		cin>>h>>g>>k>>c;
		pair<int,int> p[h],q[g];
		int source=504,sink=505;
		for(int i=0;i<h;i++)
		{
			cin>>a>>b;
			p[i]=mp(a,b);
			capacities[source][i]=1;
			graph[source].pb(i);
			graph[i].pb(source);
		}
		for(int i=0;i<g;i++)
		{
			cin>>a>>b;
			q[i]=mp(a,b);
			capacities[i+h][sink]=1;
			graph[sink].pb(i+h);
			graph[i+h].pb(sink);
		}
		int tma,from,to;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<g;j++)
			{
				tma=0;
				tma=abs(p[i].first-q[j].first)+abs(p[i].second - q[j].second);
				tma+=abs(q[j].first-k)+abs(q[j].second - k);
				if(tma>c)
				continue;
				
				from=i;
				to=h+j;
				capacities[from][to]=1;
				graph[from].pb(to);
				graph[to].pb(from);
			}	
		}
		int ans=edmondsKarp(source,sink);
		for(int i=0;i<510;i++)
		graph[i].clear();
		pf("Case %d: %d\n",tt,ans);
	}
	return 0;
}
