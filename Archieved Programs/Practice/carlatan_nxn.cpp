#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back

using namespace std;

ll Combin(int n, int r)
{
    ll ans = 1;
    for(int i = n; i > n-r; i--)
        ans *= i;
    for(int i = 1; i <= r; i++)
    {
        ans /= i;
    }
    return ans;
}

ll Carlatan(int x)
{
    ll ans = Combin(2*x, x);
    ans /= (x+1);
    return ans;
}

int main()
{
    ll arr[20][20];
    cout <<  setw(10) << "Num" << '|' << setw(10) << "Cn" << '|' << setw(20) << "Ans" << '|' << endl;
    for(int i = 1; i < 15; i++)
    {
        ll Cn = Carlatan(i);
        memset(arr, 0, sizeof(arr));
        for(int j = 0; j <= i; j++)
        {
            arr[0][j] = 1;
        }
        for(int j = 1; j <= i; j++)
        {
            for(int k = 1; k <= i; k++)
            {
                if(j <= k)
                arr[j][k] = arr[j-1][k]+arr[j][k-1];
            }
        }
        cout << setw(10) << i << '|'<< setw(10) << Cn << '|' << setw(20) << arr[i][i]<< '|' << endl;
    }
    return 0;
}
