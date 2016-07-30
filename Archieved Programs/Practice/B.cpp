#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        int tmp;
        sf("%d", &tmp);
        arr.pb(tmp);
    }
    int min_ct = 1, max_ct = 1;
    int total_ct = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == arr[i-1] + 1)
        {
            max_ct = min_ct+1;
            min_ct = 1;
            total_ct = max(total_ct, max(min_ct, max_ct));
        }
        else if(arr[i] == arr[i-1] - 1)
        {
            min_ct = max_ct+1;
            max_ct = 1;
            total_ct = max(total_ct, max(min_ct, max_ct));
            //cout << max_ct << endl;
        }
        else if(arr[i] == arr[i-1])
        {
            min_ct++;
            max_ct++;
            total_ct = max(total_ct, max(min_ct, max_ct));
        }
        else
        {
            min_ct = 1;
            max_ct = 1;
            total_ct = max(total_ct, max(min_ct, max_ct));
        }
        //cout << min_ct << ' ' << max_ct << ' ' << total_ct << endl;
    }
    cout << total_ct;
    return 0;
}
