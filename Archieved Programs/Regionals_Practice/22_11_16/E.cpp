#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int

using namespace std;

vector <double> coeff(int x1, int y1, int x2, int y2)
{
	int a, b, c;
	y2 = y2 - y1;
	x2 = x2 - x1;
	if(y2 < 0)
	{
		x2 = -x2;
		y2 = -y2;
	}
	vector <double> v;
	v.pb((double)y2), v.pb((double)-x2), v.pb((double)(x2*y1) - (double)(y2*x1));
	return v;
}

int main()
{
	int N;
	cin>>N;
	for(int n=0;n<N;n++)
	{
		int K;
		cin>>K;
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		int cnt=0;
		if(x1==x2)
		 cout<< abs(y2-y1) << endl;
		else if(y1==y2)
			cout<< abs(x2-x1) << endl;
			
		else
		{
			
			vector <double> cof = coeff(x1, y1, x2, y2);
			double temp;
			for(int i=min(x1,x2)+1;i<=max(x1,x2);i++)
			{
				//cout<< cof[0] <<" " << cof[1] << " " << cof[2] << endl;
				temp = (double)((double)-cof[2] - ((double)cof[0]*(double)i))/(double)cof[1];
				cout << temp << endl;
				if(temp > (int)(temp))
					cnt++;
				else
					cnt+=2;
			}
		}
		cnt+= abs(y1-y2);
		cnt++;
		cout<< cnt <<endl;
	}
	
}
