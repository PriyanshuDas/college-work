#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    pair<char,int> V[] = {{'a',1}, {'b',2}, {'c',2}, {'d',3}};
    sort(V, V+4);
    int total = 1+2+3+2;
    int curr = 2;
    int ct[4] = {0};
    while(next_permutation(V, V+4))
    {
        int sum = 0, flag = 0, d_vote = 0;
        cout << curr <<". {";
        curr++;
        for(int i = 0; i < 4; i++)
        {
            cout << V[i].second << ' ';
            sum += V[i].second;
            if(2*sum > total && !flag)
            {
                flag = 1;
                d_vote = V[i].second;
                ct[V[i].second]++;
            }
        }
        cout << "}" << " D : " << d_vote << endl;
    }
    ct[2]++;
    for(int i = 1; i < 4; i++)
    {
        pf("No of deciding votes by [%d] : %d\n", i, ct[i]);
    }
    return 0;
}
