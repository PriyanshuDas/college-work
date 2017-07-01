#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pii pair<int, int>
#define pi3 pair<int, pair<int, int> >


using namespace std;

int main()
{
    int n;  cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int tmp;    cin >> tmp; arr.pb(tmp);
    }
    vector <pair<int, int> > ans;
    int s = 1;
    while(s)
    {
        s = 0;
        for(int i = 1; i < n; i++)
        {
            if(arr[i-1] > arr[i])
            {
                swap(arr[i-1], arr[i]);
                ans.pb(mp(i, i+1));
                s = 1;
            }
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        pf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}
