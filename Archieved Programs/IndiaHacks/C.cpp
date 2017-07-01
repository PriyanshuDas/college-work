#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

int n;
vector <int> arr;
vector <int> imp;

int check (int pos)
{
	int ans = 0;
	for(int i = 0 ; i < n-1; i++)
	{
		int flag = 0;
		swap(arr[pos], arr[i]);
		for(int j = 0; j < imp.size(); j++)
		{
			if(j%2 == 0 && arr[j] >= arr[j+1])
				flag = 1;
			if(j%2 == 1 && arr[j] <= arr[j+1])
				flag = 1;
		}
		if(i%2 == 0 && arr[i] >= arr[i+1])
			flag = 1;
		if(i%2 == 1 && arr[i] <= arr[i+1])
			flag = 1;
		if(!flag)
			ans++;
		swap(arr[pos], arr[i]);
	}
	return ans;
}

int main()
{
	int n;	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int tmp;	sf("%d", &tmp);
		arr.pb(tmp);
	}
	for(int i = 0; i < n-1; i++)
	{
		if(i%2 == 0 && arr[i] >= arr[i+1])
			imp.pb(i);
		else if(i%2 == 1 && arr[i] <= arr[i+1])
			imp.pb(i);
	}
	cout << "Important positions are : ";
	for(int i = 0; i < imp.size(); i++)
	{
		cout << imp[i] << ' ';
	}
	cout << endl;
	if(imp.size() > 9)
	{
		cout << 0;
		return 0;
	}
	ll fin_ans = 0;
	for(int i = 0; i < imp.size(); i++)
	{
		fin_ans += check(imp[i]);
	}
	cout << fin_ans;
	return 0;
}
