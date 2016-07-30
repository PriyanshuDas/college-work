#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert

using namespace std;
vector <int> a;
vector<pair<int, int> > b;
int total = 0;
int n;
int mem[101][101];
void dp(int pos, int ct, int tot)
{

}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;    cin >> tmp;
        a.pb(tmp);
        total += tmp;
    }
    vector<pair <int, int> > ans;
    int req = 2*total/n;
    int taken[101] = {0};
    for(int i = 0; i < n; i++)
    {
        if(taken[i] == 1)
            continue;
        int curr = a[i];
        taken[i] = 1;
        for(int j = 0; j < n; j++)
        {
            if(i != j && taken[j] == 0 && curr + a[j] == req)
            {
                taken[j] = 1;
                ans.pb(mp(i+1, j+1));
                break;
            }
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        pf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}
