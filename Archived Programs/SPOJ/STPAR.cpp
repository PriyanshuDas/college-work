#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if (n == 0)
			return 0;
		vector <int> order;
		vector <int> lane;
		vector <int> curr_order;
		int curr_proper = 1;
		for (int i = 0; i < n; ++i)
		{
			curr_order.pb (i+1);
			int tem1;
			cin >> tem1;
			order.pb(tem1);
		}
		vector <int> new_order;
		for (int i = 0; i < order.size(); i++)
		{
			if (order[i] == curr_proper)
			{
				new_order.pb(order[i]);
				curr_proper++;
			}
			else if (lane.size() >= 1 && lane[lane.size() - 1] == curr_proper)
			{
				new_order.pb(lane[lane.size()-1]);
				lane.erase(lane.begin() + lane.size() -1);
				curr_proper++;
				i--;
			}
			else
			{
				lane.pb(order[i]);
			}
		}
		for (int i = 0; i < lane.size(); i++)
		{
			new_order.pb(lane[lane.size() - i - 1]);
		}
		/*for (int i = 0; i < new_order.size(); i++)
		{
			cout << new_order[i] << " ";
		}*/
		if (new_order == curr_order)
			printf ("yes\n");
		else
			printf("no\n");
	}
	return 0;
}