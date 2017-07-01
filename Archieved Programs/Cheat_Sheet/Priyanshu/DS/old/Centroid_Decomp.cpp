#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define max_n 100000
#define max_lg 20
#define loop(n) for(int i = 0; i < n; i++)

using namespace std;

typedef struct nod
{
	set<int> conn;
	bool color;					// 0-BLUE,	1-RED
	int size;
} nod;

typedef struct node
{
	bool color;
	int par;
	int lvl, ans, num;
	int dist[17];
} node;

node C_tree[max_n+1];
node *root;
int n, m;
nod arr[max_n+1];
int visited[max_n+1], level[max_n+1], DP[max_lg+1][max_n+1];
//----------------------------------------------------------//
//--------------_Pre_Process_------------------------------//
//dfs_pre(int n), finds and sets lvl of each node in original graph and DP[0][n's child]
//pre_process(), sets DP[logN][N]
//lca() finds lca for two nodes in log(N) time

void dfs_pre(int n)
{
	for(auto it = arr[n].conn.begin(); it != arr[n].conn.end(); it++)
	{
		if(*it != DP[1][n])
		{
			DP[1][*it] = n;
			level[*it] = level[n]+1;
			dfs_pre(*it);
		}
	}
}

void pre_process()
{
	DP[1][1] = 0;
	level[1] = 0;
	dfs_pre(1);
	for(int i = 2; i <= max_lg; i++)
		for(int j = 1; j <= max_n; j++)
			DP[i][j] = DP[i-1][DP[i-1][j]];
}

int lca(int a, int b)		//a is lower level
{
	if(level[a] > level[b])	swap(a, b);
	int diff = level[b] - level[a];
	for(int i = 1; i <= max_lg; i++)
		if(diff&(1<<(i-1)))
			b = DP[i][b];
	if(a==b)
		return a;
	for(int i = max_lg; i > 0; i--)
		if(DP[i][a] != DP[i][b])
		{
			a = DP[i][a];
			b = DP[i][b];
		}
	return DP[1][a];
}

int distance(int u, int v)
{
	return level[u] + level[v] - 2*level[lca(u, v)];
}

//---------------------------------------------------------//
//--------------DECOMPOSITION-----------------------------//

//dfs_size(int n, int p) finds the size of node n
//dfs_centr(int n, int p) finds the centroid starting from node n
//decompose(int n, int p) decomposes n, if p is the parent centroid

int n_nodes;	//number of nodes

void dfs_size(int n, int p)
{
	arr[n].size = 1;
	n_nodes++;
	for(auto it = arr[n].conn.begin(); it != arr[n].conn.end(); it++)
	{
		if(*it != p)
		{
			dfs_size(*it, n);
			arr[n].size += arr[*it].size;
		}
	}
}

int dist;

int dfs_centr(int n, int p)
{
	dist++;
	for(auto it = arr[n].conn.begin(); it != arr[n].conn.end(); it++)
	{
		if(*it != p && arr[*it].size > n_nodes/2)
		{
			return dfs_centr(*it, n);
		}
	}
	return n;
}

void decompose(int n, int p)
{
	n_nodes = 0;
	dist = 0;
	dfs_size(n,n);
	int centroid = dfs_centr(n,n);
	//cout << "Centroid == " << centroid << '\t' << "Dist == " << dist <<endl;
	memset(C_tree[centroid].dist, 0, sizeof(C_tree[centroid].dist));
	if(p == -1)
	{
		p = centroid;
		C_tree[centroid].lvl = 0;
		C_tree[centroid].dist[C_tree[centroid].lvl] = 0;
	}
	else
	{
		C_tree[centroid].lvl = C_tree[p].lvl+1;
		C_tree[centroid].dist[C_tree[centroid].lvl] = 0;
		for(int lv = C_tree[p].lvl; lv >= 0; lv--)
		{
			C_tree[centroid].dist[lv] = C_tree[p].dist[lv] + dist;
		}
	}
	C_tree[centroid].par = p;
	for(auto it = arr[centroid].conn.begin(); it != arr[centroid].conn.end(); it++)
	{
		arr[*it].conn.erase(centroid);
		decompose(*it, centroid);
	}
	arr[n].conn.clear();
}
 //------------------------------------------------------------//
//---------------_UPDATE_AND_QUERY_---------------------------//

void update(int n)
{
	int tmp = n;
	C_tree[n].ans = 0;
	while(1)
	{
		C_tree[tmp].ans = min(C_tree[tmp].ans, distance(n, tmp));
		if(C_tree[tmp].lvl == 0)
			break;
		tmp = C_tree[tmp].par;
	}
}

int query(int n)
{
	int tmp = n;
	int curr_ans = C_tree[n].ans;
	while(1)
	{
		curr_ans = min(curr_ans, distance(n, tmp) + C_tree[tmp].ans);
		if(C_tree[tmp].lvl == 0)
			break;
		tmp = C_tree[tmp].par;
	}
	return curr_ans;
}

/*-------------------------------------------------//
//---------------_DEBUG_---------------------------//

void traverse(int pos, int prev)
{
	pf("\n========= NoD =========\n");
	cout << "Number == " << pos << endl;
	cout << "Color == " << arr[pos].color<<endl;
	cout << "Size == " << arr[pos].size<<endl;
    set<int>:: iterator it;
	for(it = arr[pos].conn.begin(); it != arr[pos].conn.end(); it++)
	{
		if(*it != prev)
			traverse(*it, pos);
	}
}

//-------------------------------------------------//*/
int main()
{
	memset(visited, 0, sizeof(visited));
	sf("%d %d", &n, &m);
	loop(n-1)
	{
		int n1, n2;
		sf("%d %d", &n1, &n2);
		arr[n1].conn.insert(n2);
		arr[n1].color = 0;	arr[n1].size = 0;
		arr[n2].conn.insert(n1);
		arr[n1].color = 0;	arr[n1].size = 0;
	}
	loop(n)
	{
		C_tree[i+1].num = i+1;
	}
	pre_process();
	decompose(1, -1);
	loop(n)
		C_tree[i+1].ans = 99999999;
	
	update(1);
	loop(m)
	{
		int ti, vi;
		sf("%d%d", &ti, &vi);
		if(ti == 1)
			update(vi);
		else
			pf("%d\n", query(vi));
	}	
	return 0;
}
