#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T = 20;		// 20 test cases per sample
	cout << 20 <<endl;
	srand(time(NULL));	// generate random seed based on time
	for(int t = 0; t < 20; t++)
	{
		int n = (rand()%100) + 1;	// generate an n, 1 <= n <= 100
		cout << n << endl;
		for(int i = 0; i < n; i++)
		{
			int temp = rand()%1000001 ;	//generate a token, 0 <= token <= 10^6
			cout << temp << ' ';
		}
		cout << endl;
	}
}
