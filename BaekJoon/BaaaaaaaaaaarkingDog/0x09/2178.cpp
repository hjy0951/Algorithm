#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define MAXN 101

int n, m;
int map[MAXN][MAXN], visit[MAXN][MAXN];
int dy[4] = {0, 0, 1,-1};
int dx[4] = {1,-1, 0, 0};

void printMap() {
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) cout << map[i][j] << ' ';
    cout << '\n';
  }
  cout << '\n';
}

void input() {
  vector<string> lines;

  cin >> n >> m;
  for(int i = 0 ; i < n ; i++) {
    string line;
    cin >> line;
    lines.push_back(line);
  }

  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) map[i][j] = lines[i][j] - '0';
  }
}

void bfs() {
  queue<pair<int, int> > q;
  q.push(make_pair(0, 0));
  visit[0][0] = 1;

  while(!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for(int i = 0 ; i < 4 ; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if(visit[ny][nx] > 0 || map[ny][nx] == 0) continue;

      visit[ny][nx] = visit[cy][cx] + 1;
      if(ny == n-1 && nx == m-1) break;
      q.push(make_pair(ny, nx));
    }
  }
}

int main() {
  input();
  bfs();
  cout << visit[n-1][m-1] << '\n';
  return 0;
}