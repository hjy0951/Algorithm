#include <iostream>
#include <utility>
#include <queue>

using namespace std;

#define MAXN 1001

int n, m, tomatos, day = 1;
int map[MAXN][MAXN], visit[MAXN][MAXN];
int dy[4] = {0, 0, 1,-1};
int dx[4] = {1,-1, 0, 0};
queue<pair<int, int> > q;

void print() {
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      cout << visit[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}

void input() {
  cin >> m >> n;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      cin >> map[i][j];
      if(map[i][j] == 1) {
        q.push(make_pair(i, j));
        visit[i][j] = 1;
      }
      else if(map[i][j] == 0) tomatos++;
    }
  }
}

void bfs() {
  while(!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for(int i = 0 ; i < 4 ; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if(visit[ny][nx] > 0 || map[ny][nx] != 0) continue;

      visit[ny][nx] = visit[cy][cx] + 1;
      if(day < visit[ny][nx]) day = visit[ny][nx];
      q.push(make_pair(ny, nx));
      tomatos--;
    }
    // print();
  }
}

int main() {
  input();
  if(tomatos > 0) bfs();
  if(tomatos > 0) cout << "-1\n";
  else cout << day-1 << '\n';
  return 0;
}