#include <bits/stdc++.h>

#define ll long long int
#define pf printf
#define sf scanf
#define pb push_back
#define mp make_pair
#define max_s 100000

using namespace std;

ll n, q, a[max_s+1], b[max_s+1];

struct node
{
    int l, r;
    node *lc, *rc;
    ll ans; // sum_value in range
};

void merge_node(node *l, node *r, node *c)
{
    //pf("Merging Nodes (%d, %d)   --   (%d, %d)\n", l->l_lim, l->r_lim, r->l_lim, r->r_lim);
    c->ans = l->ans + r->ans;
}

node *create_node_a(int l, int r)
{
    //pf("Creating node for range (%d - %d)\n", l, r);
    node *curr = new node;
    curr->l = l; curr->r = r;
    int mid_pt = (l+r)/2;
    if(l == r)
    {
        curr->ans = a[l];
        return curr;
    }
    curr->lc = (create_node_a(l, mid_pt));
    curr->rc = (create_node_a(mid_pt+1, r));
    merge_node(curr->lc, curr->rc, curr);
    return curr;
}

node *create_node_b(int l, int r)
{
    //pf("Creating node for range (%d - %d)\n", l, r);
    node *curr = new node;
    curr->l = l; curr->r = r;
    int mid_pt = (l+r)/2;
    if(l == r)
    {
        curr->ans = b[l];
        return curr;
    }
    curr->lc = (create_node_b(l, mid_pt));
    curr->rc = (create_node_b(mid_pt+1, r));
    merge_node(curr->lc, curr->rc, curr);
    return curr;
}

ll query(node *N, int l, int r)
{
    //pf("Querying node (%d, %d) for range (%d - %d)\n", N->l, N->r, l, r);
    if(N->l == l && N->r == r)
        return N->ans;
    ll ans = 0;
    int mid_pt = (N->l + N->r)/2;
    if(r <= mid_pt)
    {
        ans = query(N->lc, l, r);
    }
    else if(l > mid_pt)
    {
        ans = query(N->rc, l, r);
    }
    else
    {
        ans = query(N->lc, l, mid_pt) + query(N->rc, mid_pt+1, r);
    }
    return ans;
}

int main()
{
    sf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        sf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        sf("%d", &b[i]);
    }
    node *root_a = create_node_a(0, n-1);
    node *root_b = create_node_b(0, n-1);
    sf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        ll x, y, c, d;   sf("%lld%lld%lld%lld", &x, &y, &c, &d);
        x--; y--;
        ll ans_a = query(root_a, x, y);
        ll ans_b = query(root_b, x, y);
        pf("Answer for a : %lld\nAnswer for n : %lld\n\n", ans_a, ans_b);
        ll tmp = ans_a*c - ans_b*d;
        ll ans = max((long long int)0, tmp);
        pf("%lld\n", ans);
    }
    return 0;
}
