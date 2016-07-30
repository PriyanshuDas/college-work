#include<bits/stdc++.h>

/*do {

  } while (next_permutation(myints,myints+3));
*/ //next_permutation

#define ll long long int
#define pf printf
#define sf scanf
#define lim 1000000001
#define ll long long int
#define pb push_back

using namespace std;

ll perm[16];
ll pow_2[13];

void pow2(ll n)
{
    pow_2[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        pow_2[i] = pow_2[i-1]*2;
    }
}

ll permute(int n)
{
    if(perm[n])
        return perm[n];
    if(n == 0 || n == 1)
    {
        perm[n] = 1;
        return perm[n];
    }
    perm[n] = n*permute(n-1);
    return perm[n];
}

vector <ll> nth_permutation(vector<ll> Original, ll K)
{
    vector <ll> New;
    ll num = K;
    /*printf("Finding the %lldth Permutation\nThe Original Vector is - \n", K);
    for(int i = 0; i < Original.size(); i++)
    {
        printf("%lld\t", Original[i]);
    }*/
    //printf("\n");
    for(ll i = Original.size()-1; i > 0 && Original.size() > 1; i--)
    {
        //printf("%lld", num);
        ll Q = num/perm[i];
        num = num%perm[i];
        if(!num)
        {
            Q--;
            num = perm[i];
        }
        New.pb(Original[Q]);
        //printf(" == %lld*%lld! + %lld\n", Q, i, num);
        Original.erase(Original.begin() + Q);
    }
    New.pb(Original[0]);
    /*printf("\nFinding the %lldth Permutation\nThe New Vector is - \n", K);
    for(int i = 0; i < New.size(); i++)
    {
        printf("%lld\t", New[i]);
    }
    printf("\n");*/
    return New;
}

ll check(ll N)
{
    //cout << "Limit is = " << N << endl;
    ll ans = 0;
    int dig = 0;
    ll N2 = N;
    ll dvs = 1;
    while(N2)
    {
        dvs*= 10;
        dig++;
        N2/= 10;
    }
    int pos = dig;
    ll mul = 1;
    while(N)
    {
        pos--;
        dvs /= 10;
        int curr = N/dvs;
        N %= dvs;
        if(curr < 4)
            break;
        else if(curr == 4)
            continue;
        if (curr > 4 && curr < 7)
        {
            ans += pow_2[pos];
            break;
        }
        if(curr > 7)
        {
            ans += 2*pow_2[pos];
            break;
        }
        if(curr == 7)
        {
            mul *= 2;
        }
    }
    ans *= mul;
    //cout << "Answer is = " << ans << endl;
    return ans;
}

int check_luck(ll N)
{
    if(!N)
        return 0;
    while(N)
    {
        int curr = N%10;
        N /= 10;
        if(curr != 4 && curr != 7)
            return 0;
    }
    return 1;
}
int main()
{
    perm[0] = 1;
    pow2(12);
    permute(15);
    ll n, k;
    cin >> n >> k;
    ll L = n;
    for(int i = 0; i < 15; i++)
    {
        if(perm[i] >= k)
        {
            L = n - i;
            break;
        }
    }
    //cout << "Limit is - " << L << endl;
    vector <ll> p_vec;
    for(ll i = L+1; i <= n; i++)
    {
        p_vec.pb(i);
    }
    if(p_vec.size())
    {
        p_vec = nth_permutation(p_vec, k);
    }
    ll ans = 0;
    for(int i = 0; i <p_vec.size(); i++)
    {
        if(check_luck(L + 1 + i) && check_luck(p_vec[i]))
        {
            ans++;
        }
    }
    //cout<< "Answer from vector is - " << ans << endl;
    ans += check(L);
    int no_digits = 0;
    int last_digit = 0;
    ll L2 = 1;
    ll Li = L;
    while(L)
    {
        no_digits++;
        last_digit = L%10;
        L /= 10;
        L2 *= 10;
    }
    L2 /= 100;
    if(no_digits)
    {
        ans += pow_2[no_digits-1];
    }
    cout << ans;
    return 0;
}
