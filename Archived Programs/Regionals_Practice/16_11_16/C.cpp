#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert

using namespace std;

void LPSArray(string pat)
{
	int len = 0;
	int M = pat.size();
	int lps[M];
	memset(lps, 0, sizeof lps);
	lps[0] = 0;
	int i=1;
	while(i<M)
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len = lps[len - 1];
				//i++;
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	for(int j=0;j<M;j++)
	{
		cout<<lps[j];
		if(j<M-1)
			cout<<" ";
	}
	cout<< endl;
}

int main()
{
	string s;
	cin >> s;
	while(s != "End")
	{
		LPSArray(s);
		cin>>s;
	}
	return 0;
}
