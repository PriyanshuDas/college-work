#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int

using namespace std;

int main()
{
    string s;   cin >> s;
    string ans;
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i] - '0';
        ans += (char)(c + '0');
    }
    cout << ans;
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}
