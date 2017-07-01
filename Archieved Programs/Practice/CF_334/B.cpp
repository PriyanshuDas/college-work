#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair
#define MOD 1000000007

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int s[100001] = {0};
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int pos = n-1;
    int ct = 0;
    int box[200002] = {0};
    ll ans = 0;
    for(pos; pos > 0 && ct < k; pos--)
    {
        box[pos] = s[pos];
        if(box[pos] > ans)
            ans = box[pos];
        ct++;
    }
    for(int i = 0; i <= pos; i++)
    {
        box[pos+1+i] += s[i];
        if(box[pos+1+i] > ans)
            ans = box[pos+1+i];
    }
    cout << ans;
    return 0;
}
