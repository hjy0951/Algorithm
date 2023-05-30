#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAXN 301

int n, m;
int map[MAXN][MAXN];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
queue<pair<int,int> > iceQ;
queue<pair<int,int> > meldQ;
queue<int> cntQ;

void printMap() {
  cout << '\n';
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      cout << map[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}

void input() {
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      cin >> map[i][j];
      if(map[i][j] > 0) iceQ.push(make_pair(i, j));
    }
  }
}

void bfs(int visit[][MAXN], int y, int x) {
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

      if(visit[ny][nx] == 0 && map[ny][nx] > 0) {
        visit[ny][nx] = 1;
        q.push(make_pair(ny, nx));
      }
    }
  }
}

int findGroup() {
  int visit[MAXN][MAXN] = {0, };
  int groups = 0;

  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      if(visit[i][j] == 0 && map[i][j] > 0) {
        bfs(visit, i, j);
        groups++;
      }
    }
  }
  return groups;
}

void countMeldCnt(int y, int x) {
  int cnt = 0;
  for(int i = 0 ; i < 4 ; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(map[ny][nx] == 0) cnt++;
  }

  if(cnt > 0) {
    meldQ.push(make_pair(y, x));
    cntQ.push(cnt);
  }
}

int meld() {
  int flag = 0;
  while(!meldQ.empty()) {
    int cy = meldQ.front().first;
    int cx = meldQ.front().second;
    int cnt = cntQ.front();

    meldQ.pop();
    cntQ.pop();

    map[cy][cx] -= cnt;
    if(map[cy][cx] < 0) map[cy][cx] = 0;
    if(map[cy][cx] == 0) flag = 1;
  }
  return flag;
}

int spendTime() {
  int time = 0;
  while(!iceQ.empty()) {
    int checkFlag = 0;
    int iceQLen = iceQ.size();

    for(int i = 0 ; i < iceQLen ; i++) {
      int cy = iceQ.front().first;
      int cx = iceQ.front().second;
      iceQ.pop();

      if(map[cy][cx] == 0) continue;

      countMeldCnt(cy, cx);
      iceQ.push(make_pair(cy, cx));
    }

    checkFlag = meld();
    time++;
    // printMap();

    if(checkFlag) {
      if(findGroup() >= 2) return time;
    }
  }
  return 0;
}

int main() {
  input();
  cout << spendTime() << '\n';
  return 0;
}