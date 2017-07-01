#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back

using namespace std;

int main()
{
	int ct = 1;
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	while(next_permutation(arr, arr+10) && ct < 1000005)
	{
		if(ct == 999999)
		{
			for (int i = 0; i < 10; i++)
				cout << arr[i];
		}
		ct++;
	}
	return 0;
}