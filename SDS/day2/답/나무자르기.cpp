#include<cstdio>
int N, M, m;
long long data[1000000], a, an;
int b(int s, int e) {
	while(s <= e) {
		a = 0;
		m = (s + e) / 2;
		for(int i = 0; i < N; i++) {
			if(data[i] > m) a = a + data[i] - m;
		}
		if(M == a) return m;
		else if(a > M) {
			an = m;			
			s = m + 1;
		}	
		else e = m - 1;
	}
	return an;
}
int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) scanf("%lld", &data[i]);
	printf("%d", b(0, 2000000000));
}