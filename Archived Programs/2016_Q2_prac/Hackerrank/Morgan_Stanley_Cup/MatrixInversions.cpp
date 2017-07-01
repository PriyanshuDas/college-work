#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert

using namespace std;
vector <int> arr;
ll Merge(int l, int m, int r)
{
    ll ans = 0;
    vector<int> a, b;
    for(int i = l; i <= m; i++)
        a.pb(arr[i]);
    for(int j = m+1; j <= r; j++)
        b.pb(arr[j]);
    int i = 0, j = 0, k = l;
    while(k <= r && i < a.size() && j < b.size())
    {
        if(a[i] > b[j])
        {
            pf("Inversion comparing (%d, %d)\n", a[i], b[j]);
            ans += a.size() - i;
            arr[k] = b[j];
            j++;
            k++;
        }
        else
        {
            arr[k] = a[j];
            i++;
            k++;
        }
    }
    while(i < a.size())
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j < b.size())
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    return ans;
}
ll merge_sort(int l, int r)
{
    //cout << "Merge Sort : " << l << ',' << r << endl;
    ll ans = 0;
    int mid = (l+r)/2;
    if(l < r)
    {
        if(l < mid)
            ans += merge_sort(l, mid);
        if(mid+1 < r)
            ans += merge_sort(mid+1, r);
        ans += Merge(l, mid, r);
    }
    return ans;
}

int main()
{
    int N;  cin >> N;
    N = N*N;
    for(int i = 0; i < N; i++)
    {
        int tmp;    cin >> tmp;
        arr.pb(tmp);
    }
    ll inver = merge_sort(0, arr.size()-1);
    pf("%lld\n", inver);
    cout << "Sorted array : ";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    return 0;
}
