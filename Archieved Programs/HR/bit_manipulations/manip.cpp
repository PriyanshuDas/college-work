#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define pb push_back

using namespace std;

typedef map<int, int>::iterator it;

int main()
{
	int n;
	int ans = -1;
	cin >> n;
	int Arr[100] = {0};
	int Mark[100] = {0};
	for(int i = 0; i < n; i++)
		sf("%d", &Arr[i]);
	int bit_pos = 31;
	while(bit_pos > -1)
	{
		map<int, int> Map;
		int curr = 1<<bit_pos;
		int ct = 0;
		for(int i = 0; i < n; i++)
		{
			if((curr&Arr[i]))
			{
				ct++;
			}
			else
			{
				int M = Arr[i];
				M = M>>bit_pos;
				M = M<<bit_pos;
				Map[M]++;
				//cout << M << endl;
			}
		}
		if(ct <= n/2)
		{
			int req = n/2 - ct;
			int count = 0;
			int flag = 0;
			for(it iter = Map.begin(); iter != Map.end(); iter++) 
			{
				if((*iter).second > n/2)
				{
					flag = 1;
					break;
				}
				count += (*iter).second;
			}
			if(flag == 0 && count >= req)
			{
				ans = bit_pos;
			}
		}
		if(ans != -1)
			break;
		bit_pos--;
	}
	cout << ans;
	return 0;
}
