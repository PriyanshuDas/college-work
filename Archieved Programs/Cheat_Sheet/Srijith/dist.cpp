#include <bits/stdc++.h>

using namespace std;

double dist_points(double x1,double y1,double x2,double y2)
{
	double x = (x2-x1)*(x2-x1);
	double y = (y2-y1)*(y2-y1);
	return sqrt(x+y);
}

int main()
{
	float x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "Distance is : " << setprecision(99) << dist_points(x1, y1, x2, y2)<< endl;
	return 0;
}
