/* Segment Trees with lazy Propagation*/

#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2>
#define pi4 pair<pi2, pi2>
#define loop(i, l, r) for(int i = l; i < r; i++)
#define n_max 100002
#define m_max 100002
#define MOD 1000000007

using namespace std;

class matrix
{
	public:
	ll **mat;				// pointer to array of pointers to long long ints
	int row, col;
	
	matrix(int m, int n)	// M*N matrix
	{
		mat = new ll*[m];
		row = m;	col = n;
		for(int i = 0; i < m; i++)	//setting size of matrix
			mat[i] = new ll[n];
	}matrix()
	{
		matrix(2, 2);
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
					C.mat[i][j] = (C.mat[i][j] + (mat[i][k]*B.mat[k][j])%MOD)%MOD;
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
	matrix operator =(matrix A)
	{
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < col; j++)
				mat[i][j] = (A.mat[i][j])%MOD;
		}
	}
	matrix operator +(matrix B)
	{
		matrix C(row, col);
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < col; j++)
				C.mat[i][j] = (mat[i][j] + B.mat[i][j])%MOD;
		}
		return C;
	}	
	friend matrix operator -(const matrix &A, const matrix &B)
	{
		matrix C(A.row, A.col);
		for(int i = 0; i < A.row; i++)
		{
			for(int j = 0; j < B.col; j++)
			{
				C.mat[i][j] = (A.mat[i][j] - B.mat[i][j])%MOD;
				if(C.mat[i][j] < 0)
					C.mat[i][j] += MOD;
			}
		}
		return C;
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

matrix F(2, 2);

typedef struct node
{
	ll l,r, pow, flag;
	matrix S;
	node() : S(2, 1) {}
} Node;

Node Seg_tree[2*n_max+1];
matrix Fibb_0(2, 1);
ll a[n_max+1], lazy[2*n_max+1];

matrix build(ll l, ll r, int pos)
{
	Seg_tree[pos].l = l;	Seg_tree[pos].r = r;
	Seg_tree[pos].pow = 0;	Seg_tree[pos].flag=0;
	ll arr[] = {0, 0};
	Seg_tree[pos].S.input(arr);
	Seg_tree[pos].pow = 0;
	if(l < r)
	{
		ll m = (l+r)/2;
		if(l <= m)
			Seg_tree[pos].S = Seg_tree[pos].S + build(l, m, pos*2);
		if(r >= m+1)
			Seg_tree[pos].S = Seg_tree[pos].S + build(m+1, r, pos*2+1);
	}
	else
	{
		Seg_tree[pos].S = (F^(a[l]))*Fibb_0;
	}
	return Seg_tree[pos].S;
}

void fix_pow(int pos)
{
	if(lazy[pos] > 0)
	{
		Seg_tree[pos].pow += lazy[pos];
		if(Seg_tree[pos].l < Seg_tree[pos].r)
		{
			lazy[2*pos] += lazy[pos];
			lazy[2*pos+1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(Seg_tree[pos].pow > 0)
	{
		Seg_tree[pos].S = (F^Seg_tree[pos].pow)*Seg_tree[pos].S;
		Seg_tree[pos].pow = 0;
	}
}

void update (ll l, ll r, ll x, int pos)
{
	if(lazy[pos] != 0)
	{
		Seg_tree[pos].pow += lazy[pos];
		if(Seg_tree[pos].l < Seg_tree[pos].r)
		{
			lazy[2*pos] += lazy[pos];
			lazy[2*pos+1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(Seg_tree[pos].pow != 0)
	{
		Seg_tree[pos].S = (F^Seg_tree[pos].pow)*(Seg_tree[pos].S);
		Seg_tree[pos].pow = 0;
	}
	if(Seg_tree[pos].l == l && Seg_tree[pos].r == r)
	{
		if(l < r)
			lazy[2*pos] += x;
		if(l < r)
			lazy[2*pos+1] += x;
		Seg_tree[pos].pow += x;
		Seg_tree[pos].S = (F^Seg_tree[pos].pow)*(Seg_tree[pos].S);
		Seg_tree[pos].pow = 0;
		if(Seg_tree[pos].l < Seg_tree[pos].r)
		{
			fix_pow(2*pos);
			fix_pow(2*pos+1);
			Seg_tree[pos].S = Seg_tree[2*pos].S + Seg_tree[2*pos+1].S;
		}
		return;
	}
	if(l < Seg_tree[pos].l || r > Seg_tree[pos].r)
		return;
	ll m = (Seg_tree[pos].l+Seg_tree[pos].r)/2;
	if(l <= m)
	{
		matrix t(2, 1);
		update(l, min(m, r), x, 2*pos);
		//Seg_tree[pos].S = Seg_tree[pos].S + (Seg_tree[2*pos].S - t);
	}
	if(r > m)
	{
		matrix t(2, 1);
		update(max(m+1, l), r, x, 2*pos+1);
		//Seg_tree[pos].S = Seg_tree[pos].S + (Seg_tree[2*pos+1].S - t);
	}
	if(Seg_tree[pos].l < Seg_tree[pos].r)
	{
		fix_pow(2*pos);
		fix_pow(2*pos+1);
		Seg_tree[pos].S = Seg_tree[2*pos].S + Seg_tree[2*pos+1].S;
	}
}

ll query(ll l, ll r, int pos)
{
	if(lazy[pos] != 0)
	{
		Seg_tree[pos].pow += lazy[pos];
		if(Seg_tree[pos].l < Seg_tree[pos].r)
		{
			lazy[2*pos] += lazy[pos];
			lazy[2*pos+1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if(Seg_tree[pos].pow != 0)
	{
		Seg_tree[pos].S = (F^Seg_tree[pos].pow)*(Seg_tree[pos].S);
		Seg_tree[pos].pow = 0;
	}
	if(Seg_tree[pos].l == l && Seg_tree[pos].r == r)
	{
		if(l < r)
		{
			fix_pow(2*pos);
			fix_pow(2*pos+1);
			Seg_tree[pos].S = Seg_tree[2*pos].S + Seg_tree[2*pos+1].S;
		}
		return Seg_tree[pos].S.mat[1][0];
	}
	ll ans = 0;
	ll m = (Seg_tree[pos].l+Seg_tree[pos].r)/2;
	if(l <= m)
	{
		ans = (ans+query(l, min(m, r), 2*pos))%MOD;
	}
	if(r > m)
	{
		ans = (ans + query(max(l, m+1), r, 2*pos+1))%MOD;
	}
	return ans;
}
int main()
{
	//ios_base::sync_with_stdio(false);
	ll arr[] = {1, 1, 1, 0};
	F.input(arr);
	ll arr2[]= {1, 0};
	Fibb_0.input(arr2);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		sf("%lld", &a[i]);
	}
	build(0, n-1, 1);
	for(int i = 0; i < m; i++)
	{
		ll t, l, r;
		int x;
		sf("%lld%lld%lld", &t, &l, &r);
		if(t == 1)
		{
			sf("%d", &x);
			update(l-1, r-1, x, 1);
		}
		else
		{
			ll ans = query(l-1, r-1, 1);
			cout << ans << endl;
		}
	}
	return 0;
}
