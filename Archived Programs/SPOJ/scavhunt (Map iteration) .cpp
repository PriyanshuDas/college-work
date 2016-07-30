#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		int n;
		cin >> n;
		map <string,string> m;
		map <string, int> m2;
		for (int i = 0; i < n-1;i++)
		{
			string t1, t2;
			cin >> t1 >> t2;
			m[t1] = t2;
			m2[t1]++;
			m2[t2]++;
		}
		map<string, string> ::iterator it;
		string startin,endin;
		for(it = m.begin(); it != m.end(); it++) 
		{
			string Start = it -> first;
			string End = it -> second;
			if (m2[Start] == 1)
				startin = Start;
			if (m2[End] == 1)
				endin = End;
		}
		string temp = startin;
		int ctr = 1;
		cout << "Scenario #"<<k+1 <<":\n";
		int flag = 0;
		while(flag != 1)
		{
			if (temp == endin)
				flag = 1;
			cout << temp <<"\n";
			ctr++;
			temp = m[temp];
		}
		cout << "\n";
	}
	return 0;
}