#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int
#define ull unsigned long long int
#define fi first
#define se second
#define n_max (1<<18)

using namespace std;

int state[n_max+1];
vector <int> Cakes;

int find_state(int st)
{
	if(state[st] != -1)
		return state[st];
	if(st == 0)
		return 0;
	//pf("@%d\n", st);
	bool states[16] = {0};
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			for(int m = i; m < 4; m++)
			{
				for(int n = j; n < 4; n++)
				{
					int mask = -1, flag = 0;
					for(int ii = i; ii <= m && flag == 0; ii++)
					{
						for(int jj = j; jj <= n && flag == 0; jj++)
						{
							if(((1<<(ii*4+jj))&st) == 0)
								flag = 1;
							mask = (mask^(1<<(ii*4+jj)));
						}
					}
					if(flag == 0 && (mask&st) < st)
					{
						int next_st = find_state(mask&st);
						states[next_st] = 1;
					}
				}
			}
		}
	}
	state[st] = 0;
	for(int i = 0; i < 16; i++)
	{
		if(states[i] == 1)
			state[st]++;
		else
			break;
	}
	return state[st];
}

typedef struct node
{
	int l, r;
	node *lp, *rp;
	int val;
	bool lazy;
	int l_val;
} node;

void init_node(node *n)
{
	n->l = 0,		n->r = 0;
	n->lp = NULL,	n->rp = NULL;
	n->val = 0,		n->l_val = 0;
	n->lazy = 0;
}
void erase_node(node *n)
{
	if(n->lp != NULL)	erase_node(n->lp);
	if(n->rp != NULL)	erase_node(n->rp);
	delete n;
}

node *root;
int N, T;
int create_node(node *n, int l, int r)
{
	n->l = l;	n->r = r;	n->val = 0;
	if(l == r)
	{
		n->val = state[Cakes[l]];
		return n->val;
	}
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
	int mid = (l+r)>>1;
	n->val = (create_node(n->lp, l, mid)^create_node(n->rp, mid+1, r));
	return n->val;
}
int point_update(node *n, int pos, int val)
{
	//pf("Inserting %d from %d @ (%d, %d)\n", val, pos, n->l, n->r);
	if(n->l == n->r)
	{
		n->val = state[val];
		//pf("Inserting %d @ %d\n", n->val, pos);
		return n->val;
	}
	int mid = (n->l + n->r)>>1;
	/*if(n->lp == NULL)
	{
		n->lp = new node;
		init_node(n->lp);
		//create_node(n->lp, n->l, mid);
	}

	if(n->rp == NULL)
	{
		n->rp = new node;
		init_node(n->rp);
		//create_node(n->rp, mid+1, n->r);
	}
*/
	int l_v = n->lp->val;
	int r_v = n->rp->val;
	if(n->lp->l <= pos && n->lp->r >= pos)
	{
		l_v = point_update(n->lp, pos, val);
	}
	if(n->rp->l <= pos && n->rp->r >= pos)
		r_v = point_update(n->rp, pos, val);
	n->val = (l_v^r_v);
	return n->val;
}

int range_query(node *n, int l, int r)
{
	if(n->l > r || n->r < l)
		return 0;
	if(n->l == l && n->r == r)
		return n->val;
	int l_v = 0, r_v = 0;
	if(n->lp->r >= l)
	{
		l_v = range_query(n->lp, max(n->lp->l, l), min(n->lp->r, r));
	}
	if(n->rp->l <= r)
	{
		r_v = range_query(n->rp, max(n->rp->l, l), min(n->rp->r, r));
	}
	return (l_v^r_v);
}


typedef struct Cake
{
	int matrix[4][4];
} cake;


int main()
{
	memset(state, -1, sizeof(state));
	state[0] = 0;
	//pf("{");
	for(int i = 0; i < (1<<17); i++)
	{
		int s = find_state(i);
		//pf("%d, ", s);
	}
	//pf("}\n");
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		Cakes.clear();
		int N, M;	sf("%d%d", &N, &M);
		for(int n = 0; n < N; n++)
		{
			cake c;
			int cur = 0;
			for(int i = 0; i < 4; i++)
			{
					char s[10];
					sf("%s", s);
					for(int j = 0; j < 4; j++)
					{
						c.matrix[i][j] = (s[j] - '0');
					}
			}
			for(int i = 0; i < 4; i++)
				for(int j = 0; j < 4; j++)
					cur = cur|((1<< (i*4 + j))*c.matrix[i][j]);
			//cout << cur << endl;
			Cakes.pb(cur);
		}
		root = new node;
		init_node(root);
		create_node(root, 0, N-1);
		/*pf("Cake states : ");
		for(int n = 0; n < N; n++)
		{
			pf("State[%d] == %d ", Cakes[n], state[Cakes[n]]);
		}
		pf("\n");*/
		for(int m = 0; m < M; m++)
		{
			int typ;	sf("%d", &typ);
			if(typ == 1)
			{
				int l, r;	sf("%d%d", &l, &r);
				l--;	r--;
				int ans = range_query(root, l, r);
				//pf("For Query (%d, %d) -> %d\n", l, r, ans);
				if(ans == 0)
					pf("Lotsy\n");
				else
					pf("Pishty\n");
			}
			else
			{
				cake c;
				int pos = 0;
				sf("%d", &pos);
				pos--;
				int cur = 0;
				for(int i = 0; i < 4; i++)
				{
					char s[10];
					sf("%s", s);
					for(int j = 0; j < 4; j++)
					{
						c.matrix[i][j] = (s[j] - '0');
					}
				}
				for(int i = 0; i < 4; i++)
					for(int j = 0; j < 4; j++)
						cur = cur|((1<< (i*4 + j))*c.matrix[i][j]);
				 point_update(root, pos, cur);
			}
		}
		erase_node(root);
	}
	return 0;
}