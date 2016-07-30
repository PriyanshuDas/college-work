#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define m_val 1429432

using namespace std;

typedef struct node
{
    bool val = 0;
    int siz = 0;
    bool v_n = 0;
    node *lc, *rc;
} node;

node *c_node(int sz, int st)
{
    node *curr = new node;
    curr->v_n = false;
    if(sz == 1)
    {
        curr->v_n = true;
        curr->val = true;
        curr->lc = new node;
        curr->rc = new node;
        curr->lc->siz = 0;   curr->rc->siz = 0;
        curr->lc->val = 0; curr->rc->val = 0;
    }
    curr->siz = sz;
    if(sz >= 2)
    {
        curr->lc = c_node(sz/2, st);
        curr->rc = c_node(sz - sz/2, st + sz/2);
    }
    return curr;
}

void traverse(node *curr)
{
    //pf("Curr_size == %d\n", curr->siz);
    if(curr->lc->siz != 0)
        traverse(curr->lc);
    if(curr->rc->siz != 0)
        traverse(curr->rc);
    if(curr->v_n == 1)
        pf("%d ", curr->val);
}

int val(node *n, int pos)
{
    if(n->lc->siz == 0 && n->rc->siz == 0)
    {
        return n->val;
    }
    if(n->lc->siz > pos)
        return val(n->lc, pos);
    int r_pos = pos - n->lc->siz;
    if(r_pos < (n->rc->siz))
        return val(n->rc, r_pos);

}

void S_and_D(node *n, int pos, int prd) //Problem
{
    //pf("Search and Destroy @ { (%d, %d), %d, %d }\n", n->siz, n->val, pos, prd);
    if(n->siz == 1 && pos == 0)
    {
        n->val = -1;    n->siz = 0;
        return;
    }
    if(n->siz <= pos)
        return;
    int l_s = n->lc->siz,   r_s = n->rc->siz;
    if(l_s > pos)
    {
        S_and_D(n->lc, pos, prd);
    }
    if(pos >= l_s)
    {
        S_and_D(n->rc, pos-l_s, prd);
    }
    else
    {
        int last_l_pos = pos + ((l_s - pos - 1) - (l_s - pos - 1)%prd);
        //pf("last_l_pos == %d\n", last_l_pos);
        int r_pos = last_l_pos + prd - l_s;
        if(r_pos < r_s)
            S_and_D(n->rc, r_pos, prd);
    }
    n->siz = n->lc->siz + n->rc->siz;
}
int main()
{
    node *root = c_node(m_val, 1);
    S_and_D(root, 1, 2);
    for(int i = 1; i < root->siz; i++)
    {
        int curr = val(root, i);
        //pf("%d ", curr);
        if(curr >= root->siz)
            break;
        S_and_D(root, curr-1, curr);
    }
    int T;
    sf("%d", &T);
    for(int t = 0; t < T; t++)
    {
        int pos;    sf("%d", &pos);
        pf("Case %d: %d\n", t+1, val(root, pos-1));
    }
    return 0;
}
