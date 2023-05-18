#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int n, current = 1, stkTop, target, idx = 0;
  stack<int> stk;
  vector<char> cmdStk;
  vector<int> goalArr;

  cin >> n;
  for(int i = 0, temp ; i < n ; i++) {
    cin >> temp;
    goalArr.push_back(temp);
  }

  while(idx < goalArr.size() && current <= n+1) {
    if(stk.empty()) {
      stk.push(current++);
      cmdStk.push_back('+');
      continue;
    }

    stkTop = stk.top();
    target = goalArr[idx];

    if(stkTop == target) {
      stk.pop();
      cmdStk.push_back('-');
      idx++;
    } else {
      stk.push(current++);
      cmdStk.push_back('+');
    }
  }

  if(!stk.empty()) cout << "NO\n";
  else {
    for(int i = 0 ; i < cmdStk.size() ; i++) {
      cout << cmdStk[i] << '\n';
    }
  }

  return 0;
}

/*
4 3 6 8 7 5 2 1

1 2 5 7
4 3 6

++++--++-+

1 2 5 3 4
3 4
1 2 5
+-+-+++-

top이 target과 같으면 pop
              다르면 push
*/