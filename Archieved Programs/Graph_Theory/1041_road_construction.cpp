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

/*void set_parent(int n1, int n2)
{
	if (parent[n1] == n1)
	{
		parent[n1] = n2;
		return;
	}
	set_parent(parent[n1], n2);
	parent[n1] = n2;
	*/
bool Union(int n1, int n2)
{
	int x = find(n1);
	int y = find(n2);
	//printf("Parent of %d is %d\t\tParent of %d is %d\n\n", n1, x, n2, y);
	if (x != y)
	{
		parent[x] = parent[y];
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
		int m, ct = 0, dist[1001][1001] = {0};
		map<string, int> M;
		set < pair<int, pair<int, int> > > s;
		char flash;
		scanf("%c", &flash);
		scanf("%d",&m);
		for(int j = 0; j < 1001; j++)
			parent[j] = j;				//Resetting the Parent Array
		int ctn = 1;
		for (int j = 0; j < m; j++)
		{
			char u[51], v[51];
			int w;
			scanf("%s%s%d", u, v, &w);
			if (!M[u])
			{
				M[u] = ctn;
				ctn++;
			}
			if (!M[v])
			{
				M[v] = ctn;
				ctn++;
			}
			dist[M[u]][M[v]] = w;	 	
			s.insert(mp(w, mp(M[u],M[v])));
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
		//printf("No.nodes inserted=%d\nNumber of Cities :%d",ct, ctn);
		if(ct != ctn-2)
			printf("Case %d: Impossible\n", i+1);
		else
			printf("Case %d: %lld\n", i+1, ans);
	}

	return 0;
}
