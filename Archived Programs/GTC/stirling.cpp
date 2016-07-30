#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int

using namespace std;

int Stir_Mod(int n, int m)
{
	if(n == m)
		return 1;
	if(m == 0)
		return 0;
	if(n == 0)
		return 0;
	if(m%2 == 0)
	{
		return Stir_Mod(n-1, m-1);
	}
	else
	{
		return Stir_Mod(n-1, m) + Stir_Mod(n-1, m-1);
	}
}

int main()
{
	cout << setw(5) << " " << "| ";
	for(int i = 0; i < 26; i++)
	{
		cout << setw(5) << left << i << "| ";
	}
	cout << "\n-------------------------------------------------------------------------------------------\n";
	for(int i = 0; i < 26; i++)
	{
		cout << setw(5) << left << i << "| ";
		for(int j = 0; j <= i; j++)
		{
			cout << setw(5) << Stir_Mod(i, j) << "| ";
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << setw(5) << " " << "| ";
	for(int i = 0; i < 26; i++)
	{
		cout << setw(5) << left << i << "| ";
	}
	cout << "\n-------------------------------------------------------------------------------------------\n";
	for(int i = 0; i < 26; i++)
	{
		cout << setw(5) << left << i << "| ";
		for(int j = 0; j <= i; j++)
		{
			cout << setw(5) << Stir_Mod(i, j)%2 << "| ";
		}
		cout << endl;
	}
}
