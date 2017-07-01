//Solution for 1085 lightoj

#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back
#define fir first
#define sec second
#define be begin()
#define ull unsigned ll
#define pi2 pair<int, int>
#define n_max 100001
#define MOD 1000000007

using namespace std;

typedef struct node
{
	int l, r;
	node *lp, *rp;
	ull ct;
	bool lazy;
	int l_val;
} node;

void init_node(node *n)
{
	n->l = 0,		n->r = 0;
	n->lp = NULL,	n->rp = NULL;
	n->ct = 0,		n->l_val = 0;
	n->lazy = 0;
}

void erase_node(node *n)
{
	if(n->lp != NULL)	erase_node(n->lp);
	if(n->rp != NULL)	erase_node(n->rp);
	delete n;
}

int arr[n_max+1];
vector<pi2> sorted;
node *root;
int N, T;
void create_node(node *n, int l, int r)
{
	n->l = l;	n->r = r;	n->ct = 0;
	if(l == r)
		return;
	if(n->lp == NULL)
	{
		n->lp = new node;
		init_node(n->lp);
	}
	if(n->rp == NULL)
	{
		n->rp = new node;
		init_node(n->rp);
	}
	int mid = (l+r)/2;
	create_node(n->lp, l, mid);
	create_node(n->rp, mid+1, r);
}
ull point_update(node *n, int pos, ull val)
{
	if(n->lazy)
	{
		if(n->lp != NULL)
		{
			n->lp->lazy = 1;
			n->lp->l_val+= n->l_val;
			n->lp->ct = (n->l_val + n->lp->ct)%MOD;
		}
		if(n->rp != NULL)
		{
			n->rp->lazy = 1;
			n->rp->l_val+= n->l_val;
			n->rp->ct = (n->l_val + n->rp->ct)%MOD;
		}
		n->l_val = 0;
		n->lazy = 0;
	}
	/*	Actual Query		*/
}

ull range_update(node *n, int l, int r)
{
	if(n->lazy)
	{
		if(n->lp != NULL)
		{
			n->lp->lazy = 1;
			n->lp->l_val = (n->lp->l_val + n->l_val)%MOD;
			n->lp->ct = (n->l_val + n->lp->ct)%MOD;
		}
		if(n->rp != NULL)
		{
			n->rp->lazy = 1;
			n->rp->l_val = (n->rp->l_val + n->l_val)%MOD;
			n->rp->ct = (n->l_val + n->rp->ct)%MOD;
		}
		n->l_val = 0;
		n->lazy = 0;
	}
	/*		Actual Update		*/
}*/
