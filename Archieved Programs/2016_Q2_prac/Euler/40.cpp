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


int main()
{
    string s;
    for(int i = 0; i < MIL && s.size() <= MIL; i++)
    {
        string tmp = int_to_str(i);
        s += tmp;
    }
    ll ans = 1;
    for(int i = 1; i <= MIL; i *= 10)
    {
        cout << s[i-1];
        ans *= (s[i-1] - '0');
    }
    cout << "Ans is " << ans << endl;
    return 0;
}
