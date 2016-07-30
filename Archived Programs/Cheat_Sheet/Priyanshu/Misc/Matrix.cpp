/*	Matrix Implementation
	Includes :
(1)	Matrix Multiplication
(2) Matrix Exponentiation

Created By :- Priyanshu Das*/

#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define pb push_back
#define ll long long int
#define mp make_pair

using namespace std;

//int tmp_row = 0, tmp_col = 0;

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

using namespace std;

int main()
{
	int flag = 1;
	while(flag)
	{
		pf("Enter Choice :\n1: Multiply 2 Matrices\n");
		pf("2: Power of a Square Matrix\n");
		pf("3: End\n");
		int ch;
		cin >> ch;
		switch(ch)
		{
			case 1:
			{
				int m1, n1, m2, n2;
				cout << "Enter size of Matrix 1 (row, col): ";
				cin >> m1 >> n1;
				cout << "Enter Matrix 1 :\n";
				ll arr1[m1*n1+1];
				for(int i = 0; i < m1; i++)
				{
					for(int j = 0; j < n1; j++)
					{
						sf("%lld", &arr1[i*n1 + j]);
					}
				}
				cout << "Enter size of Matrix w (row, col): ";
				cin >> m2 >> n2;
				ll arr2[m2*n2 + 1];
				cout << "Enter Matrix 2 :\n";
				for(int i = 0; i < m2; i++)
				{
					for(int j = 0; j < n2; j++)
					{
						sf("%lld", &arr2[i*n2 + j]);
					}
				}
				matrix A(m1, n1);	matrix B(m2, n2);
				//temp_row = m1;		temp_col = n1;
				//temp_row = m2;		temp_col = n2;
				A.input(arr1);
				B.input(arr2);
				cout << " Resultant Matrix is :\n";
				matrix C = A*B;
				C.display();
				break;
			}
			case 2:
			{
				int n1;
				cout << "Enter order of square Matrix: ";
				cin >> n1;
				cout << "Enter Matrix :\n";
				ll arr1[n1*n1+1];
				for(int i = 0; i < n1; i++)
				{
					for(int j = 0; j < n1; j++)
					{
						sf("%lld", &arr1[i*n1 + j]);
					}
				}
				matrix A(n1, n1);
				A.input(arr1);
				ll P;
				cout << "Enter power : ";
				cin >> P;
				matrix C = A^P;
				cout << " Resultant Matrix is :\n";
				C.display();
				break;
			}
			case 3:
			{
				flag = 0;
				break;
			}
			default:
				break;
		}
	}
}
