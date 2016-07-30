#include <bits/stdc++.h>

#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define loop(n) for(int i = 0; i < n; i++)
#define sf scanf
#define pf printf

using namespace std;

int main()
{
	int N;
	cin >> N;
	int arr[100001];
	loop(N)
		sf("%d", &arr[i]);
	ll max_sum = 0;
	ll curr_sum = 0;
	loop(N)
	{
		curr_sum += arr[i];
		if(arr[i] == 0)
			curr_sum = 0;
		else if(curr_sum > max_sum)
			max_sum = curr_sum;
		if(curr_sum < 0)
			curr_sum = 0;
	}
	cout << max_sum;
	return 0;
}
