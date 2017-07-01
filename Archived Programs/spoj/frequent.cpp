#include <bits/stdc++.h>

#define ll long long int
#define pf printf
#define sf scanf
#define pb push_back
#define mp make_pair
#define max_s 100000

using namespace std;

int n, q, a[max_s+1];

struct node
{
    int l_lim, r_lim;
    node *lc, *rc;
    pair<int, int> ans, l_ans, r_ans;   //needed data
};

void merge_node(node *l, node *r, node *c)
{
    //pf("Merging (%d - %d)   &&    (%d - %d)\n", l->l_lim, l->r_lim, r->l_lim, r->r_lim);
    c->l_lim = l->l_lim;    c->r_lim = r->r_lim;
    pair<int, int> t_l_ans, t_r_ans;
    if(l->l_ans.first == (l->r_lim - l->l_lim + 1) && l->l_ans.second == r->l_ans.second)
    {
        t_l_ans = mp(l->l_ans.first + r->l_ans.first ,l->l_ans.second);
    }
    else
        t_l_ans = l->l_ans;

    if(r->r_ans.first == (r->r_lim - r->l_lim + 1) && r->r_ans.second == l->r_ans.second)
    {
        t_r_ans = mp(r->r_ans.first + l->r_ans.first, r->r_ans.second);
    }
    else
        t_r_ans = r->r_ans;
    pair<int, int> t_ans = mp(0, 0);
    if(l->r_ans.second == r->l_ans.second)
    {
        t_ans = mp(l->r_ans.first+r->l_ans.first, l->r_ans.second);
    }
    c->l_ans = t_l_ans; c->r_ans = t_r_ans;
    c->ans = max(l->ans, max(r->ans, t_ans));
}

node *create_node(int l, int r)
{
   // pf("Creating node for range (%d - %d)\n", l, r);
    node *curr = new node;
    curr->l_lim = l; curr->r_lim = r;
    int mid_pt = (l+r)/2;
    if(l == r)
    {
        curr->ans = mp(1, a[l]);
        curr->l_ans = mp(1, a[l]);
        curr->r_ans = mp(1, a[l]);
        return curr;
    }
    curr->lc = (create_node(l, mid_pt));
    curr->rc = (create_node(mid_pt+1, r));
    merge_node(curr->lc, curr->rc, curr);
    return curr;
}

node query(node *N, int l, int r)
{
    int mid_pt = (N->r_lim + N->l_lim)/2;
    if(N->l_lim == l && N->r_lim == r)
        return *N;
    if(l >= N->l_lim && r <= mid_pt)
        return query(N->lc, l, r);
    if(l > mid_pt && r <= N->r_lim)
        return query(N->rc, l, r);
    node ans;
    if(l <= mid_pt && r > mid_pt)
    {
        node l_ans = query(N->lc, l, mid_pt);
        node r_ans = query(N->rc, mid_pt+1, r);
        merge_node( &l_ans, &r_ans, &ans);
    }
    return ans;
}

int main()
{
    while(1)
    {
        sf("%d", &n);
        if(n == 0)
            break;
        sf("%d", &q);
        for(int i = 0; i < n; i++)
        {
            sf("%d", &a[i]);
        }
        node *root = create_node(0, n-1);
        for(int j = 0; j < q; j++)
        {
            int x, y;
            sf("%d%d", &x, &y);
            x--, y--;
            node ans = query(root, x, y);
            pf("%d\n", ans.ans.first);
        }
        delete root;
    }
    return 0;
}
