#include <bits/stdc++.h>

#define ll long long int

using namespace std;

string message;

class Stack
{
	private:
		string s;
	public:
	void push(char c)
	{
		s += c;
		return;
	}
	char pull()
	{
		return s[s.size() - 1];
	}
	char pop()
	{
		char c = s[s.size() - 1];
		s = s.substr(0, s.size() - 1);
		return c;
	}
	int check()
	{
		if(s.size() == 0)
			return 0;
		return 1;
	}
};


string new_msg = "";
Stack S;
set<string> Set;
int ans = 0;

void dp(int pos, string msg)
{
	//cout<< msg<< endl;
	if(pos == message.size())
	{
		if(!(S.check()))
		{
			Set.insert(msg);
			//cout << msg << endl;
		}
		if(msg == message)
			ans++;
	}
	if(S.check())
	{
		char c = S.pop();
		//cout << "$" << c << "$"<<endl;
		msg += c;
		//cout <<"$$" <<  msg << "$$"<<endl;
		dp(pos, msg);
		S.push(c);
		msg = msg.substr(0, msg.size() - 1);
	}
	
	if(pos < message.size())
	{
		S.push(message[pos]);
		dp(pos+1, msg);
		S.pop();
	}
	return;
}

int main()
{
	cin >> message;
	/*for(int i = 0; i < message.size(); i++)
		S.push(message[i]);
	cout<< message << endl;
	for(int i = 0; i < message.size(); i++)
		cout << S.pop();*/
	dp(0, "");
	cout << ans << " " << Set.size();
	return 0;
}
