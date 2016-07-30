
        #include <bits/stdc++.h>

        #define sf scanf
        #define pf printf
        #define ll long long int
        #define mp make_pair
        #define max_l 1000000
        #define pb push_back

        using namespace std;

        int memo[2*max_l+1];
        string s_mem[2*max_l+1];
        vector<string> string_list;
        ll decode(string s)
        {
            ll ans = 0;
            for(int i = 0; i < s.size(); i++)
            {
                switch(s[i])
                {
                case '0':
                {
                    ans += i + 1;
                    break;
                }
                case '1':
                {
                    ans -= (i+1);
                    break;
                }
                case '2':
                {
                    ans *= (i+1);
                    break;
                }
                default:
                    break;
                }
            }
            return ans;
        }

        void gen(string s)
        {
            if(s.size() > 14)
                return;
            string s1 = s;
            int val = max_l + decode(s);
            int len = s.size();
            //cout << val << endl;
            if(val < 2*max_l && val >= 0 && (memo[val] == -1 || len < memo[val]))
            {
                s_mem[val] = s1;
                memo[val] = len;
            }
            for(int i = 0; i < 3; i++)
            {
                char ch = '0'+i;
                string s2 = s+ch;
                string_list.pb(s2);
                gen(s2);
            }
        }

        int main()
        {
            memset(memo, -1, sizeof(memo));
            gen("");
            for(int i = 1; i <= 1000; i++)
            {
                int curr = i+max_l;
                /*if(s_mem[curr] == "")
                {
                    cout << i << '\t';
                }*/
                cout << i << " " << s_mem[curr] << endl;
            }
            return 0;
        }
