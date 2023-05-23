#include <iostream>
#include <stack>

using namespace std;

int t;
string brackets;
stack<char> stk;

int main() {
  cin >> t;

  for(int i = 0 ; i < t ; i++) {
    int flag = 0;
    cin >> brackets;

    while(!stk.empty()) stk.pop();

    for(int j = 0 ; j < brackets.length() ; j++) {
      char current = brackets[j];

      if(current == '(') stk.push(current);
      else {
        if(stk.empty()) {
          flag = 1;
          break;
        }
        stk.pop();
      }
    }

    if(!stk.empty() || flag) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}