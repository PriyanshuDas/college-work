#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

ll merge(ll arr[], ll begin, ll middle, ll end)
{
	ll inv = 0, l = begin, r = middle;
	ll s1 = middle - begin,	s2 = end - middle;
	ll tempa[s1];
	ll tempb[s2];
	
	for(ll i = 0; i < s1; i++)
		tempa[i]  = arr[i+l];
	
	for(ll i = 0; i < s2; i++)
		tempb[i]  = arr[i+r];
		
	ll t1 = 0, t2 = 0;
	while(t1 < s1 && t2 < s2)
	{
		if(tempa[t1] <= tempb[t2])
		{
			arr[begin+t1+t2] = tempa[t1];
			t1++;
		}
		else if(tempb[t2] < tempa[t1])
		{
			arr[begin+t1+t2] = tempb[t2];
			inv += (s1 - t1);
			t2++;
		}
	}
	if(t1 < s1)
	{
		while(t1 != s1)
		{
			arr[begin+t1+t2] = tempa[t1];
			t1++;
		}
	}
	if(t2 < s2)
	{
		while(t2 != s2)
		{
			arr[begin+t1+t2] = tempb[t2];
			t2++;
		}
	}
}

ll mergesort(ll arr[], ll begin, ll end)
{
	ll inversion = 0;
	ll middle = ((begin+end)+1)>>1;
	if(begin < end - 1)
	{
		inversion = mergesort(arr, begin, middle);
		inversion += mergesort(arr, middle, end);
		inversion += merge(arr, begin, middle, end);
	}
	return inversion;
}

int main()
{
	ll n = 0;
	cin >> n;
	ll arra[n];
	for(ll i = 0; i < n; i++)
	{
		cin >> arra[i];
	}
	mergesort(arra, 0, n);
	for(ll i = 0; i < n; i++)
	{
		pf("%lld ", arra[i]);
	}
	cout << endl;
	return 0;
}
