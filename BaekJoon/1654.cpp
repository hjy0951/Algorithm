#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long k, n;
long long length = 0;
long long maxLen = 0;
vector<long long> lines;

long long binarySearch() {
  long long mid, sp = 1, ep = maxLen;
  long long ret = 0;

  while(ep - sp >= 0) {
    mid = (sp + ep) / 2;

    long long canMake = 0;
    for(int i = 0 ; i < lines.size() ; i++) {
      int currentLine = lines[i];
      if(mid > currentLine) {
        continue;
      }
      else {
        canMake += currentLine / mid;
      }
    }
    if (canMake < n) {
      ep = mid - 1;
    } else {
      sp = mid+1;
      ret = mid;
    }
  }
  return ret;
}

int main() {  
  cin >> k >> n;

  for(int i = 0 ; i < k ; i++) {
    long long temp;
    cin >> temp;
    lines.push_back(temp);
    if(temp > maxLen) maxLen = temp;
  }

  sort(lines.begin(), lines.end());

  length = binarySearch();

  cout << length << '\n';
  return 0;
}

/*
4 15
802
743
457
539

152

3 4
2
6
19

6
*/