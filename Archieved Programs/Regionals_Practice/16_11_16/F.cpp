#include <bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define ll long long int
#define ull unsigned long long int
#define mp make_pair
#define pb push_back
#define ins insert

struct compare{
	bool operator()(const ull& l ,  const ull& r)
	{
		if(l>r)
		return true;
		else
		return false;
	}
};
int main()
{
	int t,n,k;
	ull a,ans;
	cin>>t;
	for(int iii=1;iii<=t;iii++)
	{
		ans=0;
		priority_queue<ull , vector <ull > ,compare > p;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			p.push(a);
		}
		int l;
		if(n==1)
		{
			printf("Case %d: %d\n",iii,0);
			continue;
		}
		while(!p.empty())
		{
			l=0;a=0;
			while(!p.empty() && l < k)
			{
				l++;
				a+=p.top();
				p.pop();
			}
			if(p.empty())
			{
				ans+=a;
			}
			else
			{
				ans+=a;
				p.push(a);	
			}
		}
		printf("Case %d: %llu\n",iii,ans);
	}
	
	return 0;
}
