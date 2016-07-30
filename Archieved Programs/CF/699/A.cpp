#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int N; cin >> N;
    string dir; cin >> dir;
    vector<int> pos;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        sf("%d", &tmp);
        pos.pb(tmp);
    }
    sort(pos.begin(), pos.end());
    ll tim = 9999999999;
    for(int i = 0; i < N-1; i++)
    {
        if(dir[i] == 'R' && dir[i+1] == 'L')
        {
            ll tmp = (pos[i+1] - pos[i])/2;
            i++;
            tim = min(tim, tmp);
        }
    }
    if(tim == 9999999999)
        cout << -1;
    else
        cout << tim;
    return 0;
}
