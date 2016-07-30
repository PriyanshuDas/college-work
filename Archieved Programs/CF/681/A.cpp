#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
    int n;  cin >>n;
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        string tmp; cin >> tmp;
        int b, a; cin >> b >> a;
        if (a > b && b >= 2400)
        {
            flag = 1;
        }
    }
    if(flag == 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
