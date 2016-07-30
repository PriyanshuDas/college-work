#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define max_l 1000000000

using namespace std;

vector <int> ans;
ll n, m;

int main()
{
    cin >> n >> m;
    vector<int> toy;
    for(int i = 0; i < n; i++)
    {
        int tmp;    sf("%d", &tmp);
        toy.pb(tmp);
    }
    toy.pb(0);
    sort(toy.begin(), toy.end());
    int ct = 0, flag = 0;
    for(int i = 1; i < toy.size() && flag == 0; i++)
    {
        for(int j = toy[i-1]+1; j < toy[i]; j++)
        {
            if(m < j)
            {
                flag = 1;
                break;
            }
            else
            {
                m -= j;
                ans.pb(j);
            }
        }
    }
    if(!flag)
    {
        for(int j = toy[toy.size()-1]+1; j < max_l && flag == 0; j++)
        {
            if(m < j)
            {
                flag = 1;
                break;
            }
            else
            {
                m -= j;
                ans.pb(j);
            }
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
    {
        pf("%d", ans[i]);
        if(i != ans.size() - 1)
            pf(" ");
    }
    cout << endl;
    return 0;
}
