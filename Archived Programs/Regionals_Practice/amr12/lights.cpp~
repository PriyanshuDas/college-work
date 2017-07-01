#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ins insert
#define n_max 1000001

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		string s[n];
		
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		
		vector<int>v;
		
		int cnt=0;
		
		for(int i=0;i<n;i++)
		{
			cnt=0;
			for(int j=0;j<m;j++)
			{
				if(s[i][j]=='*')
				cnt++;
			}
			v.pb(cnt);
		}
		
		sort(v.begin(),v.end());
		
		for(int i=0;i<n&&k;i++)
		{
			if( (m-v[i]) > v[i] )
			{
				v[i]=m-v[i];
				k--;
			}
		}
		
		if(k%2==1)
		{
			sort(v.begin(),v.end());
			v[0]=m-v[0];
		}
		int sum=0;
		for(int i=0;i<n;i++)
			sum+=v[i];
		cout<<sum<<endl;
	}
	return 0;
}
