#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void inversion(vector< int > s, int& p, int sz)
{
	int n=s.size();
	int cnt=0, minn=20;
	for(int i=0;i<n;i++)
	{
		for(int j =i+1;j<n;j++)
			if(s[i]>s[j])
				cnt++;
	}
	minn=min(minn,cnt);
	
	if( p < ((sz*sz - sz)/2 - minn + 1))
	{
		p = (sz*sz - sz)/2;
		p = p - minn + 1;
		
	}
}

int main()
{
	int n;
	cin>>n;
	string s; 
	vector<string> v;
	map <string, int> ms,vtt;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		vtt[s]=i;
		ms[s]++;
		v.pb(s);
	}
	
	int m, k;
	cin>>m;
	
	int p=0, ind=50, p2=0;

	for(int i=0;i<m;i++)
	{
		vector <string> gps;
		vector <int> vs;
		cin>>k;
		int flag = 0;
		
		for(int j=0;j<k;j++)
		{
			cin>>s;
			if(ms[s]==1)
				vs.pb(j), gps.pb(s);
		}
		
		/*for(int temp = 0; temp< vs.size();temp++)
				cout<<vs[temp] << "/";
		
		cout<< endl;*/
		
		
		sort(v.begin(),v.end());
		
		do
		{
			/*for(int yy=0;yy<n;yy++)
				cout<< v[yy] << " ";*/
			vector <int> pps;
			flag=0;
			int kk=0;
				for(int l=0;l<vs.size() && kk < n;l++)
				{
					if(v[kk] == gps[l])
						kk++, pps.pb(vtt[gps[l]]);
				}
				if(kk==n)
					flag=1;
			
			if(!flag)
				continue;
				
				
			
				
			/*for(int yy=0;yy<n;yy++)
				cout<< pps[yy] << " ";
			cout<< endl;*/
			inversion(pps, p, n);
			/*cout<<"pp\n";
			for(int temp = 0; temp < pps.size();temp++)
				cout<< pps[temp] << " ";
			cout << endl;*/
			if(p>p2)
			{
				p2 = p;
				ind = i;
			}
		}while(next_permutation(v.begin(),v.end()));
	}
	
	if(p2==0)
		cout<<"Brand new problem!\n";
		
	else
	{
		cout<< ind+1 <<endl;
		printf("[:");
		for(int i=0;i<p2;i++)
			printf("|");
			
		printf(":]\n");
	}
	
	//for(int i
	return 0;

}
