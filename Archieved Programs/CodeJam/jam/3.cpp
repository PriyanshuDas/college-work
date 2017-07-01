#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define pb push_back

using namespace std;

int JP[11][11];
int JS[11][11];
int PS[11][11];
int JPS[11][11][11];

int total = 0;
int K;

int valid(int i, int j, int l)
{
	if(JP[i][j] >= K)	return 0;
	if(JS[i][l] >= K)	return 0;
	if(PS[j][l] >= K)	return 0;
	if(JPS[i][j][l] > 0)	return 0;
	JP[i][j]++;	JS[i][l]++;	PS[j][l]++;
	JPS[i][j][l]++;
	return 1;
}

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int J, P, S;
		cin >> J >> P >> S >> K;
		total = 0;
		vector <vector<int> > curr_ans;
		memset(JP, 0, sizeof(JP));
		memset(JS, 0, sizeof(JS));
		memset(PS, 0, sizeof(PS));
		memset(JPS, 0, sizeof(JPS));
		for(int i = 1; i <= S; i++)
		{
			for(int j = 1; j <= P; j++)
			{
				for(int l = 1; l <= J; l++)
				{
					int tmp = valid(l, j, i);
					if(tmp != 0)
					{
						vector <int> t2;	t2.pb(l), t2.pb(j), t2.pb(i);
						curr_ans.pb(t2);
						total++;
					}
				}
			}
		}
		pf("Case #%d: %d\n", t+1, total);
		for(int i = 0; i < curr_ans.size(); i++)
		{
			for(int j = 0; j < curr_ans[i].size(); j++)
			{
				pf("%d", curr_ans[i][j]);
				if(j != curr_ans[i].size() - 1)
					cout << " ";
			}
			cout << endl;
		}
	}
}
