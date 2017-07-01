
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
