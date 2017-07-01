#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class ORSolitaire {
public:
	int getMinimum(vector <int> numbers, int goal) {
		int ct[32] = {0};
		for(int i = 0; i < 32; i++)
			ct[i] = 0;
		int ans = 9999;
		int bt = 0;
		for(int i = 0; i < 32; i++)
		{
			for(int j = 0; j < numbers.size(); j++)
			{
				if(((1<<i)&numbers[j]) && (numbers[j]|goal) == goal)
					ct[i]++;
			}
			if((1<<i)&goal)
			{
			    //printf("%d\t%d\n", i, ct[i]);
				if(ct[i] < ans)
                {
                    ans = ct[i];
                    bt = i;
                }
			}
		}
		int tot = 0;
		for(int i = 0; i < numbers.size(); i++)
		{
		    if(((tot|numbers[i])|goal) == goal)
                tot = (tot|numbers[i]);
		}
		//cout << tot << ' ' << bt << endl;
		if(tot != goal)
            ans = 0;
		return ans;
	}
};



int main()
{
    ORSolitaire S;
    int goal, n;   vector<int> numbers;
    cin >> n >> goal;
    for(int i = 0; i < n; i++)
    {
        int tmp;    cin >> tmp; numbers.push_back(tmp);
    }
    cout << S.getMinimum(numbers, goal);
}
