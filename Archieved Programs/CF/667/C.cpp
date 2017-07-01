#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define max_pos 10001

using namespace std;
ll visit[max_pos][4];
string s, prev_s, next_s;
set<string> suff_list;

ll calculate(int pos, int last_no)
{
    if(pos == s.size())
        return 1;
    if(pos > s.size())
        return 0;
    if(visit[pos][last_no] != -1)
        return visit[pos][last_no];
    ll ans = 0;
    prev_s = s.substr(pos-last_no, last_no);
    next_s = s.substr(pos, 2);
    ll curr_ans = 0;
    if(prev_s != next_s)
    {
        curr_ans = calculate(pos+2, 2);
    }
    //pf("@(%d, %d)\n", pos, last_no);
    //cout << curr_ans << endl;
    ans += curr_ans;
    if(curr_ans != 0)
    {
        next_s = s.substr(pos, 2);
        suff_list.insert(next_s);
    }
    curr_ans = 0;
    next_s = s.substr(pos, 3);
    if(prev_s != next_s)
    {
        curr_ans = calculate(pos+3, 3);
    }
    ans += curr_ans;
    if(curr_ans != 0)
    {
        next_s = s.substr(pos, 3);
        suff_list.insert(next_s);
    }
    visit[pos][last_no] = ans;
    return ans;
}

int main()
{
    cin >> s;
    ll Ans = 0;
    memset(visit, -1, sizeof(visit));
    for(int i = 5; i < s.size(); i++)
    {
        Ans += calculate(i, 0);
    }
    cout << Ans << endl;
    set<string>::iterator it;
    for(it = suff_list.begin(); it != suff_list.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}
