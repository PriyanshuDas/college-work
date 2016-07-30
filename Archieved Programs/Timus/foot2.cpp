#include <bits/stdc++.h>

#define pf printf
#define sf scanf
using namespace std;

int main()
{
	double pi = acos(-1);
	float a, b;
	float rt2= sqrt(2);
	float lim = pi*135/180;
	cin >> a >> b;

	float a2 = a*a;
	float b2 = b*b;
	float a3 = a2*a;
	float b3 = b2*b;
	float a4 = a2*a2;
	float b4 = b2*b2;

	float ang_2 = atan(a*(rt2*b + a)/(b*(rt2*a + b)));
	float ang = (pi + atan(-1*a*(rt2*b + a)/(b*(rt2*a + b))))/2;
	float ans_2 = 0.25*(a2*sin(ang_2) + b2*cos(ang_2)) + a*b*(sin(ang_2) + cos(ang_2) - 1)/(2*rt2);
	float ans_1 = a*b*sin(ang)*sin((3*pi/4)-ang)+0.25*(a*a*sin(2*ang) +b*b*sin(3*pi/2-2*ang));
	pf("Ans 1 - %0.9lf\nAns 2 - %0.9lf\n", ans_1, ans_2);

	return 0;
}