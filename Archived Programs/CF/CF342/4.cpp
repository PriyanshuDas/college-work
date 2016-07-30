#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<long long int, long long int>

using namespace std;

string s;
int arr[100001];
int num[100001];
int n, wrong = 0;

void set(int pos, int carry_l, int carry_r)
{
	int n1 = 0, n2 = 0;
	int val_l = arr[pos], val_r = arr[n-pos-1];
	if(carry_l)
		val_l--;
	if(carry_r)
		val_r--;
	if(val_l != val_r)
	{
		wrong = 1;
		return;
	}
	int fl = 0;
	for(int i = 0; i < 10 && fl != 0; i++)
	{
		for(int j = 0; j < 10 && fl != 0; j++)
		{
			if((i+j)%10 == val_l)
			{
				fl = 1;
				num[pos] = i;	num[n-pos-1] = j;
				set(pos+1, (i+j)/10, carry_l);
			}
		}
	}
}
int main()
{
	cin >> s;
	n = s.size();
	for(int i = 0; i < s.size(); i++)
		arr[i] = s[i]-'0';
	
	return 0;
}
