#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
       ll arr[3], balls = 0, K;
       int flag = 3;
       cin >> arr[0] >> arr[1] >> arr[2] >> K;
       sort(arr, arr+3);
       if(arr[0] < K)
       {
           balls += 3*arr[0];
           arr[1] -= arr[0];
           arr[2] -= arr[0];
           K -= arr[0];
           arr[0] = 0;
           flag = 2;
       }
       if(arr[1] < K)
       {
           balls += 2*arr[1];
           arr[2] -= arr[1];
           K -= arr[1];
           arr[1] = 0;
           flag = 1;
       }
       if(K != 0)
            balls += (K-1)*flag + 1;
       cout << balls << endl;
    }
}
