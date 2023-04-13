#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 100001

int n;
int map[MAXN][3];
int maxDP[2][3];
int minDP[2][3];

void findAns() {
  int maxAns = 0, minAns = 987987987, turn = 1;
  for(int i = 0 ; i < 3 ; i++) {
    maxDP[0][i] = map[0][i];
    minDP[0][i] = map[0][i];
  }
  for(int i = 1 ; i < n ; i++) {
    for(int j = 0 ; j < 3 ; j++) {
      if(j == 0) {
        int temp = max(maxDP[!turn][0], maxDP[!turn][1]);
        maxDP[turn][j] = map[i][j] + temp;
        temp = min(minDP[!turn][0], minDP[!turn][1]);
        minDP[turn][j] = map[i][j] + temp;
      } else if(j == 1) {
        int minNum = 987987987;
        int maxNum = 0;
        for(int k = 0 ; k < 3 ; k++) {
          int current = maxDP[!turn][k];
          if(maxNum < current) maxNum = current;
          current = minDP[!turn][k];
          if(minNum > current) minNum = current;
        }
        maxDP[turn][j] = map[i][j] + maxNum;
        minDP[turn][j] = map[i][j] + minNum;
      } else {
        int temp = max(maxDP[!turn][1], maxDP[!turn][2]);
        maxDP[turn][j] = map[i][j] + temp;
        temp = min(minDP[!turn][1], minDP[!turn][2]);
        minDP[turn][j] = map[i][j] + temp;
      }
    }
    turn = !turn;
  }
  for(int i = 0 ; i < 3 ; i++) {
    if(maxAns < maxDP[!turn][i]) maxAns = maxDP[!turn][i];
    if(minAns > minDP[!turn][i]) minAns = minDP[!turn][i];
  }
  cout << maxAns << ' ' << minAns << '\n';
}

int main() {
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < 3 ; j++) {
      cin >> map[i][j];
    }
  }
  findAns();
  return 0;
}