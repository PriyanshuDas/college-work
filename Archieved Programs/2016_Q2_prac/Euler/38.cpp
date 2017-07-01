#include <bits/stdc++.h>
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back
#define limit 1000000

using namespace std;

string rev_str(string s)
{
    string t = s;
    //cout << s;
    for(int i = 0; i < t.size()/2; i++)
    {
        swap(t[i], t[t.size() - 1 - i]);
    }
    //cout << "Reversed is " << t << endl;
    return t;
}

string int_to_str(int I)
{
    string str;
    while(I > 0)
    {
        str += ((I%10) + '0');
        I /= 10;
    }
    return rev_str(str);
}

int main()
{
    vector<int> V;
    for(int i = 9; i < limit; i++)
    {
        int mod = 0;
        int n = i;
        while(n > 0)
        {
            mod = n%10;
            n /= 10;
        }
        if(mod == 9)
            V.pb(i);
    }
    vector <string> ans;
    for(int i = 0; i < V.size(); i++)
    {
        int ct[10] = {0};
        int flag = 0;
        string s;
        int flag1 = 0;
        for(int j = 1; j < 10; j++)
        {
            int curr = V[i]*j, flag = 0;
            while(curr > 0)
            {
                if(ct[curr%10] != 0)
                {
                    flag = 1;
                    break;
                }
                ct[curr%10]++;
                curr /= 10;
            }
            curr = V[i]*j;
            if(flag == 0)
                s += int_to_str(curr);
            if(flag == 1)
                break;
        }
        for(int j = 1; j < 10; j++)
        {
            if(ct[j] != 1)
                flag1 = 1;
        }
        if(ct[0] > 0)
            flag1 = 1;
        if(flag1 == 0 && s.size() == 9)
            ans.pb(s);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
