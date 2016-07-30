#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

int arr[101];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int ct;
        cin >> ct;
        for(int j = 0; j < ct; j++)
        {
            int tmp;
            cin >> tmp;
            arr[tmp] = 1;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(arr[i] == 0)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
