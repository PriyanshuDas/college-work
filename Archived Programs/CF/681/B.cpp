#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back

#define A 1234567
#define B 123456
#define C 1234

#define A_x 46
#define B_x 3
#define C_x 45721

using namespace std;

ll n;
int main()
{
    cin >> n;
    for(int i = 0; i < 1001; i++)
    {
        for(int j = 0; j < 10001; j++)
        {
            ll tmp = (ll)A*i + (ll)B*j;
            if((n -tmp)%C == 0 && n >= tmp)
            {
                //pf("(%d, %d) %lld\n", i, j, tmp);
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
