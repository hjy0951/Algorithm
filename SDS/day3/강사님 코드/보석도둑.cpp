#include<cstdio>
#include<queue>
#include<algorithm>
#define mpair pair<int,int>
using namespace std;
typedef struct comp {
	bool operator() (const mpair &a, const mpair &b) const{
		return a.second < b.second;
	}
};
int n, k, i, b[300000], c;
long long a;
mpair p[300000];
priority_queue<mpair, vector<mpair>, comp> pq;
int main() {
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++) scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p + n);
	for (i = 0; i < k; i++) scanf("%d", &b[i]);
	sort(b, b + k);
	for (i = 0; i < k; i++) {
		while (b[i] >= p[c].first && c < n) pq.push(p[c++]);
		if (!pq.empty()) {
			a += pq.top().second;
			pq.pop();
		}
	}
	printf("%lld", a);
}