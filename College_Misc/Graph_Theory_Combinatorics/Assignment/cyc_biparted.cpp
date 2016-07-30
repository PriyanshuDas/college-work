/*------------------ Check for Cycles and Bipartiteness of Graph----*/


#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define max_s 100000

using namespace std;
vector<int> conn[max_s];
int cyc = 0, not_bipart = 0;
int color[max_s];
int visited[max_s];

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges in the graph : ";
    cin >> n >> m;
    cout << "Enter (a b) if a -> b is edge :\n";
    for(int i = 0; i < m; i++)
    {
        int a, b;
        sf("%d%d", &a, &b);
        conn[a].pb(b);
    }
    queue<pair<int, pair<int, int> > > Q;
    Q.push(mp(0, mp(0,0)));
    memset(color, -1, sizeof(color));
    memset(visited, 0, sizeof(visited));
    while(!Q.empty())
    {
        int curr = Q.front().first;
        int dist = Q.front().second.first;
        int colr = Q.front().second.second;
        color[curr] = colr;
        visited[curr] = 1;
        cout << "Processing Node #"<<curr <<endl;
        cout << "Color : "<< color[curr] << endl;
        Q.pop();
        for(int i = 0; i < conn[curr].size(); i++)
        {
            //cout << "Yay";
            int next = conn[curr][i];
            if(visited[next])
            {
                cyc = 1;
                if(color[next] == colr)
                    not_bipart = 1;
            }
            else
            {
                int nexc = colr;
                if(nexc)    nexc = 0;
                else    nexc = 1;
                Q.push(mp(next, mp(dist+1, nexc)));
            }
        }
    }
    if(cyc)
        cout << "Cycle Exists in the graph!\n";
    else
        cout << "No Cycle Exists in the graph!\n";
    if(!not_bipart)
        cout << "Graph is Bipartite!\n";
    else
        cout << "Graph is not Bipartite!\n";
    return 0;
}
