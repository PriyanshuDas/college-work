#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
	int n;
	cin>>n;
	int maxx = 0;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(maxx < x )
			maxx=x;
	}
	cout<< maxx << endl;
	return 0;
}
