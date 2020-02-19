// 백준 1202 보석도둑
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 가방에는 최대 '한 개'의 보석만 넣을 수 있다.
struct Node{
 	int w; // 무게
 	int v; // 가격
}; 

struct cmp{
	bool operator()(Node x, Node y){
		return x.v < y.v; // 가격을 기준으로 오름차순 | 부등호 반대면 오름차순
	}
};
bool comp(const Node &x, const Node &y){
	return x.w < y.w;
}  // 무게 비교

int n,k;
Node jew[300000]; // 보석 : 무게 | 가격 
int bag[300000];
long long int maxv; // 최대 가격
// 가격을 기준으로 힙을 이용
priority_queue< Node, vector<Node>, cmp > pq;

 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	maxv = 0;
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++) cin >> jew[i].w >> jew[i].v;
	for(int i = 0 ; i < k ; i++) cin >> bag[i];
	// 오름차순 정렬 
	sort(jew, jew + n, comp); // 보석의 무게 기준으로
	sort(bag,bag+k);
	
	// 용량이 작은 무게부터 보석을 하나씩 넣어보며 최대치를 찾음
	int cnt = 0;
	for(int i = 0 ; i < k ; i++){
		while(bag[i] >= jew[cnt].w && cnt < n) pq.push(jew[cnt++]);
		if(!pq.empty()){
			Node x;
			x = pq.top();
			maxv += x.v;
			pq.pop();
		}
	}
	
	cout << maxv << endl;
 	return 0;
}
