// 백준 1991 트리 순회
#include <iostream> 

using namespace std;

struct Node{
	char data;
	int left;
	int right;	
};

Node tree[27];
int n;

void preorder(Node x){
	cout << x.data;
	if(x.left != 0) preorder(tree[x.left]);
	if(x.right != 0) preorder(tree[x.right]);
}
void inorder(Node x){
	if(x.left != 0) inorder(tree[x.left]);
	cout << x.data;
	if(x.right != 0) inorder(tree[x.right]);
}
void postorder(Node x){
	if(x.left != 0) postorder(tree[x.left]);
	if(x.right != 0) postorder(tree[x.right]);
	cout << x.data;
}

int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		char p,l,r;
		cin >> p >> l >> r;
		
		int cur = p - 'A';
		tree[cur].data = p;
		
		if(l != '.') tree[cur].left = l - 'A';
		else tree[cur].left = 0;
		
		if(r != '.') tree[cur].right = r - 'A';
		else tree[cur].right = 0;
	}
	
	preorder(tree[0]);
	cout << endl;
	inorder(tree[0]);
	cout << endl;
	postorder(tree[0]);
	
	return 0;
}
