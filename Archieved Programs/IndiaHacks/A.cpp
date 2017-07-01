#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
	int n;	cin >> n;
	vector <int> arr;
	for(int i = 0; i < n; i++)
	{
		int tmp;	cin >> tmp;
		arr.pb(tmp);
	}
	sort(arr.begin(), arr.end());
	int ct = 0;
	for(int i = 0; i < n; i++)
	{
		int curr = arr[i];
		ct = 1;
		for(int j = 0; ct < 3 && i+j < n && arr[i+j] - arr[i] <= 2; j++)
		{
			if(arr[i+j] == curr)
				continue;
			curr = arr[i+j];
			ct++;
		}
		if(ct == 3)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
