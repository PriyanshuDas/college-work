#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int
#define ull unsigned long long int
#define fi first
#define se second

using namespace std;

typedef struct Point
{
public:
	double x, y;
} Point;

double distance (Point X, Point Y)
{
	return sqrt((X.x-Y.x)*(X.x-Y.x) + (X.y-Y.y)*(X.y-Y.y));
}
class LineSegment
{
public:
	double x1, y1;
	double x2, y2;
	double m;
	LineSegment(double x_1 = 0, double y_1 = 0, double x_2 = 0, double y_2 = 0)
	{
		x1 = x_1, y1 = y_1, x2 = x_2, y2 = y_2;
		m = (y2-y1)/(x2-x1);
	}
};



int main()
{
	return 0;
}