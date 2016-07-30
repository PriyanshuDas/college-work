#include <bits/stdc++.h>

#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        string s[n];
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        int ac[n];
        memset(ac,0,sizeof(ac));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='*')
                    ac[i]++;
            }
        sort(ac,ac+n);
        int u,ans=0;
        for(int i=0;i<n&&k;i++)
        {
            u=m-ac[i];
            if(u>=ac[i])
            {
                ac[i]=u;
                k--;
            }
            else
            {
                break;
            }
        }
        //cout<<ac[0]<<ac[1]<<k;
        for(int i=0;i<n;i++)
            ans+=ac[i];
        u=1000;
        int ass=-1;
        if(k%2==1)
        {
            for(int i=0;i<n;i++)
            {
                ass=max(ass,ans+(m-ac[i])-ac[i]);
            }
            ans=ass;
        }

        cout<<ans<<endl;
    }
    return 0;
}
