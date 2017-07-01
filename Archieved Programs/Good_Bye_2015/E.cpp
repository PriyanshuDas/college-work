#include <bits/stdc++.h>

#define ll long long int
#define mp make_pair
#define pb push_back
#define pf printf
#define sf scanf

using namespace std;

vector <int> criminal;
vector <int> musketeer;
int pos[3];
vector <bool> dead;
int ans = 0;

int main()
{
    memset(pos, -1, sizeof(pos));
    int n;  cin >> n;
    for(int i = 0; i < 3; i++){     //input musketeer
        int tmp;    cin >> tmp; musketeer.pb(tmp);
    }
    sort(musketeer.begin(), musketeer.end());
    for(int i = 0; i < n; i++){     // input criminal
        int tmp;    cin >> tmp; criminal.pb(tmp);   dead.pb(0);
    }
    sort(criminal.begin(), criminal.end());
    for(int i = 0; i < n/2; i++)
        swap(criminal[i], criminal[n-1-i]);
    for(int i = 0; i < n; i++)    //setpos for musketeer
    {
        //cout << criminal[i] << '\t';
        if(criminal[i] <= musketeer[2] && pos[2] == -1) pos[2] = i;
        if(criminal[i] <= musketeer[1] && pos[1] == -1) pos[1] = i;
        if(criminal[i] <= musketeer[0] && pos[0] == -1) pos[0] = i;
    }
    if(criminal[0] > musketeer[0]+musketeer[1]+musketeer[2])
    {
        cout << -1;
        return 0;
    }

    //A+B+C
    int i = 0;
    for(i = 0; i < n && criminal[i] > musketeer[2] + musketeer[1]; i++)
    {
        dead[i] = 1;
        ans++;
    }
cout << "\nA+B+C done\n";
cout << "Ans : "<< ans<<endl;
//pf("A == %d\tB == %d\t C == %d\n", pos[0], pos[1], pos[2]);
    //find pos for A
    //B+C
    for(i; i < n && criminal[i] > musketeer[2] + musketeer[0] && dead[i] == 0; i++)
    {
        dead[i] = 1;
        ans++;
        while(pos[0] != -1 && pos[0] < n && dead[pos[0]])
            pos[0]++;
        if(pos[0] < n && pos[0] != -1)
        {
            dead[pos[0]] = 1;
            pos[0]++;
        }
    }
    cout << "B+C done\n";
    cout << "Ans : "<< ans<<endl;
    //find pos for B
    //A+C
    for(i; i < n && criminal[i] > musketeer[0] + musketeer[1] && !dead[i]; i++)
    {
        ans++;
        dead[i] = 1;
        while(pos[1] > -1 && pos[1] < n && dead[pos[1]])
            pos[1]++;
        if(pos[1] > -1 && pos[1] < n && dead[pos[1]] != 1)
        {
            dead[pos[1]] = 1;
            pos[1]++;
        }
    }

    cout << "A+C done\n";
    cout << "Ans : "<< ans<<endl;
    //find pos for C
    for(int j = pos[2]; j > -1 && j < n; j++)
    {
        if(dead[pos[2]] == 0)
            break;
        pos[2]++;
    }

    //A+B
    if(A+B > C)
    {
        for(i; i < n && criminal[i] <= musketeer[0] + musketeer[1] && criminal[i] > musketeer[2] && !dead[i]; i++)
        {
            if(dead[i])
                continue;
            dead[i] = 1;
            ans++;
            while(pos[2] > -1 && pos[2] < n && dead[pos[2]])
                pos[2]++;
            if(pos[2] > -1 && pos[2] < n && !dead[pos[2]])
            {
                pos[2]++;
                dead[pos[2]] = 1;
            }
        }
        cout << "A+B done\n";
        cout << "Ans : "<< ans<<endl;
        //Solo
        /*cout << "DEAD COUNTER \n";
        for(int i = 0; i < n; i++)
            cout << dead[i] << '\t';
        cout << endl;
    pf("A == %d\tB == %d\t C == %d\n", pos[0], pos[1], pos[2]);*/
        while((pos[0] < n && pos[0] > -1) || (pos[1] < n  && pos[1] > -1)|| (pos[2] < n && pos[2] > -1))
        {
            int flag = 0;
            while(pos[0] > -1 && pos[0] < n && dead[pos[0]])
                pos[0]++;
            if(pos[0] > -1 && pos[0] < n)
            {
                flag = 1;
                dead[pos[0]] = 1;
                pos[0]++;
            }
            while(pos[1] > -1 && pos[1] < n && dead[pos[1]])
                pos[1]++;
            if(pos[1] > -1 && pos[1] < n)
            {
                flag = 1;
                dead[pos[1]] = 1;
                pos[1]++;
            }
            while(pos[2] > -1 && pos[2] < n && dead[pos[2]])
                pos[2]++;
            if(pos[2] > -1 && pos[2] < n)
            {
                dead[pos[2]] = 1;
                pos[2]++;
            }
            if(flag)    ans++;
        }
    }
    else if(A+B <= C)
    {

    }
    cout << ans;
    return 0;
}
