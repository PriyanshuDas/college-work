#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair

using namespace std;


/*Algorithm :- 	Find F(p, L), F(p, L) = F'(p, L+1) - 1
				F'(p, L) = Summation(f(n)) where 0 <= n < L
							f(n) = 1, if( Sum of base-p(n), excluding n0 is x*p
								 = 0, otherwise

Let G(p, L) be count of 0 <= n < L, such that sum of base-p(n) %p == 0

If ( L%p == 0)

	F'(p, L) = p*G(p, L/p)
	
Else

	F'(p, L) = p*G(p, L/p) + L%p*(base-p-sum(L/p)%p == 0)
	
To Find G(p, L)

If (L%p == 0)

	G(p, L) = L/p

Else

	G(p, Q + R) = Q + 1	(If (-(sum-base-p(Q)%p)%p) < R)
	G(p, Q + R) = Q		(Otherwise)
*/

ll sum_p(ll p, ll L)
{
	ll ans = 0, L2 = L;
	while(L2 > 0)
	{
		ans += L2%p;
		L2/=p;
	}
	//pf("Sum (%lld, %lld) == %lld\n", p, L, ans);
	return ans;
}

ll G(ll p, ll L)
{
	if(L%p == 0)
		return L/p;
	ll sum_base_p = sum_p(p, L/p);
	ll ans = L/p;
	if((p - sum_base_p%p)%p < L%p)
	{
		ans++;
	}
	//pf("G(%lld, %lld) == %lld\n", p, L, ans);
	return ans;
}

ll F2(ll p, ll L)
{
	ll ans = 0;
	ans = p*G(p, L/p);
	if(L%p != 0 && sum_p(p, L/p)%p == 0)
	{
		ans += L%p;
	}
	//pf("F2(%lld, %lld) == %lld\n", p, L, ans);
	return ans;
}

ll F(ll p, ll L)
{
	return F2(p, L+1)-1;
}

int main()
{
	ll T;	cin >> T;
	for(int i = 0; i < T; i++)
	{
		ll p, L;	sf("%lld%lld", &p, &L);
		ll ans = F(p, L);
		pf("%lld\n", ans);
	}
	return 0;
}
