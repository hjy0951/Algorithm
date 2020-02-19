// Lazy Propagation 알아두면 좋음
// 세그먼트 트리의 배열 크기는 보통 N*4를 절대 넘지 않음
// 백준 5639 이진 탐색 트리
#include <iostream> 
#include <cstdio>
#include <algorithm>

using namespace std;

struct Node{
	int data;
	int left;
	int right;
};

Node tree[10000];
int cnt; 

void makeTree(int idx, int x){ // INSERT
	if(x < tree[idx].data){ // left
		if(tree[idx].left == 0){ // child x
			tree[idx].left = cnt;
			tree[cnt++].data = x;
			return;
		}
		else{ // child o
			makeTree(tree[idx].left, x);
		}
	}
	else{ // right
		if(tree[idx].right == 0){ // child x
			tree[idx].right = cnt;
			tree[cnt++].data = x;
			return;
		}
		else{ // child o
			makeTree(tree[idx].right, x);
		}
	}
}

void postorder(Node x){
	if(x.left != 0) postorder(tree[x.left]);
	if(x.right != 0) postorder(tree[x.right]);
	printf("%d\n", x.data);
}

int main(){
	int f;
	cin >> f;
	tree[0].data = f;
	tree[0].left = 0;
	tree[0].right = 0;
	cnt++;
	 
	int num;
	while(scanf("%d", &num) != EOF){ // 백준에서만 확인 가능
//	if(num == -1) break;
//	while(cin >> num){
		makeTree(0, num);
	}
	
	postorder(tree[0]);
	return 0;
}
