#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define n_max 100001

using namespace std;

int rows[n_max+1] = {0};
int cols[n_max+1] = {0};
int row_c = 0, col_c = 0;
int rook_c = 0;
int main()
{
    ll n, m;   cin >> n >> m;
    ll curr = 0;
    for(int i = 0; i < m; i++)
    {
        int xi, yi;
        sf("%d%d", &xi, &yi);
        if(rows[xi] == 0 && cols[yi] == 0)
        {
            curr += n + n - 1 - row_c - col_c;
            row_c++;    col_c++;    rows[xi] = 1;   cols[yi] = 1;
        }
        else if(rows[xi] == 1 && cols[yi] == 0)
        {
            curr += n - row_c;
            col_c++;    cols[yi] = 1;
        }
        else if(rows[xi] == 0 && cols[yi] == 1)
        {
            curr += n - col_c;
            row_c++;    rows[xi] = 1;
        }
        ll ret = n*n - curr;
        pf("%lld ", ret);
    }
    return 0;
}
