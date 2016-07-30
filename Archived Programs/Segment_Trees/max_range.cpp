#include<bits/stdc++.h>

#define ll long long int
#define mp make_pair
#define pb push_back
#define max_size 1000000

using namespace std;

typedef struct
{
    int left, right, ind;
    ll curr_val = INT_MAX;
    void update(ll val)
    {
        curr_val = val;
    }
} node;

const int height = ceil(log(max_size));
ll range_max = 0;
node arr[1000000];

void set_val(int ind, ll num, int nod_ind)
{
    if(num < arr[nod_ind].curr_val)
    {
        arr[nod_ind].update(num);
    }
    int l = arr[nod_ind].left;
    int r = arr[nod_ind].right;
    //cout << l <<'\t' << r << endl;
    if(arr[nod_ind].left == arr[nod_ind].right)
    {
        //printf("(%d,%d)\n", l,r);
        arr[nod_ind].update(num);
    }
    else if(ind >= arr[nod_ind].left && ind <= (arr[nod_ind].left + arr[nod_ind].right)/2)
    {
        set_val(ind, num, 2*nod_ind);
    }

    else if(ind > (arr[nod_ind].left + arr[nod_ind].right)/2 && ind <= arr[nod_ind].right)
    {
        set_val(ind, num, 2*(nod_ind) + 1);
    }

    //printf("Updating (%d,%d) @ index (%d)\n", arr[nod_ind].left, arr[nod_ind].right, nod_ind);
}

ll query(int l, int r, int ind)
{
    ll min_curr = INT_MAX;
    ll left_min, right_min;
    //printf("Querying for (%d,%d)\t@(%d, %d) == %d\n\n", l, r, arr[ind].left, arr[ind].right, arr[ind].curr_val);
    if(arr[ind].left >= l && arr[ind].right <= r)
    {
        //printf("Answer found @\t(%d,%d)\n", arr[ind].left, arr[ind].right);
        return arr[ind].curr_val;
    }
    int l_l = arr[ind].left;    int l_r = (arr[ind].left + arr[ind].right)/2;
    int r_l =  (arr[ind].left + arr[ind].right)/2 + 1;    int r_r = arr[ind].right;
    if(l >= l_l && r <= l_r)
    {
        //printf("Going left from (%d,%d), ie\t@(%d,%d)\n",l, r, l_l, l_r);
        return query(l, l_r, 2*ind);
    }
    if(l >= r_l && r <= r_r)
    {
        //printf("Going rigt, ie\t@(%d,%d)\n",(r_l, r_r));
        return query(r_l, r, 2*ind + 1);
    }
    if(l >= l_l && r > l_r)
    {
        left_min = query(l, l_r, 2*ind);
        right_min = query(r_l, r, 2*ind + 1);
    }
    min_curr = min(left_min, right_min);
    return min_curr;
}


void build(int l, int r, int ind)
{
    if(l == r)
    {
        //printf("Value at index %d is %d\n", ind, l);
        arr[ind].curr_val = INT_MAX;
        arr[ind].left = l;      arr[ind].right = r;
    }
    else
    {
        arr[ind].left = l;       arr[ind].right = r;
        arr[ind].curr_val = INT_MAX;
        build(l,(l + r)/2, 2*ind);
        build((l + r)/2 + 1, r, 2*ind + 1);
    }
    //printf("(%d,%d) @ index (%d)\n", arr[ind].left, arr[ind].right, ind);
}
int main()
{
    cin >> range_max;
    build(1, range_max, 1);
    for(int i = 1; i <= range_max; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        set_val(i, tmp, 1);
    }
    int n_query;
    cin >> n_query;
    for(int i = 0; i < n_query; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        ll ans = query(l+1, r+1, 1);
        printf("%lld\n", ans);
    }
    return 0;
}
