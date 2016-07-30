#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;
vector<pair<int, string> > region[10001];
vector<string> ans_reg[10001];
bool found[100001];

int main()
{
    int n, m;   cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string s;   int reg, rat;
        cin >> s >> reg >> rat;
        region[reg].pb(mp(rat, s));
    }
    for(int i = 1; i <= m; i++)
    {
        sort(region[i].rbegin(), region[i].rend());
        int flag = 0, r1 = 0, r2 = 0;
        for(int j = 0; j < 3 && j < region[i].size(); j++)
        {
            int curr = region[i][j].first;
            if(curr >= r2)
            {
                flag++;
                if(curr > r1)
                {
                    r2 = r1;    r1 = curr;
                }
                else
                {
                    r2 = curr;
                }
            }
        }
        if(flag == 2)
        {
            ans_reg[i].pb(region[i][0].second);
            ans_reg[i].pb(region[i][1].second);
        }
        else
        {
            ans_reg[i].pb("?");
        }
        //pf("For Region %d, Flag == %d\n", i, flag);
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j < ans_reg[i].size(); j++)
        {
            cout << ans_reg[i][j];
            if(j != ans_reg[i].size() - 1)
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
