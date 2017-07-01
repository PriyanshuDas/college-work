#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define MIL 1000000

using namespace std;

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

string int_to_str(int I)
{
    string str;
    while(I > 0)
    {
        str += ((I%10) + '0');
        I /= 10;
    }
    return rev_str(str);
}

string int_to_bin(int I)
{
    string ret;
    while(I > 0)
    {
        if(I%2 == 1)
            ret += '1';
        else
            ret += '0';
        I /= 2;
    }
    return ret;
}
int str_to_int(string s)
{
    int num = 0;
    for(int i = 0; i < s.size(); i++)
    {
        num *= 10;
        num += (s[i] - '0');
    }
    return num;
}

bool palin(string s)
{
    for(int i = 0; i < s.size()/2; i++)
    {
        if(s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    ll ans = 0;
    for(int i = 0; i < MIL; i++)
    {
        string s = int_to_str(i);
        string b = int_to_bin(i);
        if(palin(s) && palin(b))
            ans += i;
    }
    pf("Sum is : %lld\n", ans);
    return 0;
}
