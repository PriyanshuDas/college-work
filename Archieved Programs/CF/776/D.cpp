#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define MAXN 1000000
#define SIZE (2*MAXN + 1)
using namespace std;

typedef vector <int> vi;

// Assuming vertices are labeled 1...V
vi G[SIZE], Grev[SIZE];
bool explored[SIZE];
int leader[SIZE], finish[SIZE], order[SIZE], t = 0, parent = 0;
map <int, bool> truthAssignment;

// running DFS on the reverse graph
void dfs_reverse(int i) {
    explored[i] = true;
    for(vi::iterator it = Grev[i].begin(); it != Grev[i].end(); it++)
        if(!explored[*it])
            dfs_reverse(*it);
    t++;
    finish[i] = t;
}

// running DFS on the actual graph
void dfs(int i) {
    explored[i] = true;
    leader[i] = parent;
    for(vi::iterator it = G[i].begin(); it != G[i].end(); it++)
        if(!explored[*it])
            dfs(*it);
}

// check if u & v are in the same connected component
bool stronglyConnected(int u, int v)    {
    return leader[u] == leader[v];
}

int main()  {
    int i, u, v, N, M;
    // N is the number of variables and M is the number of clauses

    // n rooms, m keys
    int n, m;   sf("%d%d", &n, &m);
    vector <int> state;

    for(int i = 0; i < n; i++)
    {
        int st; sf("%d", &st);
        state.pb(st);
    }

    N = m;
    vector <int> Keys[n+1];
    for(int i = 1; i <= m; i++)
    {
        int xi; sf("%d", &xi);
        for(int j = 0; j < xi; j++)
        {
            int rm; sf("%d", &rm);
            Keys[rm-1].pb(i);
        }
    }

    vector <pair<int, int> > Clauses;
    for(int i = 0; i < n; i++)
    {
        if(state[i] == 0)
        {
            Clauses.pb(mp(Keys[i][0], Keys[i][1]));
            Clauses.pb(mp(-1*Keys[i][0], -1*Keys[i][1]));
        }
        else
        {
            Clauses.pb(mp(Keys[i][0], -1*Keys[i][1]));
            Clauses.pb(mp(-1*Keys[i][0], Keys[i][1]));
        }
    }
    //M clauses
    M = Clauses.size();
    for(i=0; i<M; i++)  
    {
        u = Clauses[i].first;
        v = Clauses[i].second;
                                 /*  Each clause is of the form u or v
                                    1 <= x <= N for an uncomplemented variable x
                                    -N <= x <= -1 for a complemented variable x
                                    -x is the complement of a variable x
                                */

    // Internally, complement of variable x is represented as N + x.
        if(u > 0)   {
            if(v > 0)   {
                G[N+u].push_back(v); G[N+v].push_back(u);
                Grev[v].push_back(N+u); Grev[u].push_back(N+v);
            } else  {
                G[N+u].push_back(N-v); G[-v].push_back(u);
                Grev[N-v].push_back(N+u); Grev[u].push_back(-v);
            }
        } else  {
            if(v > 0)   {
                G[-u].push_back(v); G[N+v].push_back(N-u);
                Grev[v].push_back(-u); Grev[N-u].push_back(N+v);
            } else  {
                G[-u].push_back(N-v); G[-v].push_back(N-u);
                Grev[N-v].push_back(-u); Grev[N-u].push_back(-v);
            }
        }
    }

    memset(explored, false, (2*N + 1)*sizeof(bool));
    for(i=2*N; i>0; i--)  {
        if(!explored[i])
            dfs_reverse(i);
        order[finish[i]] = i;
    }

    memset(explored, false, (2*N + 1)*sizeof(bool));
    for(i=2*N; i>0; i--)
        if(!explored[order[i]]) {
            parent = order[i];
            dfs(order[i]);
        }
    for(i=2*N; i>0; i--)   {
        u = order[i];
        if(u > N)   {
            if(stronglyConnected(u, u-N)) break;
            if(truthAssignment.find(leader[u]) == truthAssignment.end())    {
                truthAssignment[leader[u]] = true;
                truthAssignment[leader[u-N]] = false;
            }
        } else {
            if(stronglyConnected(u, N+u)) break;
            if(truthAssignment.find(leader[u]) == truthAssignment.end())    {
                truthAssignment[leader[u]] = true;
                truthAssignment[leader[N+u]] = false;
            }
        }
    }

    if(i > 0)
        printf("NO\n");
    else    {
        printf("YES\n");
    }

    return 0;
}