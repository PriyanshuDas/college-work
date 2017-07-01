#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long ing

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int n; 	cin >> n;
		int tot = 0;
		for(int i = 0; i < n; i++)
		{
			int tmp;	cin >> tmp;
			tot = (tot^tmp);
		}
		if(tot != 0)
			cout << "First\n";
		else
			cout << "Second\n";
	}
	return 0;
}
