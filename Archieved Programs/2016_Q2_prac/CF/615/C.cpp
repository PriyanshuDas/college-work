#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll unsigned long long int
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

int main()
{
    string s1, s2, t;
    cin >> s1 >> t;
    s2 = string (s1.rbegin(), s1.rend());
    map<string, pair<int, int> > S;
    for(int i = 0; i < s1.size(); i++)
    {
        string t1, t2;
        t1 += s1[i];    t2 += s2[i];
        S[t1] = mp(i+1, i+1);      S[t2] = mp(s1.size()-i, s1.size()-i);
        for(int j = i+1; j < s1.size(); j++)
        {
            t1 += s1[j];    t2 += s2[j];
            S[t1] = mp(i+1, j+1);   S[t2] = mp(s1.size()-i, s1.size()-j);
        }
    }
    int flag = 0, ct = 0;
    vector <pair<int, int> > V;
    for(int i = 0; i < t.size(); i++)
    {
        string tmp;     tmp += t[i];
        map<string, pair<int, int> >::iterator it = S.find(tmp);
        pair<int, int> c;
        if(it == S.end())
        {
            c = it->second;
            flag = 1;
            break;
        }
        ct++;
        for(int j = i+1; j < t.size(); j++)
        {
            tmp += t[j];
            it = S.find(tmp);
            if(it != S.end())
            {
                c = it->second;
                i++;
            }
            else
            {
                break;
            }
        }
        V.pb(c);
    }
    if(flag == 1)
    {
        cout << -1;
    }
    else
    {
        cout << ct << endl;
        for(int i = 0; i < V.size(); i++)
        {
            pf("%d %d\n", V[i].first, V[i].second);
        }
    }
    //cout << s1 << endl << s2 ;
    return 0;
}
