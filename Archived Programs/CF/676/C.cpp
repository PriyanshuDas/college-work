#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int

using namespace std;
	
int no_a[100002] = {0}, no_b[1000002] = {0};
int n, k;
string s;

int bin_search(char c, int st, int en)
{
	if(c == 'a' && no_b[en] - no_b[st-1] <= k)
		return 1;
	
	if(c == 'b' && no_a[en] - no_a[st-1] <= k)
		return 1;
		
	return 0;
}

int max_search(int pos)
{
	int last_c = pos;
	int last_w = n;
	int last = pos;
	int curr = n;
	while(abs(curr - last) > 0)
	{
		int flag = bin_search(s[pos-1], pos, curr);
		if(flag == 1)
		{
			//pf("(%c, %d, %d) == 1\n", s[pos-1], last_c, last_w);
			last_c = curr;
			double tmp = (last_w + last_c)/2;
			curr = ceil(tmp);
			last = last_c;
		}
		if(flag == 0)
		{
			//pf("(%c, %d, %d) == 0\n", s[pos-1], last_c, last_w);
			last_w = curr;
			double tmp = (last_w + last_c)/2;
			curr = ceil(tmp);
			last = last_w;
		}
	}
	return (last_c - pos + 1);
}

int main()
{
	cin >> n >> k;
	cin >> s;
	
	for(int i = 1; i <= s.size(); i++)
	{
		no_a[i] = no_a[i-1];
		no_b[i] = no_b[i-1];
		if(s[i-1] == 'a')
			no_a[i]++;
		if(s[i-1] == 'b')
			no_b[i]++;
		//pf("a[%d] == %d\nb[%d] == %d\n\n", i, no_a[i], i, no_b[i]);
	}
	int max_ans = 0;
	for(int i = 1; i <= s.size(); i++)
	{
		int curr = max_search(i);
		if(curr > max_ans)
			max_ans = curr;
	}
	cout << max_ans;
	return 0;
}
