#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

class matrix
{
	ll **mat;				// pointer to array of pointers to long long ints
	int row, col;
	public:
	matrix(int m, int n)	// M*N matrix
	{
		mat = new ll*[m];
		row = m;	col = n;
		for(int i = 0; i < m; i++)	//setting size of matrix
			mat[i] = new ll[n];
	}
	matrix operator *(matrix B)
	{
		matrix C(row, B.col);
		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++)
				C.mat[i][j] = 0;
		
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < col; j++)
			{
				for(int k = 0; k < col; k++)
				{
					C.mat[i][j] += mat[i][k]*B.mat[k][j];
				}
			}
		}
		return C;
	}
	matrix operator ^(ll P)
	{
		if(P==1)							// If pow == 1, return the matrix
			return (*this);
		if(P&1)								//If pow is odd, return A^(p-1)*A
			return (*this)*((*this)^(P-1));
		matrix B = (*this)^(P/2);			//IF pow is even, return [A^(p/2)] * [A^(p/2)]
		return B*B;
	}
	void input(ll arr[])					//Input is taken as an arr with size = row*columns
	{
		for(int i = 0; i < row; i++)
		{
			for(int j = 0;  j < col; j++)
				mat[i][j] = arr[col*i+j];	//Row Major Form
		}
	}
	void display()							//For Debugging
	{
		for(int i = 0; i < row; i++)
		{
			pf("|");
			for(int j = 0; j < col; j++)
			{
				cout << setw(10) << left << mat[i][j];
			}	
			pf("|\n");
		}
	}
};

matrix A(2, 2);

typedef struct Node
{
}
int main()
{
	ll arr[] = {0, 1, 1, 1};
	A.input(arr);
	vector<int> pow_phi;
	vector<int> fibb;
	fibb.pb(1);
	fibb.pb(2);
	fibb.pb(3);
	fibb.pb(5);
	pow_phi.pb(1);
	pow_phi.pb(2);
	pow_phi.pb(3);
	pow_phi.pb(5);
	for(int i = 4; i < 10; i++)
	{
		pow_phi.pb(pow_phi[i-1]*phi);
		fibb.pb(fibb[i-2]+fibb[i-1]);
		int phi_n = pow_phi[i];
		cout << fibb[i] << "\t|\t" << phi_n << endl;
	}
	return 0;
}
