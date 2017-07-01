#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
    int n, ans = 0;  cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;    cin >> tmp;
        tmp--;
        ans += tmp;
        if(ans%2 == 0)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}
