
#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
    int T;  cin >> T;
    for(int t = 0; t < T; t++)
    {
        int N;  cin >> N;
        string s;
        for(int i = 0; i < N; i++)
            s += (i%26 + 'a');
        cout << s<<endl;
    }
    return 0;
}
