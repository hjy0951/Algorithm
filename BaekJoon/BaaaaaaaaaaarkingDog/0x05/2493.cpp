#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

int main() {
  // 입출력 속도 향상을 위한 코드
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  stack<pair<int,int> > stk;
  vector<int> idxArr;

  cin >> n;

  for(int i = 0, temp ; i < n ; i++) {
    cin >> temp;

    while(!stk.empty() && stk.top().first < temp) stk.pop();

    if(stk.empty()) idxArr.push_back(0);
    else idxArr.push_back(stk.top().second);

    stk.push(make_pair(temp, i+1));
  }

  for(int i = 0 ; i < idxArr.size() ; i++) {
    cout << idxArr[i] << ' ';
  }
  cout << '\n';

  return 0;
}