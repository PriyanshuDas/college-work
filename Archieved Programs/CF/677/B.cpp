#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
	int n, h, k, curr = 0, time = 0;	cin >> n >> h >> k;
	int arr[100001] = {0};
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int i = 0;
	while(i < n)
	{
		while(i < n && curr + arr[i] <= h)
		{
			curr += arr[i];	i++;
		}
		curr = max(0, curr-k) ;	time++;
	}
	while(curr > 0)
	{
		curr -= k;
		time++;
	}
	cout << time;
	return 0;
}
