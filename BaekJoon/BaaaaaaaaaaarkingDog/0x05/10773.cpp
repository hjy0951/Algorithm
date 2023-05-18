#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> stk;
  int k, temp, sum = 0;

  cin >> k;
  for(int i = 0 ; i < k ; i++) {
    cin >> temp;
    if(temp == 0) stk.pop();
    else stk.push(temp);
  }
  while(!stk.empty()) {
    sum += stk.top();
    stk.pop();
  }
  cout << sum << '\n';
  return 0;
}