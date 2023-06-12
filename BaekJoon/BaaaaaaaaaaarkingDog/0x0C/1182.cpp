#include <iostream>
#include <vector>

using namespace std;

int n, s, cnt;
vector<int> arr;

void input() {
  cin >> n >> s;
  for(int i = 0, num ; i < n ; i++) {
    cin >> num;
    arr.push_back(num);
  }
}

void findSum(int idx, int used, int sum) {
  if(idx == arr.size()) {
    if(used > 0 && sum == s) cnt++;
    return;
  } 
  findSum(idx+1, used, sum);
  findSum(idx+1, used+1, sum+arr[idx]);
}

int main() {
  input();
  findSum(0, 0, 0);
  cout << cnt << '\n';
  return 0;
}