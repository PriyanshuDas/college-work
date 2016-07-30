#include<bits/stdc++.h>
#define ll long long int
#define sf scanf
#define pf printf

using namespace std;

int fibb[100000];
ll fib(int n)
{
	if(fibb[n])
		return fibb[n];
	else
		fibb[n] = fib(n-1)+fib(n-2);
	return fibb[n];
}
int main()
{
	ll sum = 0;
	fibb[1] = 1;
	fibb[2] = 1;
	int N;
	pf("Sum of even fibb no upto which point?:\n");
	sf("%d", &N);
	fib(N);
	pf("The %dth fibb no is : %lld\n", N, fib(N));
	for(int i = 1; i<= N; i ++)
		if(fibb[i]%2 == 0)
			sum += fibb[i];
	pf("Sum is : %lld\n", sum);
	return 0;
}