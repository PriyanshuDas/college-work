#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(v) v.begin(), v.end()

const int mod = 1e9 + 7;

int a[123];
int dp[123][5];
int n;

int rec(int ind, int prev){
	//cout << ind << " " << prev << endl;
	if(ind == n)
		return 0;

	if(dp[ind][prev] != -1)
		return dp[ind][prev];

	dp[ind][prev] = 2e9;
	if(a[ind] == 0){
		dp[ind][prev] = min(dp[ind][prev], 1 + rec(ind + 1, 3));
	}
	else if(a[ind] == 1){
		dp[ind][prev] = min(dp[ind][prev], 1 + rec(ind + 1, 3));
		if(prev != 2)
			dp[ind][prev] = min(dp[ind][prev], rec(ind + 1, 2));
	}
	else if(a[ind] == 2){
		dp[ind][prev] = min(dp[ind][prev], 1 + rec(ind + 1, 3));
		if(prev != 1)
			dp[ind][prev] = min(dp[ind][prev], rec(ind + 1, 1));
	}
	else if(a[ind] == 3){
		dp[ind][prev] = min(dp[ind][prev], 1 + rec(ind + 1, 3));
		if(prev != 2)
			dp[ind][prev] = min(dp[ind][prev], rec(ind + 1, 2));
		if(prev != 1)
			dp[ind][prev] = min(dp[ind][prev], rec(ind + 1, 1));
	}

	return dp[ind][prev];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> n;

	for(int i=0;i<n;i++)
		cin >> a[i];

	memset(dp, -1, sizeof(dp));
	cout << rec(0, 3) << endl;

	return 0;
}
