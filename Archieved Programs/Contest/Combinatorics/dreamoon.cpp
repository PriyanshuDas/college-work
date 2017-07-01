#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int

using namespace std;

int fact[11] = {0};
int pow_2[11] = {0};

void factorial()
{
	fact[0] = 1;
	pow_2[0] = 1;
	for (int i = 1; i < 11; i++)
	{
		pow_2[i] = 2*pow_2[i-1];
		fact[i] = fact[i-1]*i;
	}
}

ll Combin(ll N, ll R)
{
	return (fact[N])/(fact[R]*fact[N-R]);
}

int main()
{
	factorial();
	string correct, input;
	cin >> correct >> input;
	int net_corr = 0, net_inp = 0, no_miss = 0;
	for(int i = 0; i < correct.size(); i++)
	{
		if(correct[i] == '+')
			net_corr++;
		else
			net_corr--;
		if(input[i] == '+')
			net_inp++;
		else if (input[i] == '-')
			net_inp--;
		else
			no_miss++;
	}
	//cout << net_corr <<'\t' << net_inp << '\t' << no_miss << endl;
	int err = net_corr - net_inp;
	double ans = 0;
	if(abs(err)%2 != no_miss%2)
	{
		ans = 0;
	}
	else
	{
		int no_p = (no_miss+err)/2;
		int no_n = (no_miss-err)/2;
	
		//printf("no of + = %d, no of - = %d\n", no_p, no_n);	
		
		if(no_p >= 0 && no_n >= 0)
		{
			ans = Combin(no_miss, no_p);
			ans /= pow_2[no_miss];
		}
	}
	pf("%0.10lf", ans);
	return 0;
}
