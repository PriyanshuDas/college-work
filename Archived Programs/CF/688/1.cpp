#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int

using namespace std;

int main()
{
    int n, d;   cin >> n >> d;
    int ans = 0, curr = 0;
    for(int i = 0; i < d; i++)
    {
        string s;   cin >> s;
        sort(s.begin(), s.end());
        if(s[0] == '0')
            curr++;
        else
            curr = 0;
        ans = max(ans, curr);
    }
    cout << ans;
    return 0;
}
