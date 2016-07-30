#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

int k;
vector <string > ans;

void gen(int n, string s)
{
    for(int k = n/2; k >= 1; k /= 2)
    {
        string tmp = s;
        for(int j = 0; j < s.size(); j++)
        {
            if((j/k)%2 == 0)
            {
                if(tmp[j] == '*')
                    tmp[j] = '+';
                else
                    tmp[j] = '*';
            }
        }
        ans.pb(tmp);
        gen(k, tmp);
    }
}

int main()
{
    cin >> k;
    int num = 1;
    for(int i = 1; i <= k; i++)
        num *= 2;
    string tmp = "";
    for(int i = 0; i < num; i++)
        tmp += "+";
    ans.pb(tmp);

    gen(num, tmp);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
