#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll> >
#define max_n 1001
#define max_m 1001
#define max_q 100001
#define sec second

using namespace std;

bool l_flip[max_n+1];
map<ll,ll> l_flip_t[max_n+1];						// last flip op time						~

map<ll, ll> l_qry_typ[max_n+1][max_m+1];			// last qry type on on (i, j) at time [key] ~
map<ll, ll> l_qry_tim[max_n+1][max_m+1];			// last qrt tym on (i, j) at time [key]		~

map<ll, ll> n_book[max_n+1];						// total books in ith row at time [key]
ll n_book_q[max_q+1];								// total books after query q
ll n, m, q;

int main()
{
	cin >> n >> m >> q;
	memset(l_flip_t, -1, sizeof(l_flip_t));		// *****
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			l_qry_typ[i][j][0] = 2;
			l_qry_tim[i][j][0] = 0;
		}
		l_flip_t[i][0] = -1;
	}
	for(int i = 1; i <= q; i++)
	{
		n_book_q[i] = n_book_q[i-1];
		int typ, x, y;
		sf("%d%d", &typ, &x);
		map<ll,ll>::iterator l_q_typ_it;
		map<ll,ll>::iterator l_q_tim_it;
		map<ll,ll>::iterator l_flip_t_it = l_flip_t[x].lower_bound(i);
		map<ll,ll>::iterator n_book_it = n_book[x].lower_bound(i);
		if(l_flip_t_it != l_flip_t[x].end())
		{
			
		}
		if(typ == 1 || typ == 2)
		{
			sf("%d", &y);
			l_q_typ_it = l_qry_typ[x][y].end();
			l_q_typ_it--;
			l_q_tim_it = l_qry_tim[x][y].end();
			l_q_tim_it--;
		}
		if(typ == 1)
		{
			if((l_q_typ_it->sec == 2 && l_flip_t_it->sec < l_q_tim_it->sec) || (l_q_typ_it->sec == 1 && l_flip_t_it->sec > l_q_tim_it->sec))
			//if flipped before removing etc or flipped after putting
			{
				n_book[x][i] = n_book_it->second+1;
				n_book_q[i]++;
			}
			l_qry_typ[x][y][i] = 1;
			l_qry_tim[x][y][i] = i;
			
		}
		else if(typ == 2)
		{
			if((l_q_typ_it->sec == 1 && l_flip_t_it->sec < l_q_tim_it->sec) || (l_q_typ_it->sec == 2 && l_flip_t_it->sec > l_q_tim_it->sec))
			//if flipped before putting or flipped after removing
			{
				n_book[x][i] = n_book_it->second - 1;
				n_book_q[i]--;
			}
			l_qry_typ[x][y][i] = 2;
			l_qry_tim[x][y][i] = i;
		}
		else if(typ == 3)	//invert books on xth shelf
		{
			int curr = n_book_it->second;
			int next = m - curr;
			n_book[x][i] = next;
			n_book_q[i] = n_book_q[i] + (next-curr);
			l_flip_t[x][i] = i;
		}
		else if(typ == 4)	//Return library to state at xth query;
		{
			q = q-i;
			i = x;
		}
		pf("%lld\n", n_book_q[i]);
	}
	return 0;
}
