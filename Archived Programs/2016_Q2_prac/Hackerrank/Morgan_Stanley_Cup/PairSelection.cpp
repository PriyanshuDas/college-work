#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

int ct_R[501] = {0};
int ct_C[501] = {0};
int Mat[501][501] = {0};
int main()
{
    int N, M;   cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        string s;   cin >> s;
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == '1')
            {
                Mat[i][j] = 1;
                ct_R[i]++;
                ct_C[j]++;
            }
        }
    }
    int flag = 1, ct = 0;
    while(flag != 0)
    {
        flag = 0;
        for(int i = 0; i < N; i++)
        {
            if(ct_R[i] == 1)
            {
                flag = 1;
                ct++;
                int pos = 0;
                for(int j = 0; j < M; j++)
                {
                    if(Mat[i][j] == 1)
                    {
                        Mat[i][j] = 0;
                        ct_R[i]--;
                        ct_C[j]--;
                        pos = j;
                    }
                }
                for(int k = 0; k < N; k++)
                {
                    Mat[k][pos] = 0;
                }
                ct_R[i] = 0;
                ct_C[pos] = 0;
            }
        }
        for(int j = 0; j < M; j++)
        {
            if(ct_C[j] == 1)
            {
                flag = 1;
                ct++;
                int pos = 0;
                for(int i = 0; i < N; i++)
                {
                    if(Mat[i][j] == 1)
                    {
                        Mat[i][j] = 0;
                        ct_R[i]--;
                        ct_C[j]--;
                        pos = i;
                    }
                }
                for(int k = 0; k < M; k++)
                {
                    Mat[pos][k] = 0;
                }
                ct_R[pos] = 0;
                ct_C[j] = 0;
            }
        }
    }
    cout << ct;
    return 0;
}
