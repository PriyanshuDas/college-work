#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define pb push_back
#define ins insert

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int n;	cin >> n;
		ll total = 0;
		ll tmp;	cin >> tmp;
		for(int i = 1; i < n; i++)
		{
			cin >> tmp;
			if(i%2 == 1)
				total = (total^tmp);
		}
		//cout << "Total : " << total << endl;
		if(total == 0)
			cout << "Second\n";
		else
			cout << "First\n";
	}
	return 0;
}
