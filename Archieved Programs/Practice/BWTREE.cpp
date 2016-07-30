#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define mod_inv 500000004

using namespace std;

ll fin_ans = 0;
vector <int> graph[100001];
bool color[100001];
ll ans[100001];

void traverse(int curr, int parent)
{
    ll temp = 1;
    for(int i =0; i < graph[curr].size(); i++)
    {
        int nu = graph[curr][i];
        if(nu != parent)
        {
            traverse(nu, curr);
            if(color[nu] != color[curr])
                temp = (temp + ans[nu])%MOD;
        }
    }
    ans[curr] = temp;
}

void traverse2(int curr, int parent)
{
    if(color[parent] != color[curr] && ans[parent] != 0)
    {
        ans[curr] = ans[parent];
    }
    for(int i =0; i < graph[curr].size(); i++)
    {
        int nu = graph[curr][i];
        if(nu != parent)
            traverse2(nu,curr);
    }
    fin_ans = (fin_ans+ans[curr])%MOD;
}

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++)
    {
        int st, en;
        sf("%d%d", &st, &en);
        graph[st].pb(en);
        graph[en].pb(st);
    }
    for(int i = 1; i <= N; i++)
    {
        char col;
        cin >> col;
        if(col == 'W')
            color[i] = 1;
    }
    traverse(1, 0);
    traverse2(1,0);
    fin_ans = (fin_ans + N)%MOD;
    fin_ans = (fin_ans*500000004)%MOD;
    if(fin_ans < 0)
        fin_ans += MOD;
    cout << fin_ans;
    return 0;
}
