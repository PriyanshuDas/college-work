#include <bits/stdc++.h>

#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair <int, int>

using namespace std;

ll steps;
ll st_x, st_y;
ll curr_x, curr_y;
ll rem = 0;
int main()
{
    cin >> steps;
    ll n = sqrt(steps/3);
    while(3*n*(n+1) > steps)
        n--;
    st_x = 2*n;
    st_y = 0;
    rem = steps - 3*n*(n+1);
    //pf("Start at : (%lld, %lld)\n", st_x, st_y);
    curr_x = st_x;
    curr_y = st_y;
    while(rem)
    {
        n++;
        rem--;
        curr_x++;
        curr_y+= 2;
        if(rem > n)/*               \           */
        {
            curr_y += 2*(n-1);
            curr_x -= (n-1);
            rem-= (n-1);
        }
        else
        {
            curr_y += 2*rem;
            curr_x -= rem;
            rem = 0;
            break;
        }
        if(rem >= n)           //      -
        {
            curr_x -= 2*n;
            rem -= n;
        }
        else
        {
            curr_x -= 2*rem;
            rem = 0;
            break;
        }
        if(rem >= n)           //      /
        {
            curr_y -= 2*n;
            curr_x -= n;
            rem -= n;
        }
        else
        {
            curr_y -= 2*rem;
            curr_x -= rem;
            rem = 0;
            break;
        }
        if(rem >= n)    /*      \   */
        {
            curr_y -= 2*n;
            curr_x += n;
            rem -= n;
        }
        else
        {
            curr_y -= 2*rem;
            curr_x += rem;
            rem = 0;
            break;
        }
        if(rem >= n)            // _
        {
            curr_x += 2*n;
            rem -= n;
        }
        else
        {
            curr_x += 2*rem;
            rem = 0;
            break;
        }
        if(rem >= n)        /*      /   */
        {
            curr_x += n;
            curr_y += 2*n;
            rem -= n;
        }
        else
        {
            curr_x += rem;
            curr_y += 2*rem;
            rem = 0;
            break;
        }
    }
    pf("%lld %lld", curr_x, curr_y);
    return 0;
}
