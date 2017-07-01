#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define mp make_pair
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-8;
const double INF = (1<<20);

double min(double a, double b)
{
	if(a < b)
		return a;
		
	else
		return b;
}

int cmpdouble(double d)
{
	if(fabs(d)<EPS) return 0;
	return d>EPS?1:-1;
}



struct Point{
	double x, y;
	Point(){}
	Point(double a, double b) : x(a),y(b) {}
	bool operator == (Point b)
		{return ((x == b.x) && (y==b.y));}
		
	bool operator < (Point b)
		{return ((x < b.x) || ((x == b.x) && (y<b.y)));}
		
	Point operator + (Point b) {return Point(x + b.x, y + b.y);}
	Point operator - (Point b) {return Point(x-b.x, y-b.y);}
	Point operator * (double c) {return Point(x*c,y*c);}
	Point operator / (double c) {
		if(!c)
			return Point(x,y);
		return Point(x/c,y/c);
	}
};

struct Line{
	double A, B, C;
	Point a, b;
	Line(){}
	Line(double _a, double _b, double _c){
		A = _a, B = _b, C = _c;
		if(cmpdouble(_a)==0)
		{
			a = Point(0,(_c/_b));
			b = Point(1, (_c/_b));
		}
		else if(cmpdouble(_b)==0)
		{
			a = Point(_c/_a , 0);
			b = Point(_c/_a , 1);
		}
		else
		{
			a = Point(0, _c/_b);
			b = Point(1, (_c - _a)/_b);
		}
	}
	Line(Point p1, Point p2)
	{
		a = p1, b = p2;
		A = p2.y - p1.y;
		B = p1.x - p2.x;
		C = (A*p1.x + B*p1.y);
	}
	bool operator == (Line l)
	{
		Line p = *this;
		return ((a==l.a) && (b==l.b));
	}
};

double sqr(double x)
{	return (x*x); }

double crossp(const Point &O, const Point &A, const Point &B)
{
	return ((A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x));
}

Point linelineinter(Line a, Line b)
{
	double temp;
	temp = (1.0 / (a.A * b.B - a.B * b.A));
	Point ans(a.C*b.B - b.C*a.B, a.A*b.C - b.A * a.C);
	ans = ans*temp;
	return ans;
}

bool Pointonsegment(Line l, Point p)
{
	if(cmpdouble(crossp(l.a, p, l.b) == 0))
	{
		if(p.x >= min(l.a.x, l.b.x) && p.x<=max(l.a.x, l.b.x))
			if(p.y >= min(l.a.y, l.b.y) && p.y <= max(l.a.y, l.b.y))
				return true;
	}
	return false;
	
}

bool dointersect(Line a, Line b)
{
	Point ans;
	ans = linelineinter(a,b);
	bool flag1=0, flag2=0;
	flag1 = Pointonsegment(a, ans);
	flag2 = Pointonsegment(b, ans);
	if(flag1 && flag2)
		return true;
		
	return false;
}

int pointpolygon(vector <Point> poly, Point p)
{
	int n = poly.size();
	Point dummy(INF, 0);
	Line l(p,dummy);
	int intersections=0;
	for(int i=0;i < n;i++)
	{
		Line temp(poly[i], poly[(i+1)%n]);
		if(dointersect(l, temp))
			intersections++;
	}
	if(intersections & 1) return -1;
	
	return 1;
}

double dist_points(Point X, Point Y)
{
	double x  = sqr(Y.x - X.x);
	double y = sqr(Y.y - X.y);
	return sqrt(x + y);
}

vector <Point> hull(vector <Point> P)
{
	int n=P.size(), k=0;
	vector <Point> X(2*n);
	sort(P.begin(),P.end());
	for(int i=0;i<n;i++)
	{
		while(k>=2)
		{
			if(crossp(X[k-2], X[k-1],P[i]) <= 0)
				k--;
			
			else
				break;
		}
		X[k++]=P[i];
	}
	for(int i=n-2, t=k+1;i>=0;i--)
	{
		while(k>=t)
		{
			if(crossp(X[k-2], X[k-1], P[i]) < 0.0)
				k--;
			else
				break;
		}
		X[k++] = P[i];
	}
	X.resize(k-1);
	return X;
}





int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		Point a, b, c;
		cin>>a.x>>a.y>>b.x>>b.y;
		vector<Point> P;
		double dist=INF;
		for(int i=0;i<4;i++)
		{
			cin>>c.x>>c.y;
			P.pb(c);
		}
		int flag1, flag2;
		flag1 = pointpolygon(P, a);
		flag2 = pointpolygon(P, b);
		if(flag1==-1 && flag2==-1)
		{
			dist = dist_points(a, b);
			//cout<<"here\n";
			pf("%0.11lf\n", dist);
			continue;
		}
		if(flag1==-1)
		{
			cout<< -1 << endl;
			continue;
		}
		
		if(flag2 == -1)
		{
			cout<< -1 << endl;
			continue;
		}
		P.pb(a), P.pb(b);
		sort(P.begin(),P.end());
		P = hull(P);
		for(int i=0;i<P.size();i++)
		{
			cout<< P[i].x <<" " << P[i].y << endl;
		}
		int inda, indb;
		int flag=-1;
		for(int i=0;i<P.size();i++)
		{
			if(P[i] == a)
			{
				flag++;
				inda  = i;
			}
			if( P[i]==b)
			{
				flag++;
				indb = i;
			}
		}
		if(flag<1)
		{
			dist = dist_points(a, b);
			cout<<"here\n";
			pf("%0.11lf\n", dist);
			continue;
		}
		double tempdist=0;
		for(int i=inda;i!=indb;i= (i+1)%6)
		{
			tempdist+= dist_points(P[i%6], P[(i+1)%6]);
		}
		dist = min(dist, tempdist);
		pf("%0.11lf\n", dist);
		tempdist=0;
		for(int i=indb;i!=inda;i = (i+1)%6)
		{
			tempdist+= dist_points(P[i%6], P[(i+1)%6]);
		}
		dist = min(dist, tempdist);
		//cout<< dist << endl;
		pf("%0.11lf\n", dist);
	}
	return 0;
}
