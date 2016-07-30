#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define loop(n) for(int i = 0; i < n; i++)
#define loop(l,n) for(l; l < n; l++)
#define pi2 pair<int, int>
#define pi3 pair<int, pair<int,int> >
#define pi4 pair<pair<int, int>, pair<int, int> >

using namespace std;

map<ll, int> M;
vector <ll> skills;
vector <ll> required;
int n, m, cf, cm, A;

int main()
{
    cin >> n >> A >> cf >> cm >> m;
    for(int i = 0; i < n; i++)
    {
        ll tmp;
        sf("%lld", &tmp);
        skills.pb(tmp);
    }
    sort(skills.begin(), skills.end());
    for(int i = 0; i < skills.size()/2; i++)
        swap(skills[i], skills[skills.size()-1-i]);
    ll curr_req = 0;
    required.pb(0);
    for(int i = 1; i < skills.size(); i++)
    {
        curr_req = (i)*(skills[i]-skills[i-1]);
        M[i] = curr_req;
        required.pb(curr_req);
    }
    curr_req = 0;
    ll ans = 0;
    for(int pos = skills.size()-1; pos >= 0; pos--)
    {
        curr_req += A-skills[pos];
        ll curr_ans = pos*cf;
        map<ll, int> iterator::it = M.lower_bound(m-curr_req);
        ll left = m-(curr_req + it.first);
        if(it->second >= pos)
        {
            curr_ans = pos*cf + (skills[pos-1] + (m-(curr_req+required[pos-1]))/(pos))*cm;
            if(curr_ans > ans)
                ans = curr_ans;
            continue;
        }
        curr_ans += skills[it->second]*cm*(it->second+1) + (m-curr_req-required[it->second])/(it->second+1);
        if(curr_ans > ans)
            ans = curr_ans;
    }
    cout << ans;
    return 0;
}
