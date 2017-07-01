#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
#include <queue>
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define mp make_pair
#include <queue>
using namespace std;
struct compare  
 {  
   bool operator()(const pair<int,int>& l, const pair<int,int>& r)  
   {  
       return l.fir > r.fir;  
   }  
 };

int main(){
	int test,n;
	scanf("%d",&test);
	while(test--){
		int dist[10002];
		
		vector<pair<int,int> >v[10002];
		scanf("%d",&n);
		string s;
		int val=0,num,x,y;
		map<string,int>m;
		for(int i=0;i<n;i++){
			cin>>s;
			m[s]=val;
			scanf("%d",&num);
			while(num--){
				scanf("%d%d",&x,&y);
				v[val].pb(mp(--x,y));

			}
			val++;
		}
		/*for(int i=0;i<n;i++){
			for(int j=0;j<v[i].size();j++){
				cout<<v[i][j].fir<<" "<<v[i][j].sec<<endl;
			}
			cout<<"twerp"<<endl;
		}*/

		scanf("%d",&num);
		string a,b;
		int src,dest;
		while(num--){
			for(int i=0;i<10002;i++)
			dist[i]=1000000000;
			priority_queue<pair<int,int> ,vector<pair<int,int> >,compare>p;
			cin>>a>>b;
			src=m[a];
			dest=m[b];
			p.push(mp(0,src));
			dist[src]=0;
			while(!p.empty()){
				x=p.top().fir;
				y=p.top().sec;
				p.pop();
			//	cout<<x<<" "<<y<<endl;
				if(x>dist[y])
						continue;
				if(y==dest){
					printf("%d\n",x);
					break;
				}
				for(int i=0;i<v[y].size();i++){
					if(x+v[y][i].sec<dist[v[y][i].fir]){
						dist[v[y][i].fir]=x+v[y][i].sec;
						p.push(mp(dist[v[y][i].fir],v[y][i].fir));
					}	
				
			
				}
			}
			cout<<num<<" "<<test<<endl;
		}

	}

	return 0;
}