#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pf printf
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
    int n, k;   cin >> n >> k;
    string s;
    cin >> s;
    vector<int> F;
    int flag = 0;
    for(int i = 0; i < k; i++)
    {
        int tmp;    cin >> tmp;
        if(s[tmp-1] == '0')
            flag = 1;
    }
    if(flag == 1)
    {
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}
