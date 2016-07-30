
#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define max_l 1000000
#define pb push_back

using namespace std;

int memo[2*max_l+1];
string s_mem[2*max_l+1];
vector<string> string_list;
ll decode(string s)
{
    ll ans = 0;
    for(int i = 0; i < s.size(); i++)
    {
        switch(s[i])
        {
        case '0':
        {
            ans += i + 1;
            break;
        }
        case '1':
        {
            ans -= (i+1);
            break;
        }
        case '2':
        {
            ans *= (i+1);
            break;
        }
        default:
            break;
        }
    }
    return ans;
}

void gen(string s)
{
    if(s.size() > 13)
        return;
    for(int i = 0; i < 3; i++)
    {
        char ch = '0'+i;
        string s2 = s+ch;
        string_list.pb(s2);
        gen(s2);
    }
}

int main()
{
   // string s;
    //cout << "Enter String to decode : ";
    //cin >> s;
    //ll ans = decode(s);
    //cout << "The Output is : " << ans << endl;
    memset(memo, -1, sizeof(memo));
    gen("");
    for(int i = 0; i < string_list.size(); i++)
    {
        string s1 = string_list[i];
        int val = max_l + decode(s1);
        int len = s1.size();
        //cout << val << endl;
        if(val < 2*max_l && val >= 0 && (memo[val] == -1 || len < memo[val]))
        {
            s_mem[val] = s1;
            memo[val] = len;
        }
    }
    for(int i = 0; i <= 10000; i++)
    {
        if(s_mem[i+max_l] == "")
        {
            cout << i << endl;
            break;
        }
        //cout << i << " == " << s_mem[i+max_l] << endl;
    }
    return 0;
}
