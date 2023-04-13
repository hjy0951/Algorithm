#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int lowerBound(vector<int>& subArr, int target) {
  int sp = 0, ep = subArr.size()-1;
  int mid = ep;

  while(ep - sp > 0) {
    mid = (sp + ep) / 2;
  
    if(subArr[mid] >= target) ep = mid;
    else sp = mid+1;
  }
  return ep;
}

int LIS() {
  vector<int> subArr;
  for(int i = 0 ; i < n ; i++) {
    int current = arr[i];
    if(subArr.empty() || current > subArr.back()) subArr.push_back(current);
    else {
      // lower_bound 찾고 대체
      int idx = lowerBound(subArr, current);
      if(idx < 0) continue;
      subArr[idx] = current;
    }
  }
  return subArr.size();
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int temp = -1;
  cin >> n;

  for(int i = 0 ; i < n ; i++) {
    cin >> temp;
    arr.push_back(temp);
  }

  cout << LIS() << '\n';
  return 0;
}