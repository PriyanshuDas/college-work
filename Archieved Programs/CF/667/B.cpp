#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define PI 3.14159265359

using namespace std;

int main()
{
    int n;  cin >> n;
    vector <int> len;
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        int li; cin >> li;
        len.pb(li);
        sum += li;
    }
    sort(len.begin(), len.end());
    sum -= len[len.size()-1];
    int req = len[len.size()-1] - sum + 1;
    cout << req;
    return 0;
}
