#include <iostream>

using namespace std;

#define MAXN 4096

int n;
int map[MAXN][MAXN];
int minuss, zeros, ones;

void input() {
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n ; j++) cin >> map[i][j];
  }
}

int checkSametype(int len, int sy, int sx) {
  int prev = map[sy][sx];

  for(int i = sy ; i < sy + len ; i++) {
    for(int j = sx ; j < sx + len ; j++) {
      if(prev != map[i][j]) return 0;
      prev = map[i][j];
    }
  }
  return 1;
}

void findPapers(int len, int sy, int sx) {
  int currentType = map[sy][sx];
  int prev = map[sy][sx];
  int thirds = len/3;

  if(!checkSametype(len, sy, sx)) {
    findPapers(thirds, sy, sx);
    findPapers(thirds, sy, sx + thirds);
    findPapers(thirds, sy, sx + (len - thirds));

    findPapers(thirds, sy + thirds, sx);
    findPapers(thirds, sy + thirds, sx + thirds);
    findPapers(thirds, sy + thirds, sx + (len - thirds));

    findPapers(thirds, sy + (len - thirds), sx);
    findPapers(thirds, sy + (len - thirds), sx + thirds);
    findPapers(thirds, sy + (len - thirds), sx + (len - thirds));
  }
  else {
    if(currentType > 0) ones++;
    else if(currentType == 0) zeros++;
    else minuss++;
  }
}

int main() {
  input();
  findPapers(n, 0, 0);

  cout << minuss << '\n';
  cout << zeros << '\n';
  cout << ones << '\n';
  return 0;
}