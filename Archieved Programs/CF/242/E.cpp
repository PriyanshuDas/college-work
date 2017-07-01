#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define max_n 100001
#define max_m 50001

using namespace std;

ll n, m;
int a[max_n];
struct node
{
    int l, r, sz;
    node *lc, *rc;
    int ct[32], p_flag, p_val;
};

void merge_node(node *l, node *r, node *c)
{
    //pf("Merging Nodes (%d, %d) -- (%d, %d)\n", l->l, l->r, r->l, r->r);
    for(int i = 0; i < 31;i++)
    {
        c->ct[i] = l->ct[i] + r->ct[i];
        //pf("(%d) (%d) + (%d) == (%d)\n", i, l->ct[i], r->ct[i], c->ct[i]);
    }
}

node *create_node(int l, int r)
{
    //pf("Creating node for range (%d - %d)\n", l, r);
    node *curr = new node;
    curr->l = l; curr->r = r; curr->sz = r-l+1;
    memset(curr->ct, 0, sizeof(curr->ct));
    curr->p_flag = 0; curr->p_val = 0;
    int mid_pt = (l+r)/2;
    if(l == r)
    {
        for(int i = 0; i < 31; i++)
        {
            int tmp = 1<<i;
            if((tmp&a[l]) != 0)
            {
                curr->ct[i]++;
            }
        }
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
    ll ans = 0;
    if(N->p_flag == 1)
    {
        for(int i = 0; i < 31; i++)
        {
            int tmp = 1<<i;
            if((tmp&(N->p_val)) != 0)
            {
                N->ct[i] = (N->r - N->l)+1 - N->ct[i];
            }
        }
        N->p_flag = 0;
        if(N->l != N->r)
        {
            N->lc->p_flag = 1;  N->lc->p_val ^= N->p_val;
            N->rc->p_flag = 1;  N->rc->p_val ^= N->p_val;
        }
        N->p_val = 0;
    }
    if(N->l == l && N->r == r)
    {
        for(int i = 0; i < 31; i++)
        {
            ll temp = pow(2, i);
            temp *= N->ct[i];
            ans += temp;
        }
        return ans;
    }
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
        ans = query(N->lc, l, mid_pt);
        ans +=query(N->rc, mid_pt+1, r);
    }
    return ans;
}

void update(node *N, int l, int r, int val)
{
    //pf("Updating node (%d, %d) for range (%d - %d)\n", N->l, N->r, l, r);
    if(N->p_flag == 1)
    {
        for(int i = 0; i < 31; i++)
        {
            int tmp = 1<<i;
            if((tmp&N->p_val) != 0)
            {
                N->ct[i] = (N->r - N->l)+1 - N->ct[i];
            }
        }
        N->p_flag = 0;
        if(N->l != N->r)
        {
            N->lc->p_flag = 1;  N->lc->p_val = (N->lc->p_val)^(N->p_val);
            N->rc->p_flag = 1;  N->rc->p_val = (N->rc->p_val)^(N->p_val);
        }
        N->p_val = 0;
    }
    if(N->l == l && N->r == r)
    {
        N->p_flag = 1;
        N->p_val ^= val;
        for(int i = 0; i < 31; i++)
        {
            int tmp = 1<<i;
            if((tmp&N->p_val) != 0)
            {
                N->ct[i] = (N->r - N->l)+1 - N->ct[i];
            }
        }
        N->p_flag = 0;
        if(N->l != N->r)
        {
            N->lc->p_flag = 1;  N->lc->p_val = (N->lc->p_val)^(N->p_val);
            N->rc->p_flag = 1;  N->rc->p_val = (N->rc->p_val)^(N->p_val);
        }
        N->p_val = 0;
        return;
    }
    int mid_pt = (N->l + N->r)/2;
    if(r <= mid_pt)
    {
        update(N->lc, l, r, val);
        update(N->rc, N->rc->l, N->rc->r, 0);
    }
    else if(l > mid_pt)
    {
        update(N->rc, l, r, val);
        update(N->lc, N->lc->l, N->lc->r, 0);
    }
    else
    {
        update(N->lc, l, mid_pt, val);
        update(N->rc, mid_pt+1, r, val);
    }
    merge_node(N->lc, N->rc, N);
}


int main()
{
    sf("%lld", &n);
    for(int i = 0; i < n; i++)
    {
        sf("%d", &a[i]);
    }
    node *root = create_node(0, n-1);

    sf("%lld", &m);
    for(int i = 0; i < m; i++)
    {
        int t, l, r, x;
        sf("%d%d%d", &t, &l, &r);
        l--;    r--;
        if(t == 2)
        {
            sf("%d", &x);
            update(root, l, r, x);
        }
        else
        {
            ll ans = query(root, l, r);
            pf("%lld\n", ans);
        }
    }
    return 0;
}
