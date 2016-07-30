#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pii pair<int, int>
#define pi3 pair<int, pair<int, int> >


using namespace std;

vector<vector<ll> > cases;
double hr, mn;
ll n, m;
int h_dig, m_dig;

void gen_cases(int pos, vector<ll> curr)
{
    if(pos >= ceil(hr) + ceil(mn))
    {
        cases.pb(curr);
        return;
    }
    int visited[7] = {0};
    for(int i = 0; i < curr.size(); i++)
    {
        visited[curr[i]] = 1;
    }
    for(int i = 0; i < 7; i++)
    {
        if(visited[i] == 1)
            continue;
        vector<ll> nu = curr;
        nu.pb(i);
        gen_cases(pos+1, nu);
    }
}

int main()
{
    cin >> n >> m;
    int n1 = n-1, m1 = m-1;
    do
    {
        n1 /= 7;
        hr++;
    }
    while (n1 != 0);
    do
    {
        m1 /= 7;
        mn++;
    }
    while (m1 != 0);
    int h_dig = ceil(hr);
    int m_dig = ceil(mn);
    if(ceil(hr)+ceil(mn) > 7)
        cout << 0;
    else
    {
        ll ct = 0;
        vector<ll> tmp;
        gen_cases(0, tmp);
        for(int i = 0; i < cases.size(); i++)
        {
            ll H = 0, M = 0, H7 = 0, M7 = 0, j;
            for(j = 0; j < hr; j++)
            {
                H7 = H*10 + cases[i][j];
                H = H*7 + cases[i][j];
            }
            for(j; j < cases[i].size(); j++)
            {
                M7 = M*10 + cases[i][j];
                M = M*7 + cases[i][j];
            }
            if(H < n && M < m && (H*m + M) < n*m)
            {
                //pf("%lld : %lld\n", H7, M7);
                ct++;
            }
        }
        cout << ct;
    }
    return 0;
}
