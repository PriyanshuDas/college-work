#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define ins insert
#define pb push_back
#define ins insert
#define pi2 pair<int, int>
#define fi first
#define se second
#define mp make_pair


using namespace std;

typedef struct node
{
	int l, r;
	vector <int> B;	// (size)
	node *lp, *rp;
	pair <int, int> left, right;
} node;

node *root;
vector <int> Inp;

int bin_search(node *n, int q)
{
	int l = 0;
	int r = n->B.size()-1;
	int ans = 0;
	//pf("Binary Searching in range (%d, %d) for %d\n", n->l, n->r, q);
	while(l <= r)
	{
		int mid = (l+r)>>1;
		//pf("\t%d\t%d\n", mid, n->B[mid]);
		if(n->B[mid] < q)
		{
			ans = mid+1;
			l = mid+1;
		}
		else
			r = mid-1;
	}
	return n->B.size()-ans;
}


// (ans, ((left, sz), (right, sz))
pair <int, pair<pi2, pi2> > Query(node *n, int l, int r, int q)
{
	//Find number of blocks with size >= q in (l, r);
	if(l == n->l && r == n->r)
	{
		int val = bin_search(n, q);
		//pf("Blaa\n");
		return mp(val, mp(n->left, n->right));
	}
	pair<int, pair<pi2, pi2> > L, R;
	L.fi = -1;
	R.fi = -1;
	if(l <= n->lp->r)
		L = Query(n->lp, l, min(r, n->lp->r), q);
	if(r >= n->rp->l)
		R = Query(n->rp, max(l, n->rp->l), r, q);
	pair<int, pair<pi2, pi2> > Ans;
	if(L.fi == -1)
		return R;
	if(R.fi == -1)
		return L;
	
	Ans.fi = L.fi+R.fi;
	if(L.se.se.fi == R.se.fi.fi)
	{
		int sz = L.se.se.se + R.se.fi.se;
		if(sz >= q)
			Ans.fi++;
		if(L.se.se.se >= q)
			Ans.fi--;
		if(R.se.fi.se >= q)
			Ans.fi--;
	}
	Ans.se.fi = L.se.fi;
	Ans.se.se = R.se.se;

	if(L.se.fi.se == (min(r, n->lp->r) - l + 1) && L.se.se.fi == R.se.fi.fi)
		Ans.se.fi.se = L.se.se.se + R.se.fi.se;

	if(R.se.se.se == (r - max(l, n->rp->l) + 1) && L.se.se.fi == R.se.fi.fi)
		Ans.se.se.se = L.se.se.se + R.se.fi.se;
	//pf("@(%d, %d)\t-\t%d\n", l, r, Ans.fi);
	return Ans;
		
}


void create_node(node *n, int l, int r)
{
	//if(r > 1)
		//pf("@(%d, %d)\n", l, r);
	int c_s = Inp[l];
	n->l = l;
	n->r = r;
	n->lp = NULL;
	n->rp = NULL;
	n->B.clear();

	int ct = 1;
	for(int i = l+1; i <= r; i++)
	{
		if(Inp[i] == c_s)
			ct++;
		else
		{
			c_s = Inp[i];
			n->B.pb(ct);
			ct = 1;
		}
	}
	n->B.pb(ct);
	n->left = mp(Inp[l], n->B[0]);
	n->right = mp(Inp[r], n->B[n->B.size()-1]);
	sort(n->B.begin(), n->B.end());
	if(l < r)
	{
		if(l <= (l+r)/2)
		{
			n->lp = new node;
			create_node(n->lp, l, (l+r)/2);
		}
		if(r >= (l+r)/2 + 1)
		{
			n->rp = new node;
			create_node(n->rp, (l+r)/2 +1, r);
		}
	}
}

void erase_node(node *n)
{
	if(n->lp != NULL)
		erase_node(n->lp);
	if(n->rp != NULL)
		erase_node(n->rp);
	delete(n);
}


int main()
{
	int T;	cin >> T;
	while(T--)
	{
		int N, Q;
		sf("%d%d", &N, &Q);
		Inp.clear();
		root = new node;
		for (int i = 0; i < N; ++i)
		{
			int tmp; sf("%d", &tmp);
			Inp.pb(tmp);
		}
		create_node(root, 0, N-1);
		for (int i = 0; i < Q; ++i)
		{
			int l, r, q;
			sf("%d%d%d", &l, &r, &q);
			int ans = Query(root, l-1, r-1, q).fi;
			pf("%d\n", ans);	
		}
		//erase_node(root);
	}
	return 0;
}