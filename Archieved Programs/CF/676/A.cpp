#include <bits/stdc++.h>

#define ll long long int
#define mp make_pair

using namespace std;

int main()
{
	int n;	cin >> n;
	int arr[101], min_v = 9999, max_v = 0;
	int min_pos = 0, max_pos = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if(arr[i] == n)
		{
			max_pos = i;
		}
		if(arr[i] == 1)
		{
			min_pos = i;
		}
	}
	int d1=min_pos, d2 = max_pos, d3 = abs(n-1-max_pos), d4 = (n-1-min_pos);
	int ans = max(max(d1,d2),max(d3,d4));
	cout << ans;
	return 0;
}
