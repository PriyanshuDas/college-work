#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define loop(i,l,r) for(int i = l; i < r; i++)

using namespace std;

int main()
{
	int N;	cin >> N;
	int arr[200001];
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int flag = 0;
	for(int i = 0; i < N; i++)
	{
		//pf("@(%d, %d)\n", i, flag);
		if(arr[i]%2 == 0)
		{
			continue;
		}
		else if(arr[i]%2 == 1)
		{
			int f1 = 1;
			if(i < N-1 && arr[i+1] != 0)
			{
				f1 = 0;
				arr[i+1]--;
			}
			flag = max(flag, f1);
		}
	}
	if(flag == 1)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}
