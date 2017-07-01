#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define ull unsigned long long int
#define ins insert

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int arr[101][101] = {0};
	set<int> x_list;
	set<int> y_list;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for(int j = 0; j < m; j++)
		{
			if(s[j] == '*')
			{
				arr[i][j] = 1;
				x_list.ins(i);
				y_list.ins(j);
			}
		}
	}
	set<int>::iterator it_x = x_list.begin();
	set<int>::iterator it_y = y_list.begin();
	int x = 0, y = 0;
	for(it_x; it_x != x_list.end(); it_x++)
	{
		for(it_y = y_list.begin(); it_y != y_list.end(); it_y++)
		{
			if(arr[*it_x][*it_y] != 1)
			{
				x = *it_x;
				y = *it_y;
			}
		}
	}
	x++;	y++;
	cout << x << ' ' << y;
} 
