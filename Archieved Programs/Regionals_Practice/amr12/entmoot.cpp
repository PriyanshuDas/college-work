#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ins insert
#define n_max 1000001
#define max_t 4000001
#define del 0.00001

using namespace std;



struct Point{
	double x, y;
	friend ostream& operator << (ostream &s, Point& p)
	{
		s << p.x << " " << p.y << endl;
		return s;
	}
	friend istream& operator >> (istream &s, Point& p)
	{
		s >> p.x >> p.y;
		return s;
	}
};

double dist(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool circleint(Point p1, double r1, Point p2, double r2)
{
	double d;
	d = dist(p1, p2);
	if((d > (r1+r2)))
		return false;
	else
		return true;
}

vector <Point> P;
int vel[101];
int N;

bool allint(double m)
{
	double rad1, rad2;
	for(int i=0;i<N;i++)
	{
		rad1 = m*vel[i];
		for(int j=1;j<N;j++)
		{
			rad2 = m*vel[j];
			if(!circleint(P[i], rad1, P[j], rad2))
			{
				return false;
			}
		}
	
	}
	return true;
	/*if(abs(m - 10) < 0.001)
	{
		return false;
	}
	return true;*/
}

double binsearch()
{
	double l = 0, r = max_t;
	int N = P.size();
	while((r-l) > del)
	{
		double m = (l+r)*0.5;
		//pf("(%lf\t%lf)\n", l, r);
		int flag=0;
		
		if(allint(m))
		{
			r = m;
			continue;
		}
		else
		{
			l = m;
			continue;
		}
	}
	return r; 
}

int main()
{
	//cout << binsearch();
	int T;
	cin>>T;
	while(T--)
	{
		cin>>N;
		Point z;
		for(int i=0;i<N;i++)
		{
			cin>> z;
			cin>>vel[i];
			P.pb(z);
		}
		double time;
		time = binsearch();
		pf("%.5lf\n", time);
		P.clear();
	}
	return 0;
}
