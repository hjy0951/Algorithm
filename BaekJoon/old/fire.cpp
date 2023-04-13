// 백준 5427 불
// 백준 4179 불! 과 같은 문제. 조건만 다르게 주어짐
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int map[1000][1000];
int visit[1000][1000];
int f[1000][1000];
int n, m;
int sy, sx, fy, fx;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int minn;
queue<pair<int, int> > fq;

void printmap(int arr[][1000]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void fire() {
	while (!fq.empty()) {
		int cy = fq.front().first;
		int cx = fq.front().second;
		fq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] == 1 && f[ny][nx] == 0) {
				f[ny][nx] = f[cy][cx] + 1;
				fq.push(make_pair(ny, nx));
			}
		}
	}
}

void escape() {
	queue<pair<int, int> > q;
	q.push(make_pair(sy, sx));
	visit[sy][sx] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < n && nx >= 0 && nx < m && visit[ny][nx] == 0 && map[ny][nx] == 1 && ((visit[cy][cx]+1 < f[ny][nx]) || (f[ny][nx] == 0)) ) {
				visit[ny][nx] = visit[cy][cx] + 1;
				q.push(make_pair(ny, nx));
			}
			else if ((ny < 0 || ny >= n || nx < 0 || nx >= m) && (map[cy][cx] == 1)) {
				minn = min(minn, visit[cy][cx]);				
			}
		}
	}
}

int main() {
    int t;
    scanf(" %d", &t);

    for(int q = 0 ; q < t ; q++){
        minn = 987987987;
        scanf(" %d %d", &m, &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char a;
                scanf(" %1c", &a);

                if (a == '#' ) {
                    map[i][j] = 0;
                }
                else if (a == '*') {
                    fq.push(make_pair(i, j));
                    f[i][j] = 1;
                    map[i][j] = 0;
                }
                else if (a == '@') {
                    sy = i;
                    sx = j;
                    map[i][j] = 1;
                }
                else {
                    map[i][j] = 1;
                }
            }
        }

        fire();
        escape();

        if(minn != 987987987) printf("%d\n", minn);
        else {
            printf("IMPOSSIBLE\n");
        }

        memset(f,0,sizeof(f));
        memset(visit,0,sizeof(visit));
        // while(!fq.empty()){
        //     fq.pop();
        // }

    }
	
	return 0;
}