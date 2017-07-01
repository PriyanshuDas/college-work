#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int

using namespace std;

int main()
{
    int T;  cin >> T;
    for(int i = 0; i < T; i++)
    {
        string s;   cin >> s;
        int flag = 0;
        for(int i = 0; i < s.size()/2; i++)
        {
            if(s[i] != s[s.size()-1-i])
                flag = 1;
        }
        if(flag == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
