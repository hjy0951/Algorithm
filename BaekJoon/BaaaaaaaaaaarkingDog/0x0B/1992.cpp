#include <iostream>

using namespace std;

#define MAXN 64

int n;
int map[MAXN][MAXN];

void input() {
  string line;
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    cin >> line;
    for(int j = 0 ; j < n ; j++) map[i][j] = line[j] - '0';
  }
}

int checkSameNumbers(int len, int sy, int sx) {
  int prev = map[sy][sx];
  for(int i = sy ; i < sy + len ; i++) {
    for(int j = sx ; j < sx + len ; j++) {
      if(prev != map[i][j]) return 0;
    }
  }
  return 1;
}

void compaction(int len, int sy, int sx) {
  if(checkSameNumbers(len, sy, sx)) {
    cout << map[sy][sx];
    return;
  }

  cout << '(';

  int halfLen = len / 2;
  compaction(halfLen, sy, sx);
  compaction(halfLen, sy, sx + halfLen);
  compaction(halfLen, sy + halfLen, sx);
  compaction(halfLen, sy + halfLen, sx + halfLen);

  cout << ')';
}

int main() {
  input();
  compaction(n, 0, 0);
  cout << '\n';
  return 0;
}

/*
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
0 0 0 1 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1

0
0 0 1 1
0 (0111) 0 1
1
*/