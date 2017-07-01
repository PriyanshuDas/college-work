#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define max_l 1000000000

using namespace std;

int main()
{
    int n;  cin >> n;
    vector <char> dir;
    int x, y;
    int x0, y0; sf("%d%d", &x0, &y0);
    x = x0; y = y0;
    for(int i = 1; i <= n; i++)
    {
        int x1, y1; sf("%d%d", &x1, &y1);
        if(x1 > x0)
            dir.pb('R');
        else if(x1 < x0)
            dir.pb('L');
        else if(y1 > y0)
            dir.pb('U');
        else
            dir.pb('D');
       x0 = x1;    y0 = y1;
    }
    if(x > x0)
        dir.pb('R');
    else if(x < x0)
        dir.pb('L');
    else if(y > y0)
        dir.pb('U');
    else
        dir.pb('D');
    int ct = 0;
    for(int i = 1 ;i < dir.size(); i++)
    {
        char p = dir[i-1], c = dir[i];
        if(p == 'U' && c == 'R')
            ct++;
        else if(p =='R' && c == 'D')
            ct++;
        else if(p == 'D' && c == 'L')
            ct++;
        else if(p == 'L' && c == 'U')
            ct++;
    }
    cout << ct;
    return 0;
}
