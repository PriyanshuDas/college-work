#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int M[100];
int N[100];
int Mask_1;
int Mask_2;
int max_bit = 0;
int set_bit = 0;
int set_bit_2 = 0;
int Path[100][100];
ll ans;

void cycle (int);
void cycle_2(int);

void cycle (int ind)
{
	int curr = 0;
	if(ind)
	{
		curr = M[ind - 1] + 1;
	}
	for(int i = curr; i < max_bit - (set_bit - ind) + 1; i++)
	{
		M[ind] = i;
		if(ind == set_bit - 1)
		{
			int x = 0;
			cout << '{';
			for(int i = 0; i < set_bit; i++)
			{
				cout << M[i];
				if(i < set_bit - 1)
					cout << ", ";
				x ^= (1<<M[i]);
			}
			cout << "}\n\n";
			for(int i = max_bit - 1; i >= 0; i--)
			{
				if(x&(1<<i))
					cout << 1;
				else
					cout << 0;
			}
			printf("\t == \t%d\n\n", x);
			Mask_1 = x;
			cycle_2(0);
			continue;
		}
		cycle(ind + 1);
	}
	return;
}

void cycle_2(int ind)
{
	//cout <<"a";
	int curr = 0;
	if(ind)
	{
		curr = N[ind - 1] + 1;
	}
	for(int i = curr; i < max_bit - (set_bit_2 - ind) + 1; i++)
	{
		int flag = 0;
		if(((1<<i) & Mask_1) == 0)
		{
			printf("Putting at : %d\n", i);
			for(int j = 0; j < set_bit; j++)
			{
				if(!Path[M[j]][i] && M[j]!= i)
				{
					printf("Path doesn't exist from %d to %d\n", M[j], i);
					flag = 1;
				}
			}
			if(flag)
				continue;
			N[ind] = i;
			if(ind == set_bit_2 - 1)
			{
				int x = 0;
				//cout << '{';
				for(int i = 0; i < set_bit_2; i++)
				{
					/*cout << N[i];
					if(i < set_bit_2 - 1)
						cout << ", ";*/
					x ^= (1<<N[i]);
				}
				//cout << "}\n\n";
				/*for(int i = max_bit - 1; i >= 0; i--)
				{
					if(x&(1<<i))
						cout << 1;
					else
						cout << 0;
				}
				printf("\t == \t%d\n\n", x);*/	
				Mask_2 = x;
				ans++;
				continue;
			}
			cycle_2(ind + 1);
		}
	}
	return;
}
int main()
{
	printf("Enter the number of part building factories : ");
	scanf("%d", &set_bit);
	printf("Enter the number of part assembling factories : ");
	scanf("%d", &set_bit_2);
	int sz = 1;
	string county[100];
	for(int i = 0; i < sz; i++)
	{
		cin >> county[i];
		sz = county[i].size();
	}
	max_bit = sz;
	for(int i = 0; i < sz; i++)
	{
		for(int j = 0; j < sz; j++)
		{
			if(county[i][j] == 'Y')
			{
				Path[i][j] = 1;
				Path[j][i] = 1;
			}
		}
	}
	cycle(0);
	printf("\nThe answer is : %lld\n", ans);
	return 0;
}
