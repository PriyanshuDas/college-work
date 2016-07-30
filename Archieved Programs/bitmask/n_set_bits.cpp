#include <bits/stdc++.h>
#define Set 8

using namespace std;

int M[100];
int N[100];
int Mask;
int max_bit = 0;
int set_bit = 0;

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
			continue;
		}
		cycle(ind + 1);
	}
	return;
}
int main()
{
	printf("Enter the number of max bits (<30) : ");
	scanf("%d", &max_bit);
	printf("Enter the number of bits to be set : ");
	scanf("%d", &set_bit);
	if(set_bit >= max_bit && max_bit < 30)
	{
		printf("Error : User is stupid.\n\n");
		return 0;
	}
	cycle(0);
}
