#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
   int n;
   cin>>n;
   ll arr[n+1];
   for(int i=1;i<=n;i++)
       cin>>arr[i];

   int cnt=0;
   for(int i=1;i<=n;i++)
   {
      // printf("i = %d \n", i);
       cnt=0;
       int x, j;
       int flag=0;
       for(j=1;j<=n-1;j++)
       {
           if(arr[j]>arr[j+1])
           {
               cnt++;
               if(flag==0)
               {
                   x=j;
                   flag=1;
               }

               swap(arr[j], arr[j+1]);
               j++;
           }
           else if(cnt>0 && flag==1)
           {
               cout<<x<<" "<<j-1<<endl;
               flag=0;
           }
           if(cnt>0 && (j==n || j==n-1) && flag==1)
           {
               cout<<x<<" "<<j<<endl;
               //printf("J is %d\n",j);
               flag=0;
           }
       }

       if(cnt==0)
           break;
   }
   return 0;
}
