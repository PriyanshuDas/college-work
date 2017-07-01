#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define n_max 66001

/* Outline of Algorithm :-

- Take n
1- Find higher x coordinate of rectangle ending farther from y - axis		16
2- Find lower x coordinate of rectangle starting closer to y - axis			16
3- Find higher y coordinate of rectangle ending farther from x - axis		16
4- Find lower y coordinate of rectangle starting closer to x - axis			16
5- Use 1 to find left x-coordinate of "right" triangle						16
6- Use 2 to find right x-coordinate of "left" triangle						16
7- Use 3 to find lower y-coordinate of "upper" triangle						16
8- Use 4 to find upper y-coordinate of "lower" triangle						16

9- Have a list of pairs of x coordinates and y coordinates. -> 4 pairs
10- Ways of arranging them :- 2	(x1[0], y1[0]) - (x2[0], y2[0]) or (x1[1], y1[0]) - (x2[1], y2[0)

11- Total Queries = 16*8 + 2 = 134

*/
using namespace std;

int main()
{
	int n;	cin >> n;
	vector<int> x_1, x_2;
	vector<int> y_1, y_2;
	int l = 1, r = n, g = n;
	//1- Find higher x coordinate of rectangle ending farther from y - axis		16
	//-> (1,1) to (x, n) will have 2
	
	l = 1, r = n, g = n;
	while(l <= r)
	{
		int m = (l+r)/2;
		pf("? %d %d %d %d\n", 1, 1, m, n);
		fflush(stdout);
		int tmp;	sf("%d", &tmp);
		if(tmp == 0 || tmp == 1)			//critical condition
		{
			l = m+1;
			continue;
		}
		else if (tmp == 2)
		{
			g = m;
			r = m-1;
			continue;
		}
	}
	x_2.pb(g);
	
	//2- Find lower x coordinate of rectangle starting closer to y - axis		16
	
	l = 1; r = x_2[0]; g = 1;
	while(l <= r)
	{
		int m = (l+r)/2;
		pf("? %d %d %d %d\n", m, 1, x_2[0], n);
		fflush(stdout);
		int tmp;	sf("%d", &tmp);
		if(tmp == 0 || tmp == 1)			//critical condition
		{
			r = m-1;
			continue;
		}
		else if (tmp == 2)
		{
			g = m;
			l = m+1;
			continue;
		}
	}
	//pf("%d %d\n", g, x_2[0]);
	x_1.pb(g);	

	//5- Use 1 to find left x-coordinate of "right" triangle					16
	
	l = 1; r = x_2[0]; g = 1;
	while(l <= r)
	{
		int m = (l+r)/2;
		pf("? %d %d %d %d\n", m, 1, x_2[0], n);
		fflush(stdout);
		int tmp;	sf("%d", &tmp);
		if(tmp == 0)			//critical condition
		{
			r = m-1;
			continue;
		}
		else if (tmp == 2 || tmp == 1)
		{
			g = m;
			l = m+1;
			continue;
		}
	}
	//pf("%d %d\n", g, x_2[0]);
	x_1.pb(g);
	
	//6- Use 2 to find right x-coordinate of "left" triangle					16
	l = x_1[0], r = x_2[0], g = x_2[0];
	while(l <= r)
	{
		int m = (l+r)/2;
		pf("? %d %d %d %d\n", x_1[0], 1, m, n);
		fflush(stdout);
		int tmp;	sf("%d", &tmp);
		if(tmp == 0)			//critical condition
		{
			l = m+1;
			continue;
		}
		else if (tmp == 2 || tmp == 1)
		{
			g = m;
			r = m-1;
			continue;
		}
	}
	x_2.pb(g);
	//pf("%d %d %d %d\n", x_1[0], x_2[1], x_1[1], x_2[0]);
	swap(x_2[0], x_2[1]);
	
	//3- Find higher y coordinate of rectangle ending farther from x - axis		16
	
	l = 1, r = n, g = n;
	while(l <= r)
	{
		int m = (l+r)/2;
		pf("? %d %d %d %d\n", 1, 1, n, m);
		fflush(stdout);
		int tmp;	sf("%d", &tmp);
		if(tmp == 0 || tmp == 1)			//critical condition
		{
			l = m+1;
			continue;
		}
		else if (tmp == 2)
		{
			g = m;
			r = m-1;
			continue;
		}
	}
	//pf("%d %d\n", 1, g);
	y_2.pb(g);
	
	//4- Find lower y coordinate of rectangle starting closer to x - axis		16
	
	l = 1; r = y_2[0]; g = y_2[0];
	while(l <= r)
	{
		int m = (l+r)/2;
		pf("? %d %d %d %d\n", 1, m, n, y_2[0]);
		fflush(stdout);
		int tmp;	sf("%d", &tmp);
		if(tmp == 0 || tmp == 1)			//critical condition
		{
			r = m-1;
			continue;
		}
		else if (tmp == 2)
		{
			g = m;
			l = m+1;
			continue;
		}
	}
	y_1.pb(g);
	//pf("%d %d\n", y_1[0], y_2[0]);

	
	//7- Use 3 to find lower y-coordinate of "upper" triangle					16
	
	l = y_1[0]; r = y_2[0]; g = y_2[0];
	while(l <= r)
	{
		int m = (l+r)/2;
		pf("? %d %d %d %d\n", 1, m, n,  y_2[0]);
		fflush(stdout);
		int tmp;	sf("%d", &tmp);
		if(tmp == 0)			//critical condition
		{
			r = m-1;
			continue;
		}
		else if (tmp == 2 || tmp == 1)
		{
			g = m;
			l = m+1;
			continue;
		}
	}
	//pf("%d %d\n", g, x_2[0]);
	y_1.pb(g);
	
	//8- Use 4 to find upper y-coordinate of "lower" triangle					16
	l = y_1[0], r = y_2[0], g = y_2[0];
	while(l <= r)
	{
		int m = (l+r)/2;
		pf("? %d %d %d %d\n", 1, y_1[0], n, m);
		fflush(stdout);
		int tmp;	sf("%d", &tmp);
		if(tmp == 0)			//critical condition
		{
			l = m+1;
			continue;
		}
		else if (tmp == 2 || tmp == 1)
		{
			g = m;
			r = m-1;
			continue;
		}
	}
	y_2.pb(g);
	//pf("%d %d %d %d\n", y_1[0], y_2[1], y_1[1], y_2[0]);
	int flag = 0;
	swap(y_2[0], y_2[1]);
	for(int i = 0; i < 2 && !flag; i++)
	{
		for(int j = 0; j < 2 && !flag; j++)
		{
			for(int k = 0; k < 2 && !flag; k++)
			{
				for(int l = 0; l < 2 && !flag; l++)
				{
					if(x_1[i] > x_2[j] || y_1[k] > y_2[l] || x_1[(i+1)%2] > x_2[(i+1)%2] || y_1[(k+1)%2] > y_2[(l+1)%2])
						continue;
					int t1 = 0, t2 = 0;
					pf("? %d %d %d %d\n", x_1[i], y_1[k], x_2[j], y_2[l]);
					fflush(stdout);
					sf("%d", &t1);
					pf("? %d %d %d %d\n", x_1[(i+1)%2], y_1[(k+1)%2], x_2[(j+1)%2], y_2[(l+1)%2]);
					fflush(stdout);
					sf("%d", &t2);
					if(t1 == 1 && t2 == 1)
					{
						flag = 1;
						pf("! %d %d %d %d %d %d %d %d\n",x_1[i],y_1[k],x_2[j],y_2[l],x_1[(i+1)%2],y_1[(k+1)%2], x_2[(j+1)%2],y_2[(l+1)%2]);
					}
				}
			}
		}
	}
	return 0;
}
