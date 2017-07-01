#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define pb push_back
#define mp make_pair


using namespace std;


typedef pair<int,int> PII;

 
int parent[1001] = {0};

int find(int n)
{
	if(parent[n] == n)
		return n;
	parent[n] = find(parent[n]);
	return parent[n];
}

void set_parent(int n1, int n2)
{
	if (parent[n1] == n1)
	{
		parent[n1] = n2;
		return;
	}
	set_parent(parent[n1], n2);
	parent[n1] = n2;
	
}
bool Union(int n1, int n2)
{
	int x = find(n1);
	int y = find(n2);
	printf("Parent of %d is %d\t\tParent of %d is %d\n\n", n1, x, n2, y);
	if (x != y)
	{
		set_parent(n1, parent[n2]);
		parent[n1] = parent[n2];
		return 1;
	}
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		long long int ans = 0;
		int n, ct = 0, m, K, dist[1001][1001] = {0};
		set < pair<int, pair<int, int> > > s;
		char flash;
		scanf("%c", &flash);
		scanf("%d%d%d", &n, &m,&K);
		for(int j = 0; j < 1001; j++)
			parent[j] = j;				//Resetting the Parent Array

		for (int j = 0; j < m; j++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			dist[u][v] = w;
			s.insert(mp(dist[u][v], mp(u,v)));
		}
		set<pair<int, pair<int, int> > >::iterator it= s.begin();
		/*for (it; it != s.end(); it++)
			printf(" %d\n", (*it).first);*/
		for (it; it != s.end(); it++)
		{
			int x = (*it).second.first;
			int y = (*it).second.second;
			int d = (*it).first;
			if(Union (x, y))
			{
				ct++;
				ans += d;
			}
		}
		printf("No of nodes inserted == %d\n", ct);
		if(ct != n-1)
			printf("Case %d: impossible\n", i+1);
		else
			printf("Case %d: %lld\n", i+1, ans);
	}

	return 0;
}
