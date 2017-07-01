#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define ins insert

using namespace std;

int main()
{
	int n;
	cin>>n;
	ll a,b,c;
	pair< ll , pair<ll, ll > > p[n];
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		p[i]=mp(abs(a-b),mp(a,b));
		
	}
	sort(p,p+n);
	pair<ll, ll > q;
	ll ans=0,sum=0;
	
	for(int i=n-1;i>=0;i--)
	{
		a=p[i].first;
		q=p[i].second;
		//cout<<ans<<endl;
		if(ans<q.first)
		{
			sum+=abs(ans-q.first);
			ans=a;
		}
		else
		{
			ans=(ans-q.first) + a;
		}
	}
	//cout<<ans<<endl;
	cout<<sum<<endl;
	return 0;
}
