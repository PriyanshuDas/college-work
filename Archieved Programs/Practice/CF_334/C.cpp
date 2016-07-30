#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair
#define MOD 1000000007

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int max_add = 0;
    int min_l = n+1, max_r = -1;
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(i > 0 && s[i] == s[i-1])
        {
            if(i < min_l)
                min_l = i;
        }
        if(i < n-1 && s[i] == s[i+1])
        {
            if(i > max_r)
                max_r = i;
        }
    }
    if(min_l <= max_r)
        max_add = 2;
    else if(n == 1 || (min_l == n+1)&&(max_r == -1))
    {
        max_add = 0;
    }
    else
    {
        max_add = 1;
    }
    ll orig = 1;
    for(int i = 1 ; i < n; i++)
    {
        if(s[i] != s[i-1])
            orig++;
    }
    orig += max_add;
    cout << orig;
    return 0;
}
