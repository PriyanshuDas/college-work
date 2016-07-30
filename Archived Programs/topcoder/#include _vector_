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

#define pb push_back
using namespace std;

unsigned nCr( unsigned N, unsigned k )
{
    if (k > N) return 0;
    if (k * 2 > N) k = N-k;
    if (k == 0) return 1;

    int result = N;
    for( int i = 2; i <= k; ++i ) {
        result *= (N-i+1);
        result /= i;
    }
    return result;
}

class Fragile2 {
public:
	int countPairs(vector <string> graph) {
	int points = 0;
	int n = graph.size();
	int ans = 0;
	int count[21];
	vector <int> gph[21];
	for (int i = 0; i < 21; i++)
	{
		count[i] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		int counts = 0;
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 'Y')
			{
				gph[i].pb (j);
				counts++;
			}
		}
		count[i] = counts;
		if(counts > 1)
			points++;
	}
	cout << "points - "<< points;
	int Baka = n-1;
	for(int i = 0; i< points; i++)
	{
		ans += Baka;
		Baka -= 1;
	}
	for(int i = 0; i < 21; i++)
	{
		if (count[i] == 2)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << "\n ANS " << ans;
				int curr_num = graph[i][j];
				if (count[curr_num] == 1)
				{
					ans--;
				}
			}
		}
	}
	return ans;
	}
};

