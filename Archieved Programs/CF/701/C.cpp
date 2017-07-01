#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define n_max 100001
#define int_max 9999999

using namespace std;

int sum[60][n_max+1] = {0};
int n;
int un = 0;

bool check(int a, int b)
{
    int c_c = 0;
    for(int i = 0; i < 60; i++)
    {
        if(sum[i][b] - sum[i][a-1] > 0)
            c_c++;
    }
    //pf("Checking from %d to %d : Found : %d\n", a, b, c_c);
    if(c_c == un)
        return true;
    return false;
}

int bin_search(int pos)
{
    int L = pos, R = n;
    int ret = int_max;
    while(L <= R)
    {
        //pf("Searching @ (%d, %d)\n", L, R);
        int m = (L+R)/2;
        if(check(pos, m))
        {
            //pf("Success!\n");
            ret = min(ret, m);
            R = m-1;
            continue;
        }
        if(check(pos, m) == false)
        {
            L = m+1;
            continue;
        }
        if(L >= R)
            return ret;
    }
    return ret;
}

int main()
{
    cin >> n;
    string s;   cin >> s;
    for(int i = 1; i <= n; i++)
    {
        int tmp = 0;
        if(s[i-1] >= 'A' && s[i-1] <= 'Z')
            tmp = 30 + (s[i-1] - 'A');
        if(s[i-1] >= 'a' && s[i-1] <= 'z')
            tmp = s[i-1] - 'a';
        for(int j = 0; j < 60; j++)
            sum[j][i] += sum[j][i-1];
        sum[tmp][i]++;
        //cout << tmp<< endl;
    }
    for(int i = 0; i < 60; i++)
    {
        if(sum[i][n] > 0)
            un++;
    }
    //pf("Unique pokes are : %d\n", un);
    int min_ans = n;
    n = s.size();
    for(int i = 1; i <= n; i++)
    {
        //pf("Searching from %d\n", i);
        int curr = bin_search(i) - i+1;
        if(curr < min_ans)
            min_ans = curr;
    }
    cout << min_ans;
}
