#include <bits/stdc++.h>

#define pf printf
#define sf scanf
using namespace std;

int main()
{
	double pi = acos(-1);
	double a, b;
	double rt2= sqrt(2);
	double lim = pi*135/180;
	cin >> a >> b;

	double a2 = a*a;
	double b2 = b*b;
	double a3 = a2*a;
	double b3 = b2*b;
	double a4 = a2*a2;
	double b4 = b2*b2;

	double ang_2 = pi + atan(-1*a*(rt2*b + a)/(b*(rt2*a + b)));
	double ang = (pi + atan(-1*a*(rt2*b + a)/(b*(rt2*a + b))))/2;
	double ans1 = a*b*sin(ang)*sin((3*pi/4)-ang)+0.25*(a*a*sin(2*ang) +b*b*sin(3*pi/2-2*ang));
	double ang2 = (2*pi + atan(-1*a*(rt2*b + a)/(b*(rt2*a + b))))/2;
	double ans2 = a*b*sin(ang2)*sin((3*pi/4)-ang2)+0.25*(a*a*sin(2*ang2) +b*b*sin(3*pi/2-2*ang2));
	//double ans = max(ans1, ans2);
	double ans3 = ((2*rt2*a2*b2 + 3*a3*b + 3*a*b3 + rt2*(a4+b4))/(a4+b4+4*a2*b2 + 2*rt2*a*b*(a2+b2)) + a*b/(2*rt2));
	double expec = ((a2+b2)/4 + (a*b)/rt2);
	double ans4 = (a*sin(ang_2)*(a + rt2*b) - b*cos(ang_2)*(rt2*a + b) + rt2*a*b)*0.25;
	double ans = min(ans1, ans4);
	printf("%0.25lf\n", ans1);
	return 0;
}