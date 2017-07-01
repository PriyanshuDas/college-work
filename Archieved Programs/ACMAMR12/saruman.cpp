#include <bits/stdc++.h>

#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert

using namespace std;

int main()
{
    int T, K, N;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cin >> N >> K;
        string c;   cin >> c;
        int flag = 0;
        int ct = 0, curr_l = 1;
        if(K == 1)
        {
            flag = 1;
            curr_l = 0;
            ct++;
        }
        for(int i = 1; i < c.size(); i++)
        {
            if(c[i] == c[i-1])
            {
                curr_l++;
                if(curr_l == K)
                {
                    flag = 1;
                    curr_l = 0;
                    ct++;
                }
            }
            else
            {
                curr_l = 1;
                ct++;
            }
        }
        if(curr_l > 0 && N >= 2 && c[N-1] == c[N-2])
            ct++;
        if(flag == 0)
            cout << -1 << endl;
        else
            cout << ct << endl;
    }
    return 0;
}
