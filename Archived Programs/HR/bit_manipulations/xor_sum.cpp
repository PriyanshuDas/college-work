#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXN=100000+10;

int A[MAXN];
int N;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &N); A[0]=0;
		for (int i=1; i<=N; i++) {
			scanf("%d", &A[i]);
			A[i]^=A[i-1];
		}
		long long ret=0;
		for (int i=0, p=1; i<30; i++, p<<=1) {
			int c=0;
			for (int j=0; j<=N; j++) {
				if (A[j]&p) c++;
			}
			ret+=(long long)c*(N-c+1)*p;
		}
		printf("%lld\n", ret);
	}
	return 0;
}
