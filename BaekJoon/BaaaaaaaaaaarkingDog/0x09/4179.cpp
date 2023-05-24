#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 1001

int r, c;
int map[MAXN][MAXN], fire[MAXN][MAXN], visit[MAXN][MAXN];
int dy[4] = {0, 0, 1,-1};
int dx[4] = {1,-1, 0, 0};
queue<pair<int,int> > q, fireQ;

void input() {
  string line;
  vector<string> lines;
  cin >> r >> c;
  for(int i = 0 ; i < r ; i++) {
    cin >> line;
    lines.push_back(line);
  }

  for(int i = 0 ; i < r ; i++) {
    for(int j = 0 ; j < c ; j++) {
      char current = lines[i][j];

      if(current == '#') map[i][j] = 1;
      else if(current == 'J') q.push(make_pair(i, j));
      else if(current == 'F') {
        fireQ.push(make_pair(i, j));
        fire[i][j] = 1;
      }
    }
  }
}

void makeFireMap() {
  while(!fireQ.empty()) {
    int cy = fireQ.front().first;
    int cx = fireQ.front().second;
    fireQ.pop();

    for(int i = 0 ; i < 4 ; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
      if(fire[ny][nx] > 0 || map[ny][nx] == 1) continue;

      fire[ny][nx] = fire[cy][cx] + 1;
      fireQ.push(make_pair(ny, nx));
    }
  }
}

int bfs() {
  // int visit[MAXN][MAXN] = {0, };
  int sy = q.front().first;
  int sx = q.front().second;

  visit[sy][sx] = 1;
  
  while(!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for(int i = 0 ; i < 4 ; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if(ny < 0 || ny >= r || nx < 0 || nx >= c) return visit[cy][cx] + 1;
      if(visit[ny][nx] > 0 || map[ny][nx] == 1 || (fire[ny][nx] > 0 && (fire[ny][nx] <= visit[cy][cx] + 1))) continue;

      visit[ny][nx] = visit[cy][cx] + 1;
      q.push(make_pair(ny, nx));
    }
  }
  return -1;
}

int main() {
  input();
  makeFireMap();
  int result = bfs();

  if(result == -1) cout << "IMPOSSIBLE\n";
  else cout << result-1 << '\n';

  return 0;
}