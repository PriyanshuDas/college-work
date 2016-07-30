#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define loop(n) for(int i = 0; i < n; i++)
#define pi2 pair<int, int>
#define pi3 pair<int, pair<int,int> >
#define pi4 pair<pair<int, int>, pair<int, int> >

using namespace std;

int main()
{
    int n;
    cin >> n;
    int num_zero = 0;
    string num_nzero;
    for(int asd = 0; asd < n; asd++)
    {
        string tmp;
        cin >> tmp;
        int num = 0;
        int i = 0;
        for(i = tmp.size()-1; i >= 0; i--)
        {
            if(tmp[i] == '0' && tmp.size() != 1)
                num_zero++;
            else
            {
                break;
            }
        }
        string s1 = tmp.substr(0, i+1);
        if(!(s1 == "0" || s1 == "1"))
        {
            num_nzero = s1;
        }
        else if(s1 == "0")
        {
            cout << "0";
            return 0;
        }
    }
    if(num_nzero == "")
        cout << '1';
    else
        cout << num_nzero;
    while(num_zero)
    {
        printf("0");
        num_zero--;
    }
    return 0;
}
