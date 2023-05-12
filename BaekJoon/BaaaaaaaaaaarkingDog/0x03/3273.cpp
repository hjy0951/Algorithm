#include <iostream>

using namespace std;

int n[10];
int maxCount;

int main() {
  string str;
  cin >> str;

  for(int i = 0 ; i < str.length() ; i++) {
    int current = str[i] - '0';
    n[current]++;

    if(current == 6 || current == 9) {
      int countSum = n[6] + n[9];
      if(countSum % 2 == 1) countSum++;
      countSum /= 2;
      if(countSum > maxCount) maxCount = countSum;
    } else {
      if(n[current] > maxCount) maxCount = n[current];
    }
  }
  cout << maxCount << '\n';
  return 0;
}