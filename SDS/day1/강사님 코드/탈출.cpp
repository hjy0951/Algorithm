#include<cstdio>
#include<queue>
using namespace std;
typedef struct node{
	int x, y, m,c;
	node(int x, int y, int m,int c):x(x), y(y), m(m),c(c){}
	node():x(0),y(0),m(0),c(0){}
};
bool visited[52][52];
int R, C, offset[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
char t[52];
queue<node> q;
node s, e;
int main() {
	scanf("%d %d\n", &R, &C);
	for (int i = 1; i <= R; i++){
		scanf("%s", t);
		for (int j = 0; j < C; j++){
			//printf("aa%c\n", t);
			if (t[j] == 'S') s.x = i, s.y = j+1;
			else if (t[j] == 'D') e.x = i, e.y = j+1;
			else if (t[j] == '*') q.push(node(i, j+1, 1,0));
			else if(t[j]=='.')visited[i][j+1] = true;
		}
	}
	visited[e.x][e.y] = true;
	q.push(node(s.x, s.y, 0, 0));
	while (!q.empty()) {
		node cu = q.front();
		q.pop();
		if (cu.m == 0) {
			if (cu.x == e.x && cu.y == e.y){
				printf("%d", cu.c);
				return 0;
			}
			for (int i = 0; i < 4; i++){
				if (visited[cu.x + offset[i][0]][cu.y + offset[i][1]]){
					int x = cu.x + offset[i][0];
					int y = cu.y + offset[i][1];
					q.push(node(x, y, 0, cu.c + 1));
					visited[x][y] = false;
				}
			}
		}
		else{
			for (int i = 0; i < 4; i++){
				int x = cu.x + offset[i][0];
				int y = cu.y + offset[i][1];
				if (visited[x][y] && (x != e.x || y != e.y)){
					q.push(node(x, y, 1, 0));
					visited[x][y] = false;
				}
			}
		}
	}
	printf("KAKTUS");
}