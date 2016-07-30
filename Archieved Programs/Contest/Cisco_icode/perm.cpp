#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define mp make_pair
#define ll long long int

using namespace std;

ll comb[62][62];
int n;
ll k;

bool bit_mask[64];

ll combin(int n, int r)
{
    ll num = 1, den = 1;
	for(int i = n; i > n-r; i--)
	{
		num *= i;
	}
	for(int i = 1; i <= r; i++)
		den *= i;
	ll ans = num/den;
	//pf("%dC%d == %lld\n", n, r, ans);
	return ans;
}

void check_1(int pos, int b, ll k)
{
	ll curr = combin(pos, b);
	ll cur_nex = combin(pos-1, b);
	if(curr_nex < k)
	{
		check_1(pos-1, b-1, 
	}
}

int main()
{
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		memset(bit_mask, 0, sizeof(bit_mask));
		cin >> n >> k;
		ll curr = 0;
		int set_bits = 0;
		for(int i = 0; i <= n; i++)
		{
			curr += combin(n, i);
			if(curr >= k)
			{
				curr -= combin(n, i);
				set_bits = i;
				break;
			}
		}
		curr = k - curr;
		//cout << "new_curr == " << curr << endl;
		check_1(n-1, set_bits, curr);
		ll ans = 0;
		for(int i = 0; i <= n; i++)
		{
			if(bit_mask[i])
			{
				ans += 1<<i;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
