#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x;	cin >> x;
	int arr[16][16];
	int tot = 0;
	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			if((i+j)%2 == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
			tot += arr[i][j];
			//cout << arr[i][j] << ' ';
		}
		//cout << endl;
	}
	int n = 15;
	int ct = 0, i = 0, j = 0;
	cout << "Total is : " << tot << endl;
	while(tot - ct > x)
	{
		int i_typ = 0, j_typ = 0;
		if(n%2 == 1)
		{
			i_typ =1;
			j_typ = 1;
		}
		else
		{
			j_typ = -1;
			i_typ = -1;
		}
		//cout << i_typ << ' ' << j_typ << endl;
		for(j; j < n && j >= 15-n+1; j += j_typ)
		{
			//cin >> i_typ;
			if(tot - ct == x)
			{
				//cout << ct << endl;
				cout << n;
				return 0;
			}
			ct += arr[i][j];
		}
		j -= j_typ;
		i += i_typ;
		for(i; i < n && i >= 15-n; i += i_typ)
		{
			//cin >> i_typ;
			if(tot - ct == x)
			{
				cout << n;
				return 0;
			}
			ct += arr[i][j];
		}
		i -= i_typ;
		j -= j_typ;
		//printf("%d\t\t%d", n, ct);
		n--;
		//cout << n << endl;
	}
	return 0;
}
