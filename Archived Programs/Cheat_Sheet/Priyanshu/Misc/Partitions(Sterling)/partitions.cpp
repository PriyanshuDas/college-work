#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

ll S_N[101][101];
int n, l;
vector<set<int> > union_q[11];

ll Stirling(int N, int K)
{
    //cout << "AA\n";
    if(S_N[N][K] != -1)
    {
        return S_N[N][K];
    }
    if(N == 0 && K == 0)
        return 1;
    if(K == 0 || N == 0)
        return 0;
    S_N[N][K] = K*Stirling(N-1, K) + Stirling(N-1, K-1);
    return S_N[N][K];
}

void Union (int no)
{

    //cout << "AA\t" << no << endl;
    for(int i = no; i - no < union_q[no-1].size()-1; i++)
    {
        set<int> tmp = union_q[no-1][i-no];
        //cout << "Insertion Begins!\n";
        if (union_q[1][i-1].size() > 0)
            tmp.insert(union_q[1][i-1].begin(), union_q[1][i-1].end());
        //cout << "Insertion Ends!\n";
        union_q[no].pb(tmp);
    }
}


int main()
{
    memset(S_N, -1, sizeof(S_N));
    cin >> n >> l;
    for(int i = 0; i < l; i++)
    {
        int m;  cin >> m;
        set<int> tmp;
        for(int j = 0; j < m; j++)
        {
            int x;  cin >> x;
            tmp.insert(x);
        }
        union_q[1].pb(tmp);
    }
    for(int i = 2; i <= l; i++)
        Union(i);
    for(int i = 1; i <= l; i++)
    {
        cout << "Union of " << i << " elements : ";
        for(int j = 0; j < union_q[i].size(); j++)
        {
            set<int>::iterator it = union_q[i][j].begin();
            cout << "{";
            for(it = union_q[i][j].begin(); it != union_q[i][j].end(); it++)
            {
                cout << *it << ' ';
            }
            cout << "}\t";
        }
        cout << endl;
    }
    //cout << "BAKA!\n";
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ll tmp = Stirling(n, i);
        //pf("Stirling[%d][%d] == %lld\n",n, i, tmp);
        ans += Stirling(n, i);
    }
    cout << "Starting Value : " << ans << endl;
    for(int i = 1; i <= l; i++)
    {
        for(int j = 0; j < union_q[i].size(); j++)
        {
            int k = (union_q[i][j]).size();
            ll tmp = 0;
            for(int m = 1; m <= n-k; m++)
                tmp += (m+1)*(Stirling(n-k, m));
            pf("For (%d, %d), the value is : %lld\n", i, j, tmp);
            if(i%2 == 1)
                ans -= tmp;
            else
                ans += tmp;
        }
    }
    cout << ans;
    return 0;
}
