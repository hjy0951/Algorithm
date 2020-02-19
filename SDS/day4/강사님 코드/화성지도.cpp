#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 10000
#define MAXY 30000

struct Range {
	int x, yl, yr, flag;
	Range(int _x, int _yl, int _yr, int _flag) : x(_x), yl(_yl), yr(_yr), flag(_flag) {};
	bool operator < (const Range & op) const {
		return x < op.x;
	}
};

struct TreeNode {
	int sum, cnt;
} tree[MAXY * 8];

vector<Range> v;
int N;

void update(int left, int right, int node, int nodeLeft, int nodeRight, int value) {
	if (left > nodeRight || right < nodeLeft) return;
	if (left <= nodeLeft && nodeRight <= right) tree[node].cnt += value;
	else {
		int mid = (nodeLeft + nodeRight) / 2;
		update(left, right, node * 2, nodeLeft, mid, value);
		update(left, right, node * 2 + 1, mid + 1, nodeRight, value);
	}
	if (!tree[node].cnt)
		tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
	else
		tree[node].sum = nodeRight - nodeLeft + 1;
}

int main() {
	int x1, y1, x2, y2, sx, ans;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		v.push_back(Range(x1, y1, y2, 1));
		v.push_back(Range(x2, y1, y2, -1));
	}
	sort(v.begin(), v.end());
	ans = 0;
	sx = v[0].x;
	for (int i = 0; i < v.size(); i++) {
		ans += (v[i].x - sx) * tree[1].sum;
		update(v[i].yl, v[i].yr - 1, 1, 0, MAXY, v[i].flag);
		sx = v[i].x;
	}
	printf("%d", ans);
	return 0;
}