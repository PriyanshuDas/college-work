#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

int n, k;
int ct[501]= {0};
int t_ct[501] = {0};


int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int tmp;    sf("%d", &tmp);
        ct[tmp]++;
    }
    dp(0, 0);
    return 0;
}
