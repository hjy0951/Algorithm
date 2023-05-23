#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int point;
string brackets;
vector<int> numbers;
vector<int> stk;

void printStk() {
  for(int i = 0 ; i < stk.size() ; i++) cout << stk[i] << ' ';
  cout << '\n';
}

void makeNumbers() {
  for(int i = 0 ; i < brackets.length() ; i++) {
    char current = brackets[i];

    if(current == '(') numbers.push_back(-1);
    else if(current == ')') numbers.push_back(-4);
    else if(current == '[') numbers.push_back(-2);
    else if(current == ']') numbers.push_back(-3);
  }
}

int execute() {
  for(int i = 0 ; i < numbers.size() ; i++) {
    int current = numbers[i];

    // printStk();

    if(current < 0) { // 괄호일 때
      if(current > -3) stk.push_back(current);
      else {
        int ac = 0;

        while(!stk.empty() && stk.back() > 0) {
          ac += stk.back();
          stk.pop_back();
        }

        if(stk.empty()) return 0;

        if(stk.back() + current != -5) {
          // 올바르지 않은 괄호
          return 0;
        } else {
          stk.pop_back();
          if(ac == 0) ac++;
          if(current == -4) ac *= 2;
          else ac *= 3;
        }

        if(stk.size() == 0) point += ac;
        else stk.push_back(ac);
      }
    }
  }
  return 1;
}

int main() {
  int isRight = 0;
  cin >> brackets;

  makeNumbers();
  isRight = execute();

  if(stk.size() > 0) isRight = 0;

  if(isRight) cout << point << '\n';
  else cout << "0\n";

  return 0;
}