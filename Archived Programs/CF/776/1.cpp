#include <bits/stdc++.h>

#define ins insert 

using namespace std;

int main()
{
	set <string> S;
	string s1, s2;
	cin >> s1 >> s2;
	S.ins(s1);	S.ins(s2);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		auto it = S.begin();
		cout << *it;
		it++;
		cout << ' ' << *it << endl;
		cin >> s1 >> s2;
		S.erase(s1);
		S.ins(s2);
	}
	auto it = S.begin();
	cout << *it;
	it++;
	cout << ' ' << *it << endl;
	return 0;
}