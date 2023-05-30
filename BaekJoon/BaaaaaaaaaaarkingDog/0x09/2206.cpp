#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAXN 1001

int n, m;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int map[MAXN][MAXN];
int visit[2][MAXN][MAXN];

void print() {
  cout << '\n';
  for(int i = 0 ; i < 2 ; i++) {
    for(int j = 0 ; j < n ; j++) {
      for(int k = 0 ; k < m ; k++) {
        cout << visit[i][j][k] << ' ';
      }
      cout << '\n';
    }
    cout << '\n';
  }
  cout << '\n';
}

void input() {
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++) {
    string line;
    cin >> line;
    for(int j = 0 ; j < m ; j++) {
      map[i][j] = line[j] - '0';
    }
  }
}

pair<pair<int,int>, int> make_3pair(int y, int x, int broken) {
  return make_pair(make_pair(y,x), broken);
}

void bfs() {
  queue<pair<pair<int,int>, int> > q;
  q.push(make_3pair(0, 0, 0));
  visit[0][0][0] = 1;

  while(!q.empty()) {
    int cy = q.front().first.first;
    int cx = q.front().first.second;
    int cb = q.front().second;
    q.pop();

    for(int i = 0 ; i < 4 ; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if(cb == 1) {
        if(map[ny][nx] == 0) {
          if(visit[cb][ny][nx] == 0) {
            visit[cb][ny][nx] = visit[cb][cy][cx] + 1;
            q.push(make_3pair(ny, nx, cb));
          }
          else {
            if(visit[cb][ny][nx] > visit[cb][cy][cx] + 1) {
              visit[cb][ny][nx] = visit[cb][cy][cx] + 1;
              q.push(make_3pair(ny, nx, cb));
            }
          }
        }
      }
      else {
        if(map[ny][nx] == 0) {
          if(visit[cb][ny][nx] == 0) {
            visit[cb][ny][nx] = visit[cb][cy][cx] + 1;
            q.push(make_3pair(ny, nx, cb));
          }
        } else {
          if(visit[1][ny][nx] == 0) {
            visit[1][ny][nx] = visit[cb][cy][cx] + 1;
            q.push(make_3pair(ny, nx, 1));
          }
          else {
            if(visit[1][ny][nx] > visit[cb][cy][cx] + 1) {
              visit[1][ny][nx] = visit[cb][cy][cx] + 1;
              q.push(make_3pair(ny, nx, 1));
            }
          }
        }
      }
    }
  }
}

int main() {
  input();
  bfs();
  // print();
  int v1 = visit[1][n-1][m-1];
  int v2 = visit[0][n-1][m-1];
  if(v1 == 0 && v2 == 0) cout << "-1\n";
  else {
    if(v1 == 0) cout << v2 << '\n';
    else if(v2 == 0) cout << v1 << '\n';
    else {
      int minValue = v1 < v2 ? v1 : v2;
      cout << minValue << '\n';
    }
  }
  return 0;
}