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
	for(int t= 0; t < T; t++)
	{
		int N;	cin >> N;
		int n_1 = 0, tot = 0;
		for(int n = 0; n < N; n++)
		{
			int tmp;	cin >> tmp;
			tot = (tot^tmp);
			if(tmp == 1)
				n_1++;
		}
			if((n_1 == N && N%2 == 0) || (n_1 != N && tot != 0))
			{
				cout << "First\n";
			}
			else
				cout << "Second\n";
	}
	return 0;
}
