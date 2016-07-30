#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define max_s 100001

using namespace std;

vector <ll> arr;

int main()
{
    int n;  cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        arr.pb(tmp);
    }
    sort(arr.begin(), arr.end());
    ll low = 1, curr = 1;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] >= curr)
        {
            arr[i] = curr;
            curr++;
        }
    }
    for(int i = 0; i < arr.size(); i++)
    {
        //cout << arr[i] << ' ';
        if(arr[i] == low)
        {
            low += 1;
        }
    }
    cout << low;
    return 0;
}
