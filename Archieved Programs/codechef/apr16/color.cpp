#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define pb push_back
#define mp make_pair
#define ll long long int
#define pii pair<int, int>

using namespace std;

int main()
{
    int T, N;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cin >> N;
        string s;
        cin >> s;
        int col[3] = {0};
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'R')
                col[0]++;
            else if(s[i] == 'G')
                col[1]++;
            else
                col[2]++;
        }
        int ans = N - max(col[0], max(col[1], col[2]));
        cout << ans << endl;
    }
}
