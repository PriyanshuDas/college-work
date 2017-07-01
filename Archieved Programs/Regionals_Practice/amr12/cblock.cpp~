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
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		char ch='a';
		string so=s;
		
		int cnt=0,f=1;
		map<int,int>m; 
		int ind=0,mcount=0;
		for(int i=0;i<n;i++)
		{
			if(ch!=s[i])
			{
				if(cnt>=k)
				{
					mcount=max(cnt,mcount);
					f=0;
					break;
				}
				cnt=1;
				ch=s[i];
				ind=i;
			}
			else
			{
				cnt++;
			}
			mcount=max(cnt,mcount);
		}
		//cout<<"ind="<<ind;
		if(mcount>=k)
		{
			f=0;
		}
		if(f)
		{
			cout<<"-1\n";
			continue;
		}
		
		
		
		int spc=1;
		m[ind]=1;
		for(int i=ind;i<n-1;i++)
		{
			if(s[i]==s[i+1])
			{
				m[i+1]=1;
				spc++;	
			}
			else
			{
				break;
			}
		}
		//cout<<"spc="<<spc;
		int ans;
		char col;
		if(m[0]==1 && m[n-1]==1)
		{
			ans=0;
			//cout<<0;;
		}
		else if(m[0]==1)
		{
			ans=1;
			col=s[n-1];
			ind=n-k;
			for(int i=n-2;i>=0;i--)
			{
				if(m[i])
					break;
				if(s[i]!=col || (i<ind))
				{
					ind=i-(k-1);
					col=s[i];
					ans++;
				}
			}
			//cout<<1;
		}
		else if(m[n-1]==1)
		{
			ans=1;
			col=s[0];
			ind=k-1;
			for(int i=1;i<n;i++)
			{
				if(m[i])
				break;
				if(s[i]!=col || i> ind)
				{
					ind=i+(k-1);
					col=s[i];
					ans++;
				}
			}
			//cout<<2;
		}
		else
		{
			ans=1;
			col=s[0];
			ind=k-1;
			for(int i=1;i<n;i++)
			{
				if(m[i])
				break;
				if(s[i]!=col || i> ind)
				{
					ind=i+(k-1);
					col=s[i];
					ans++;
				}
			}
			//cout<<ans;
			ans++;
			col=s[n-1];
			ind=n-k;
			for(int i=n-2;i>=0;i--)
			{
				if(m[i])
					break;
				if(s[i]!=col || (i<ind))
				{
					ind=i-(k-1);
					col=s[i];
					ans++;
				}
			}
			//cout<<3;
		}
		//cout<<ans;
		ans+=(spc/k);
		if(spc%k)
		ans++;
		
		cout<<ans<<endl;	
	}
	return 0;
}
