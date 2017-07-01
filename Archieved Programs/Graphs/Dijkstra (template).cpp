#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define mp make_pair
using namespace std;
struct compare  
 {  
   bool operator()(const pair<int,int>& l, const pair<int,int>& r)  
   {  
       return l.first > r.first;  
   }  
 };

int main()
{
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		int v, k;
		cin >> v >> k;
		vector <pair <int, int> > Con[10001];
		long long int dist[10001];
		for (int j = 0; j < 10001; j++)
		{
			dist[j] = 400000000;
		}
		for (int j = 0; j < k; k++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			Con[a].pb(mp(b,c));
		}
		int A, B;
		cin >> A,B;
		priority_queue<pair<int,int> ,vector<pair<int,int> >,compare>p;
		p.push(mp(0,A));
			while(!p.empty())
			{
				long long int D =p.top().fir;
				long long int P =p.top().sec;
				p.pop();
				if(D > dist[P])
					continue;
				if(P == B)
				{
					printf("%lld\n",D);
					break;
				}
				for(int k=0; k<Con[P].size(); k++)
				{
					long long int new_n = Con[P][k].first;
					long long int new_d = Con[P][k].second;
					if(D + new_d < dist[new_n])
					{
						dist[new_n]=D + new_d;
						p.push(mp(D+ new_d, new_n));
					}
				}
			}
	}

	return 0;
}