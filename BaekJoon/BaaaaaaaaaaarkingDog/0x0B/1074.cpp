#include <iostream>

using namespace std;

int n, c, r;
int clen;
int point;

int power(int cnt) {
  int res = 2;
  while(cnt > 0) {
    res *= 2;
    cnt--;
  }
  return res;
}

void init() {
  cin >> n >> r >> c;
  clen = power(n);
}

int findQuarter() {
  int halfLen = clen / 2;

  if(r < halfLen && c < halfLen) return 1;
  else if(r < halfLen && c >= halfLen) return 2;
  else if(r >= halfLen && c < halfLen) return 3;
  else if(r >= halfLen && c >= halfLen) return 4;
  return 0;
}

void execute() {
  int quarter;

  while(1) {
    quarter = findQuarter();

    if(clen == 2) {
      point += quarter;
      break;
    } else {
      clen /= 2;
      point += (clen * clen) * (quarter - 1);
      if(quarter == 2) c -= clen;
      else if(quarter == 3) r -= clen;
      else if(quarter == 4) {
        c -= clen;
        r -= clen;
      }
    }
  }
}

int main() {
  init();
  execute();
  cout << point-1 << '\n';
  return 0;
}

/*
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
*/