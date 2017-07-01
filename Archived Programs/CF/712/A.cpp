#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define pi2 pair <ll, ll>
#define pi3 pair<ll, pi2>
#define pi4 pair<pi2, pi2>
#define loop(i, l, r) for(ll i = l; i < r; i++)
#define ins insert

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector <int> A, B;
	for(int i = 0; i < N; i++)
	{
		int tmp;	cin >> tmp;
		A.pb(tmp);
	}
	for(int i = 1; i < N; i++)
	{
		int tmp = A[i] + A[i-1];
		B.pb(tmp);
	}
	B.pb(A[N-1]);
	for(int i = 0; i < B.size(); i++)
		cout << B[i] << ' ';
	return 0;
}
