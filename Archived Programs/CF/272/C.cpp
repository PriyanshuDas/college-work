#include <bits/stdc++.h>

#define ll long long int
#define pf printf
#define sf scanf
#define pb push_back
#define mp make_pair
#define max_s 100000

using namespace std;

ll n, q, a[max_s+1];

struct node
{
    int l, r;
    node *lc, *rc;
    ll ans; // max_value in range
    int p_flag;
    ll p_val;
};

void merge_node(node *l, node *r, node *c)
{
    //pf("Merging Nodes (%d, %d)   --   (%d, %d)\n", l->l_lim, l->r_lim, r->l_lim, r->r_lim);
    c->ans = max(l->ans, r-> ans);
}

node *create_node(int l, int r)
{
    //pf("Creating node for range (%d - %d)\n", l, r);
    node *curr = new node;
    curr->l = l; curr->r = r;
    curr->p_flag = 0;
    int mid_pt = (l+r)/2;
    if(l == r)
    {
        curr->ans = a[l];
        return curr;
    }
    curr->lc = (create_node(l, mid_pt));
    curr->rc = (create_node(mid_pt+1, r));
    merge_node(curr->lc, curr->rc, curr);
    return curr;
}

ll query(node *N, int l, int r)
{
    //pf("Querying node (%d, %d) for range (%d - %d)\n", N->l, N->r, l, r);
    if(N->p_flag == 1)
    {
        N->ans = max(N->p_val, N->ans);
        N->p_flag = 0;
        if(N->l != N->r)
        {
            N->lc->p_flag = 1;  N->lc->p_val = N->p_val;
            N->rc->p_flag = 1;  N->rc->p_val = N->p_val;
        }
    }
    if(N->l == l && N->r == r)
        return N->ans;
    ll ans = 0;
    int mid_pt = (N->l + N->r)/2;
    if(r <= mid_pt)
    {
        ans = max(ans, query(N->lc, l, r));
    }
    else if(l > mid_pt)
    {
        ans = max(ans, query(N->rc, l, r));
    }
    else
    {
        ans = max(ans, query(N->lc, l, mid_pt));
        ans = max(ans, query(N->rc, mid_pt+1, r));
    }
    return ans;
}

void update(node *N, int l, int r, ll val)
{
    //pf("Updating node (%d, %d) for range (%d - %d)\n", N->l, N->r, l, r);
    if(N->p_flag == 1)
    {
        N->ans = max(N->p_val, N->ans);
        N->p_flag = 0;
        if(N->l != N->r)
        {
            N->lc->p_flag = 1;  N->lc->p_val = N->p_val;
            N->rc->p_flag = 1;  N->rc->p_val = N->p_val;
        }
    }
    N->ans = max(N->ans, val);
    if(N->l == l && N->r == r)
    {
        N->ans = val;
        if(l != r)
        {
            N->lc->p_flag = 1;  N->lc->p_val = val;
            N->rc->p_flag = 1;  N->rc->p_val = val;
        }
        return;
       }
    int mid_pt = (N->l + N->r)/2;
    if(r <= mid_pt)
    {
        update(N->lc, l, r, val);
    }
    else if(l > mid_pt)
    {
        update(N->rc, l, r, val);
    }
    else
    {
        update(N->lc, l, mid_pt, val);
        update(N->rc, mid_pt+1, r, val);
    }
}
int main()
{
    sf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        sf("%d", &a[i]);
    }
    node *root = create_node(0, n-1);
    sf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        ll x, y;   sf("%lld%lld", &x, &y);
        x--;
        ll ans_n = query(root, 0, x);
        pf("%lld\n", ans_n);
        ll  v = ans_n + y;
        update(root, 0, x, v);
    }
    return 0;
}
