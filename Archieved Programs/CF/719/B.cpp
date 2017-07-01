#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2>
#define pi4 pair<pi2, pi2>
#define loop(i, l, r) for(int i = l; i < r; i++)

using namespace std;

int main()
{
	int n;	cin >> n;
	string s;	cin >> s;
	//1- rbrb
	int r_c = 0, b_c = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(i%2 == 0 && s[i] == 'b')
			b_c++;
		if(i%2 == 1 && s[i] == 'r')
			r_c++;
	}
	int swap = min(b_c, r_c), paint = abs(b_c - r_c);
	int ans_1 = swap+paint;
	//pf("Ans_1, (%d, %d)\n", swap, paint);
	//2 - brbr
	r_c = 0, b_c = 0;
	for(int i = 0; i < n; i++)
	{
		if(i%2 == 1 && s[i] == 'b')
			b_c++;
		if(i%2 == 0 && s[i] == 'r')
			r_c++;
	}
	swap = min(b_c, r_c);	paint = abs(b_c - r_c);
	int ans_2 = swap+paint;
	
	int ans = min(ans_1, ans_2);
	//pf("Ans_2, (%d, %d)\n", swap, paint);
	cout << ans;
	return 0;
}
