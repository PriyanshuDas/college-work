#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define ins insert

using namespace std;

vector <string> V;
string rev_str(string s)
{
    string t = s;
    //cout << s;
    for(int i = 0; i < t.size()/2; i++)
    {
        swap(t[i], t[t.size() - 1 - i]);
    }
    //cout << "Reversed is " << t << endl;
    return t;
}

string int_to_str(ll I)
{
    string str;
    while(I > 0)
    {
        str += ((I%10) + '0');
        I /= 10;
    }
    return rev_str(str);
}

ll str_to_int(string s)
{
    ll num = 0;
    for(int i = 0; i < s.size(); i++)
    {
        num *= 10;
        num += (s[i] - '0');
    }
    return num;
}

void gen_s(string s)
{
    int ct[10] = {0};
    if(s.size() == 10)
    {
        //cout << s << endl;
        V.pb(s);
        return;
    }
    for(int i = 0; i < s.size(); i++)
    {
        ct[s[i] - '0']++;
    }
    for(int i = 0; i < 10; i++)
    {
        string tmp = s; tmp += (i + '0');
        if(i == 0 && s.size() == 0)
            continue;
        if(ct[i] == 0)
            gen_s(tmp);
    }
}

int main()
{
    gen_s("");
    ll ans = 0;
    int div[] = {2, 3, 5, 7, 11, 13, 17};
    for(int i = 0; i < V.size(); i++)
    {
        //cout << V[i] << endl;
        vector <string> D;
        for(int j = 1; j < 8; j++)
        {
            string tmp = V[i].substr(j, 3);
            //cout << tmp << endl;
            D.pb(tmp);
        }
        int flag = 0;
        for(int j = 0; j < D.size(); j++)
        {
            ll curr = str_to_int(D[j]);
            if(curr%div[j] != 0)
                flag = 1;
        }
        if(flag == 0)
        {
            ll tmp = str_to_int(V[i]);
            cout << tmp << endl;
            ans += str_to_int(V[i]);
        }
    }
    cout << "Answer is : " << ans << endl;
    return 0;
}
