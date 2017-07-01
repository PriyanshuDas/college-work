#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ui unsigned int
using namespace std;

void convert_binary(ui A)
{
	string s = "";
	ui pow = 1;
	for(int i = 0; i <= 32; i++)
	{
		if(A%2 == 0)
			s+= '0';
		else
			s+= '1';
		A/= 2;
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
}

int main()
{
	int T;
	cin >> T;
	for(int t= 0; t < T; t++)
	{
		unsigned int A, B, C;
		sf("%u%u", &A, &B);
		C = A&B;
		/*convert_binary(A);
		cout << endl;
		convert_binary(B);
		cout << endl;
		convert_binary(C);
		cout << endl;*/
		int flag = 0;
		for (int bit_pos = 32; bit_pos > 0; bit_pos--)
		{
			ui curr = 1<<(bit_pos - 1);
			if(curr&C)
			{
				flag++;
			}
			else if (flag)
			{
				if((curr&A) == (curr&B))
					continue;
				C = C>>(bit_pos);
				C = C<<(bit_pos);
				break;
			}
		}
		/*convert_binary(C);
		cout << endl;*/
		printf("%u\n", C);
	}
	return 0;
}
