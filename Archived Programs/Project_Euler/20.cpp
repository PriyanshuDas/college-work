#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define pb push_back

using namespace std;


vector <int> mult(vector<int> A, vector<int> B)
{

	int C[159] = {0};
	int Asize = A.size(), Bsize = B.size();
	vector <int> V;
	int K = 0;
	for(int I = Asize-1; I >= 0; I--)
	{
		K = Asize - I - 1;
		//cout << "A[i] = " << A[I]<<" ";
		for (int J = Bsize - 1; J>= 0; J--)
		{
			//cout << "B[j] = " << B[J]<<" ";
			C[K] += A[I]*B[J];
			C[K+1] = C[K]/10;
			C[K] %= 10;
			//cout << "C[k] = " << C[K]<<"\n";
			K++;
		}
	}
	if(C[K] == 0)
		K--;
	else
	{
		int I = K;
		while(C[I] > 0)
		{
			C[I+1] += C[I]/10;
			C[I] %= 10;
			I++;
		}
		K= I-1;

	}
	for (int I = K; I >= 0; I--)
	{

		V.pb(C[I]);
	}
	for(int I = 0; I < V.size(); I++)
		//cout << "V[i] = " << V[I]<<"\n";
	return V;
}

int main()
{
	int sum = 0;
	vector <int> ans;
	ans.pb(1);
	for(int i = 1; i < 101; i++)
	{
		vector <int> C;
		int curr = i;
		while (curr != 0)
		{
			C.pb(curr%10);
			curr/=10;
		}
		for (int j = 0; j < C.size()/2; j++)
		{
			int temp = C[j];
			C[j] = C[C.size() - 1 - j];
			C[C.size() - 1 - j] = temp;
		}
		for (int j = 0; j < C.size(); j++)
		{
			pf("%d", C[j]);
		}
		ans = mult(C, ans);
		pf(" - ");
		for(int j = 0; j < ans.size(); j++)
		{
			pf("%d", ans[j]);
		}
		pf("\n");
	}
	for (int i = 0; i < ans.size(); i++)
	{
		pf("%d", ans[i]);
		sum +=  ans[i];
	}
	/*vector <int> a, b;
	b.pb(1);
	b.pb(0);
	a.pb(1);
	a.pb(1);
	ans = mult(a,b);*/
	pf("The Ans is - ");
	for(int i = 0; i < ans.size(); i++)
		pf("%d", ans[i]);
	pf("\n");
	pf("\nThe Sum is - %d", sum);
	return 0;
}