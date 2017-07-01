<<<<<<< HEAD
/*--------------------- Voting Power ----------------------------------
------------------- Shapley - Shubick --------------------------------*/

#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;
int vote_qty[11], ct[11], last_ct[11], tot_v, n, curr_p;
ll vot_pow[11], curr_ans = 0;

ll Perm(int n)
{
    if(n == 0)
        return 1;
    ll ans = 1;
    for(int i = 1; i <= n; i++)
        ans *= i;
    return ans;
}

ll combin(int n, int r)
{
    if(r == 0 || n == 0)
        return 1;
    ll ans = 1;
    for(int i = n; i > (n-r); i--)
        ans *= i;
    for(int i = 1; i <= r; i++)
        ans /= i;
    return ans;
}
void dp(int pos, int no_ppl, int tot_v_l)
{
    if(pos > 10 || 2*tot_v_l > tot_v)
        return;
    if(2*(tot_v_l + curr_p) > tot_v)
    {
        int flag = 1;
        for(int i = 0; i < 11; i++)
            if(last_ct[i] != ct[i])
                flag = 0;
        if(!flag)
        {
            //pf("DP(%d, %d, %d)\n", pos, no_ppl, tot_v);
            //pf("(%d, %d, %d)\n", ct[1], ct[2], ct[3]);
            ll ans = 1;
            for(int i = 0; i < 11; i++)
            {
                ans *= combin(vote_qty[i], ct[i]);
            }
            ans *= Perm(no_ppl);
            ans *= Perm(n - no_ppl - 1);
            //if(pos <= 1)
            //pf("Possible ans @ (%d, %d, %d)\n", pos, no_ppl, tot_v);
            curr_ans += ans;
            for(int i = 0; i < 11; i++)
                last_ct[i] = ct[i];
        }
    }
    for(int i = 0; i <= vote_qty[pos]; i++)
    {
        ct[pos] = i;
        dp(pos+1, no_ppl+i, tot_v_l + i*pos);
    }
    ct[pos] = 0;
    return;
}

int main()
{
    cout << "Enter No of Voters (<20) (integer overflow) : ";
    cin >> n;
    cout << "Enter the no of votes for each member (< 10) :\n";
    vector <int> vot_vec;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        sf("%d", &tmp);
        vote_qty[tmp]++;
        vot_vec.pb(tmp);
        tot_v += tmp;
    }
    for(int i = 0; i <= 10; i++)
    {
        if(vote_qty[i] == 0)
            continue;
        curr_ans = 0;
        curr_p = i;
        vote_qty[i]--;
        memset(last_ct, -1, sizeof(last_ct));
        //cout << "Cases for " << i << endl;
        dp(0, 0, 0);
        vote_qty[i]++;
        vot_pow[i] = curr_ans;
        //cout << vot_pow[i]<< endl;
    }
    ll n_fact = Perm(n);
    double fin_pow[11] = {0};
    for(int i = 0; i <= 10; i++)
    {
        fin_pow[i] = (double)vot_pow[i]/(n_fact);
       // pf("fin_pow[%d] == %lf\n", i, fin_pow[i]);
    }
    cout << "Voting Powers are :\n{";
    double sum = 0;
    for(int i = 0; i < vot_vec.size(); i++)
    {
        cout << fin_pow[vot_vec[i]];
        if(i != vot_vec.size() - 1)
            cout << ", ";
        sum += fin_pow[vot_vec[i]];
    }
    cout << "}\n";
    //cout << "Sum is : " << sum << endl;
    return 0;
}
=======
/*--------------------- Voting Power ----------------------------------
------------------- Shapley - Shubick --------------------------------*/

#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;
int vote_qty[11], ct[11], last_ct[11], tot_v, n, curr_p;
ll vot_pow[11], curr_ans = 0;

ll Perm(int n)
{
    if(n == 0)
        return 1;
    ll ans = 1;
    for(int i = 1; i <= n; i++)
        ans *= i;
    return ans;
}

ll combin(int n, int r)
{
    if(r == 0 || n == 0)
        return 1;
    ll ans = 1;
    for(int i = n; i > (n-r); i--)
        ans *= i;
    for(int i = 1; i <= r; i++)
        ans /= i;
    return ans;
}
void dp(int pos, int no_ppl, int tot_v_l)
{
    if(pos > 10 || 2*tot_v_l > tot_v)
        return;
    if(2*(tot_v_l + curr_p) > tot_v)
    {
        int flag = 1;
        for(int i = 0; i < 11; i++)
            if(last_ct[i] != ct[i])
                flag = 0;
        if(!flag)
        {
            //pf("DP(%d, %d, %d)\n", pos, no_ppl, tot_v);
            //pf("(%d, %d, %d)\n", ct[1], ct[2], ct[3]);
            ll ans = 1;
            for(int i = 0; i < 11; i++)
            {
                ans *= combin(vote_qty[i], ct[i]);
            }
            ans *= Perm(no_ppl);
            ans *= Perm(n - no_ppl - 1);
            //if(pos <= 1)
            //pf("Possible ans @ (%d, %d, %d)\n", pos, no_ppl, tot_v);
            curr_ans += ans;
            for(int i = 0; i < 11; i++)
                last_ct[i] = ct[i];
        }
    }
    for(int i = 0; i <= vote_qty[pos]; i++)
    {
        ct[pos] = i;
        dp(pos+1, no_ppl+i, tot_v_l + i*pos);
    }
    ct[pos] = 0;
    return;
}

int main()
{
    cout << "Enter No of Voters (<20) (integer overflow) : ";
    cin >> n;
    cout << "Enter the no of votes for each member (< 10) :\n";
    vector <int> vot_vec;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        sf("%d", &tmp);
        vote_qty[tmp]++;
        vot_vec.pb(tmp);
        tot_v += tmp;
    }
    for(int i = 0; i <= 10; i++)
    {
        if(vote_qty[i] == 0)
            continue;
        curr_ans = 0;
        curr_p = i;
        vote_qty[i]--;
        memset(last_ct, -1, sizeof(last_ct));
        //cout << "Cases for " << i << endl;
        dp(0, 0, 0);
        vote_qty[i]++;
        vot_pow[i] = curr_ans;
        //cout << vot_pow[i]<< endl;
    }
    ll n_fact = Perm(n);
    double fin_pow[11] = {0};
    for(int i = 0; i <= 10; i++)
    {
        fin_pow[i] = (double)vot_pow[i]/(n_fact);
       // pf("fin_pow[%d] == %lf\n", i, fin_pow[i]);
    }
    cout << "Voting Powers are :\n{";
    double sum = 0;
    for(int i = 0; i < vot_vec.size(); i++)
    {
        cout << fin_pow[vot_vec[i]];
        if(i != vot_vec.size() - 1)
            cout << ", ";
        sum += fin_pow[vot_vec[i]];
    }
    cout << "}\n";
    //cout << "Sum is : " << sum << endl;
    return 0;
}
>>>>>>> d41c9ab97132aeab1446e831c5d1dfa0a46f1203
