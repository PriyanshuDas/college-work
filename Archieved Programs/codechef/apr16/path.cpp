#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    int T;  cin >> T;
    for(int t = 0; t < T; t++)
    {
        ll N, M;
        cin >> N >> M;
        if((N%2 == 1 && M%2 == 1) || (N == 1 && M != 2) || (N != 2 && M == 1))
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}
