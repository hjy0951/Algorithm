#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAXN 501

int n, m, maxArea, num;
int map[MAXN][MAXN], visit[MAXN][MAXN];
int dy[4] = {0, 0, 1,-1};
int dx[4] = {1,-1, 0, 0};

void input() {
  cin >> n >> m;

  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) cin >> map[i][j];
  }
}

void bfs(int y, int x) {
  int area = 1;
  queue<pair<int,int> > q;
  q.push(make_pair(y, x));
  visit[y][x] = 1;

  while(!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for(int i = 0 ; i < 4 ; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if(visit[ny][nx] != 0 || map[ny][nx] == 0) continue;

      visit[ny][nx] = 1;
      area++;
      q.push(make_pair(ny, nx));
    }
  }

  if(maxArea < area) maxArea = area;
}

int main() {
  input();
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      if(visit[i][j] != 0 || map[i][j] == 0) continue;
      bfs(i, j);
      num++;
    }
  }

  cout << num << '\n' << maxArea << '\n';
  return 0;
}