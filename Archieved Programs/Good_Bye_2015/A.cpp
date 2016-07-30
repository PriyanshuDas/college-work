#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int flag = 2, day, date;
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'k')
            flag = 1;
    }
    if(flag == 1)
    {
        day = s[0] - '0';
        ans = 366/7;
        if(day == 5 || day == 6)
            ans++;
    }
    if(flag == 2)
    {
        if(s[1] == ' ')
        date = s[0] - '0';
        else
            date = (s[0] - '0')*10 + (s[1] - '0');
        if(date < 30)
            ans = 12;
        else if(date == 30)
            ans = 11;
        else
            ans = 7;
    }
    cout << ans;
    return 0;
}
