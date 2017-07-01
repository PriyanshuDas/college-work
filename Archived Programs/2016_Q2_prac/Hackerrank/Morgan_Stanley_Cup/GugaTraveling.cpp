#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define INF 9999999

using namespace std;

/*  1 <= N <= 1000
    1 <= M <= 2000
    1 <= K <= 10

Key Idea :- Since K is maximum 10, we can use Dijkstra on 'relevant'
            nodes, i.e 1, n and ends of 'special' paths
            -> 22 Dijkstra's needed.
            -> O(22*(3000)) in worst -> 66,000, which is easy

            Now, we need to order the 10 paths, 10! different ways.
            Also, in a given ordering, for the given path, we need to
            find out which of the two ends to enter and exit from.
            There are 4 ways to do this, for each path.
            -> Total = 10!*(4*10) ~~ 1.5 * 10^(8)

            Therefore this solution should ideally work.*/

int N, M, K;
ll m_time[1001][1001] = {0};    //Dijkstra's
ll dist[1001][1001] = {0};
ll sp_dist[1001][1001]={0};

vector<pair<int, int> > special;
vector<int> perm;
vector<int> adj[1001];

void dijkstra(int src)
{
    set< pair<int, int> > setds;
    vector<int> Dist(N+1, INF);
    setds.insert(make_pair(0, src));
    Dist[src] = 0;
    while (!setds.empty())
    {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        //pf("@%d\n", u);
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            //pf("-%d\n", v);
            int weight = dist[u][v];
            if (Dist[v] > Dist[u] + weight)
            {
                if (Dist[v] != INF)
                    setds.erase(setds.find(make_pair(Dist[v], v)));
                Dist[v] = Dist[u] + weight;
                setds.insert(make_pair(Dist[v], v));
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        m_time[src][i] = Dist[i];
    }
}
ll dijkstra_s()    // For optimal way through the maze
{
    int D[perm.size()][2];
    for(int i = 0; i < perm.size(); i++)
    {
        D[i][0] = INF;
        D[i][1] = INF;
    }
    int p1 = 1, p2 = 1;
    for(int i = 0; i < perm.size(); i++)
    {
        int c1 = special[perm[i]].first;
        int c2 = special[perm[i]].second;
        ll r = sp_dist[c1][c2];
        //end at city 1
        ll a1 = m_time[p1][c1]+2*r, a2 = m_time[p1][c2]+r;
        ll a3 = m_time[p2][c1]+2*r, a4 = m_time[p2][c2]+r;
        ll b1 = m_time[p1][c1]+r, b2 = m_time[p1][c2]+2*r;
        ll b3 = m_time[p2][c1]+r, b4 = m_time[p2][c2]+2*r;
        if(i > 0)
        {
            a1 += D[i-1][0];    a2 += D[i-1][0];
            a3 += D[i-1][1];    a4 += D[i-1][1];
            b1 += D[i-1][0];    b2 += D[i-1][0];
            b3 += D[i-1][1];    b4 += D[i-1][1];
        }
        D[i][0] = min(min(a1, a2), min(a3, a4));
        D[i][1] = min(min(b1, b2), min(b3, b4));
        p1 = c1;    p2 = c2;
    }
    ll ans1 = D[perm.size()-1][0] + m_time[special[perm[perm.size()-1]].first][N];
    ll ans2 = D[perm.size()-1][1] + m_time[special[perm[perm.size()-1]].second][N];
    ll ans = min(ans1,ans2);
    return ans;
}

int main()
{
    memset(m_time, -1, sizeof(m_time));
    memset(dist, -1, sizeof(dist));
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++)
    {
        int x, y, z;    cin >> x >> y >> z;
        adj[x].pb(y);
        adj[y].pb(x);
        dist[x][y] = z;
        dist[y][x] = z;
    }
    for(int i = 0; i < K; i++)
    {
        int x, y, z;    cin >> x >> y >> z;
        if(dist[x][y] == -1 || z < dist[x][y])
        {
            adj[x].pb(y);
            adj[y].pb(x);
            dist[x][y] = z;
            dist[y][x] = z;
        }
        special.pb(mp(x, y));
        sp_dist[x][y] = z;
        sp_dist[y][x] = z;
    }
    dijkstra(1);
    /*for(int i = 1; i <= N; i++)
    {
        pf("(%d, %d) == %lld\n", 1, i, m_time[1][i]);
    }*/
    for(int i = 0; i < special.size(); i++)
    {
        dijkstra(special[i].first);
        dijkstra(special[i].second);
    }
    for(int i = 0; i < special.size(); i++)
        perm.pb(i);
    int p1 = 1, p2 = 1;
    /*  Deciding incoming and outgoing, directions.
        Will need a Dijkstra? O(50 + 20) Yup.*/
    ll ans = 99999999;
    while(next_permutation(perm.begin(), perm.end()))
    {
        ans = min(ans, dijkstra_s());
    }
    cout << ans;
    return 0;
}
