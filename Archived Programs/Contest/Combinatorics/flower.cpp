#include<bits/stdc++.h>
#define ll long long int
#define MOD 150000
using namespace std;

int main()
{
	 ll r, g, b;
	 cin >> r >> g >> b;
	 //ll ans = 0;
	 ll ans = (r/MOD)*(MOD/3) + (g/MOD)*(MOD/3) + (b/MOD)*(MOD/3);
	 //cout << ans << endl;
	 r %= MOD;
	 g %= MOD;
	 b %= MOD;
	 //cout << r << '\t' << g << '\t' << b << endl;
	 ll ans_1 = ans + r/3 + g/3 + b/3 + min(r%3, min(g%3, b%3));
	 for(int i = 0; i <= min(r, min(g, b)); i++)
	 {
	 	ll r_n = r - i;
	 	ll g_n = g - i;
	 	ll b_n = b - i;
	 	ll nu_ans = i + ans + r_n/3 + g_n/3 + b_n/3 + min(r_n%3, min(g_n%3, b_n%3));
	 	//printf("r - %d, g - %d, b - %d\t new_ans = %lld\n", r_n, g_n, b_n, nu_ans);
	 	if(nu_ans > ans_1)
	 		ans_1 = nu_ans;
	 }
	 cout << ans_1;
}
