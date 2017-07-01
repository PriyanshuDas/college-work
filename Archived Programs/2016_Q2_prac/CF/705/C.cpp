#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

set <int> App[300001];  //stores position of notification of Xth app
bool unseen[300001] = {0};//  read or not
int app_pos[300001];

int f_unread = 1;


int main()
{
    int n, q;   cin >> n >> q;
    int unread = 0, not_ct = 0;
    for(int i = 1; i <= q; i++)
    {
        int typ, x; cin >> typ >> x;
        if(typ == 1)
        {
            not_ct++;
            App[x].insert(not_ct);
            unseen[not_ct] = 1;
            unread++;
            app_pos[not_ct] = x;
        }
        else if (typ == 2)
        {
            set<int>::iterator it = App[x].begin();
            for(it; it != App[x].end(); it++)
            {
                if(unseen[*it] == 1)
                {
                    unseen[*it] = 0;
                    unread--;
                }
            }
            App[x].clear();
        }
        else
        {
            for(f_unread; f_unread <= x; f_unread++)
            {
                if(unseen[f_unread] == 1)
                {
                    unseen[f_unread] = 0;
                    unread--;
                    int app = app_pos[f_unread];
                    App[app].erase(f_unread);
                }
            }
        }
        cout << unread << endl;
    }
    return 0;
}
