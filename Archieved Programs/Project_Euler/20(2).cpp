#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define pb push_back

using namespace std;

//int Ans[159] = {0};
int Ans[1000000] = {0};
vector <int> Vec_Mult(vector <int> A, vector <int> B)
{
	vector<int> ans;
	memset ( Ans, 0, sizeof(Ans));
	int K = 0, pos = 0;
	for (int I = 0; I < A.size(); I++)
	{
		K = I;
		for (int J = 0; J < B.size(); J++)
		{
			Ans[K] += A[I]*B[J];
			Ans[K+1] += Ans[K]/10;
			Ans[K] %= 10;
			K++;
		}
		ans.pb(Ans[I]);
		pos++;
	}
	while(pos < K)
	{
		ans.pb(Ans[pos]);
		pos++;
	}
	while(Ans[pos] != 0)
	{
		Ans[pos+1] += Ans[pos]/10;
		Ans[pos] %= 10;
		ans.pb(Ans[pos]);
		pos++;
	}
	return ans;
}

int main()
{
	vector <int> ans;
	ans.pb(1);
	int inp;
	cin >> inp;
	for (int i = 2; i <= inp; ++i)
	{
		int tmp = i;
		vector <int> Temp;
		while (tmp != 0)
		{
			Temp.pb(tmp%10);
			tmp/= 10;
		}

		ans = Vec_Mult(Temp, ans);
	}
	pf("The term is -\n");
	long long int sum = 0;
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		sum += ans[i];
		pf("%d", ans[i]);
	}
	pf ("\nThe sum of the digits is - %lld\n", sum);
	return 0;
}