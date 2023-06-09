#include <iostream>

using namespace std;

#define MAXN 128

int n, whites, blues;
int map[MAXN][MAXN];

void input() {
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++) cin >> map[i][j];
  }
}

void findPapers(int len, int sy, int sx) {
  int halfLen = len / 2;
  int cnt = 0;

  for(int i = sy ; i < sy+len ; i++) {
    for(int j = sx ; j < sx+len ; j++) {
      if(map[i][j]) cnt++;
    }
  }

  if(!cnt) whites++;
  else if(cnt == len*len) blues++;
  else {
    findPapers(halfLen, sy, sx);
    findPapers(halfLen, sy, sx+halfLen);
    findPapers(halfLen, sy+halfLen, sx);
    findPapers(halfLen, sy+halfLen, sx+halfLen);
  }
}

int main() {
  input();
  findPapers(n, 0, 0);
  cout << whites << '\n' << blues << '\n';
  return 0;
}