#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert

using namespace std;

int main()
{
    int T;  cin >> T;
    for(int t = 0; t < T; t++)
    {
        int N;  cin >> N;
        vector<int> C;
        for(int i = 0; i < N; i++)
        {
            int Ci; cin >> Ci;
            C.pb(Ci);
        }
        int flag = 0;
        for(int i = 1; i < N-1; i++)
        {
            if(C[i-1] == C[i] && C[i] == C[i+1])
                flag = 1;
        }
        if(flag == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
