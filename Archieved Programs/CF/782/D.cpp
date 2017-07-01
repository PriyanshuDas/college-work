#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define ins insert
#define fi first
#define se second
#define n_max 10000

using namespace std;

vector <string> name[2];

map <string, vector <pair<int, int> > > chosen;	//(name, (pos, type))
map <string, vector <pair<int, int> > > chosen2;
map <string, vector <pair<int, int> > > chosen3;
string fin_name[n_max+1];
int main()
{
	int n;
	cin >> n;
	string tmp;
	for(int i = 0; i < n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		string t3, t2c1;
		t3 = s1.substr(0, 3);
		char c1 = s2[0];
		t2c1 = s1.substr(0, 2) + c1;
		name[0].pb(t3);
		name[1].pb(t2c1);
		//cout << name[0][i] << ' ' << name[1][i] << endl;
	}
	//put type 1 of all
	for(int i = 0; i < n; i++)
		chosen[name[0][i]].pb(mp(i, 0));

	//for all conflicts, put type 2

	for(auto it = chosen.begin(); it != chosen.end(); it++)
	{
		if(it->second.size() > 1)
		{
			for(int i = 0; i < it->se.size(); i++)
			{
				int pos = it->se[i].fi;
				chosen2[name[1][pos]].pb(mp(pos, 1));
			}
		}
		else
		{
			chosen2[it->first].pb(it->second[0]);
		}
	}

	// for all conflicts now occuring, put type 1 to type 2
	//pf("Chosen 2 : \n\n");
	for(auto it = chosen2.begin(); it != chosen2.end(); it++)
	{
		//cout << it->fi << endl;
		if(it->second.size() > 1)
		{
			for(int i = 0; i < it->se.size(); i++)
			{
				int pos = it->se[i].fi;
				int typ = it->se[i].se;
				//pf("\t(%d, %d)\n", pos, typ);
				chosen3[name[1][pos]].pb(mp(pos, 1));
			}
		}
		else
		{
			chosen3[it->first].pb(it->second[0]);
		}
	}
	int flag = 0;
	//pf("Chosen 3 : \n\n");
	int change = 1;
	while(change == 1 && flag == 0)
	{
		flag = 0;
		change = 0;
		chosen2.clear();
		for(auto it = chosen3.begin(); it != chosen3.end(); it++)
		{
			//cout << it->fi << endl;
			if(it->second.size() > 1)
			{
				int typ1ct = 0;
				for(int i = 0; i < it->se.size(); i++)
				{
					int pos = it->se[i].fi;
					int typ = it->se[i].se;
					if(typ == 1)
						typ1ct++;
					if(typ1ct >= 2)
					{
						flag = 1;
						change = 0;
						break;
					}
					change = 1;
					chosen2[name[1][pos]].pb(mp(pos, 1));
				}
			}
			else
			{
				int pos = it->se[0].fi;
				int typ = it->se[0].se;
				chosen2[name[typ][pos]].pb(mp(pos, typ));
				fin_name[pos] = name[typ][pos];
			}
		}
		for(auto it = chosen2.begin(); it != chosen2.end(); it++)
		{
			chosen3[it->fi] = it->se;
		}
	}
	if(flag == 0)
	{
		pf("YES\n");
		for(int i = 0; i < n; i++)
		{
			cout << fin_name[i] << '\n';
		}
	}
	else
	{
		pf("NO");
	}
	return 0;
}