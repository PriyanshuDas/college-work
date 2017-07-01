#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
    int n;  cin >> n;
    multiset <int> S;
    vector<pair<string, int> > Res;
    for(int i = 0; i < n; i++)
    {
        string s; int m;    cin >> s;
        pair <string, int> curr_p = mp(s, -1);
        if(s == "insert")
        {
            cin >> m;
            S.insert(m);
            curr_p.second = m;
        }
        else if(s == "getMin")
        {
            cin >> m;
            multiset<int>::iterator it = S.find(m);
            if(it == S.end())
            {
                S.insert(m);
                Res.pb(mp("insert", m));
            }
            it = S.begin();
            while(*it != m)
            {
                S.erase(it);
                Res.pb(mp("removeMin", -1));
                it = S.begin();
            }
            curr_p.second = m;
        }
        else
        {
            multiset<int>::iterator it = S.begin();
            if(it == S.end())
            {
                Res.pb(mp("insert", 100000));
                S.insert(100000);
            }
            S.erase(S.begin());
        }
        Res.pb(curr_p);
    }
    cout << Res.size() << endl;
    for(int i = 0; i < Res.size(); i++)
    {
        pair<string, int> tmp = Res[i];
        cout << Res[i].first;
        if(Res[i].second != -1)
            cout << ' ' << Res[i].second;
        cout << endl;
    }
    return 0;
}
