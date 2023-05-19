#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
  int n;
  vector<int> nums;
  vector<int> answer;
  stack<int> stk;

  cin >> n;
  for(int i = 0, num ; i < n ; i++) {
    cin >> num;
    nums.push_back(num);
  }
  answer.assign(n, -1);

  for(int i = n-1 ; i >= 0 ; i--) {
    int current = nums[i];

    if(stk.empty()) {
      stk.push(current);
      continue;
    }

    while(!stk.empty() && stk.top() <= current) stk.pop();
    if(!stk.empty()) answer[i] = stk.top();
    stk.push(current);
  }

  for(int i = 0 ; i < answer.size() ; i++) cout << answer[i] << ' ';
  cout << '\n';

  return 0;
}