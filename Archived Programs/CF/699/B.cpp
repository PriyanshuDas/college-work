#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int n, m;   cin >> n >> m;
    string M[1001];
    int r_c[1001] = {0}, c_c[1001] = {0}, tot_c = 0;
    for(int i = 0; i < n; i++)
        cin >> M[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(M[i][j] == '*')
            {
                c_c[i]++;   r_c[j]++;   tot_c++;
            }
        }
    }
    int flag = 0, x = 0, y = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int tmp = c_c[i] + r_c[j];
            if(M[i][j] == '*')
                tmp--;
            if(tmp == tot_c && flag == 0)
            {
                flag = 1;
                x = i+1, y = j+1;
            }
        }
    }
    if(flag == 0)
        cout << "NO";
    else
    {
        cout << "YES" << endl << x << ' ' << y;
    }
    return 0;
}
