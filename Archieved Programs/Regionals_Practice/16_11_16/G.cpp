#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int N, M;
		cin>>N>>M;
		vector<double> vd;
		double x, z;
		for(int i=0;i<N;i++)
		{
			cin>>x;
			vd.pb(x);
		}
		
		
		sort(vd.rbegin(),vd.rend());
		double temp;
		
		for(int m=0;m<M;m++)
		{
			if(m==0)
				pf("Case %d:\n", t+1);
			cin>>z;
			vector < pair <double, int> > vp;
			pf("Scenario %d:\n", m+1);
			for(int i=0;i<N;i++)
			{
				
				temp = (z/vd[i]);
				//cout<< z << " "<< vd[i]<<" " << temp << endl;
				if(temp < 0.99)
					continue;
					
				else
				{
					//cout<< z << " "<< vd[i]<<" " << temp << endl;
					int t2 = (int)temp;
					if(temp - t2 > 0.99)
						t2++;
					z -= (vd[i] * t2);
					vp.pb(mp(vd[i],t2));
				}
			}
		
			//cout<<vp[vp.size()-1].first<<endl;
			for(int i=0;i<vp.size();i++)
			{
				if(vp[i].first <= 0.99)
					pf("%.2lf ", vp[i].first);
				else
					cout<<(int)vp[i].first << " ";
					
				cout<< vp[i].second << endl;
			}
		
		}

	}
	return 0;
}
