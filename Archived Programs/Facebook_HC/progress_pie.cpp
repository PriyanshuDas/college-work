#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define ins insert
#define PI 3.1415926535897932384626

using namespace std;

ll r = 50;

bool check(int p, int x, int y)
{
	double ang1 = PI/2;
	double ang2 = atan((double)y/(double)x);
	if(ang2 < 90)
		ang2 += 2*PI;
	double ang = ang2 - ang1;
	ang = 2*PI - ang;
	//pf("%lf\t%d\n", ang*180/PI, (x*x+y*y));
	if(ang/(2*PI)*100 <= p && (x*x+y*y) <= 50*50)
		return true;
	return false;
}

int main()
{
	int T;	sf("%d", &T);
	for(int t = 0; t < T; t++)
	{
		int p, x, y;	sf("%d%d%d", &p, &x, &y);
		x-= 50;
		y-= 50;
		if(check(p, x, y))
			pf("Case #%d: black\n", t+1);
		else
			pf("Case #%d: white\n", t+1);
	}
	return 0;
}
