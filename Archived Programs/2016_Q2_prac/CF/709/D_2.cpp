#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll> >

using namespace std;

ll solve(ll a, ll b, ll c)
{
	ll D = b*b - 4*a*c;
	ll sq = (ll)sqrt(D);
	if(sq*sq < D)
		sq++;
	if(sq*sq > D)
		sq--;
	ll num = 1 + sq;
	if(c == 0)
		return 0;
	return num/2;
}

int main()
{
	ll a[4];
	for(int i = 0; i < 4; i++)
		cin >> a[i];
	ll ct_0 = solve(1, -1, -2*a[0]);
	ll ct_1 = solve(1, -1, -2*a[3]);
	/*cout << ct_0 << ' ' << ct_1 << endl;
	pf("(%lld, %lld, %lld, %lld)\n", a[0], a[1], a[2], a[3]);*/
	if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0)
    {
        cout << 0;
        return 0;
    }
    if(ct_0 == 0 && (a[1] != 0 || a[2] != 0))
        ct_0++;
    if(ct_1 == 0 && (a[1] != 0 || a[2] != 0))
        ct_1++;
    //cout << ct_0 << ' ' << ct_1 << endl;
	if((ct_0*(ct_0-1) != 2*a[0]) || (ct_1*(ct_1-1) != 2*a[3]) || (ct_1*ct_0 != a[1] + a[2]) || a[0] < 0 || a[1] < 0 || a[2] < 0 || a[3] < 0 || ct_0 < 0 || ct_1 < 0)
	{
		cout << "Impossible";
		return 0;
	}
	string ans;
	for(int i = 0; i < ct_0; i++)
	{
		ans += '1';
	}
	for(int i = 0; i < ct_1; i++)
	{
		ans += '1';
	}
	ll ct_01 = ct_0*ct_1, ct_10 = 0;
	ll end_pos_0 = ct_0 - 1;

	while(ct_01 != a[1])
	{
		ll req = ct_01 - a[1];
		ll n_1 = min(req, ct_1);
		ans[end_pos_0+n_1] = '0';
		end_pos_0--;
		ct_01 -= n_1;
	}
	for(int i = 0; i <= end_pos_0; i++)
		ans[i] = '0';
	cout << ans;
	return 0;
}
