#include <iostream>
#include <stack>

using namespace std;

string brackets;
stack<char> stk;

int main() {
  int count = 0, opens = 0, p = 0;
  char current, next;

  cin >> brackets;

  while(p < brackets.length()) {
    current = brackets[p];
    if(current == '(' && p+1 < brackets.length()) {
      next = brackets[p+1];
      if(next == ')') {
        count += opens;
        p++;
      }
      else {
        stk.push(current);
        opens++;
      }
    }
    else if(current == ')') {
      stk.pop();
      opens--;
      count++;
    }

    p++;
  }

  cout << count << '\n';

  return 0;
}