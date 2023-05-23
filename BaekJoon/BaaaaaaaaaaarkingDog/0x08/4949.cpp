#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<string> lines;
stack<char> stk;

int main() {
  string line;

  while(1) {
    getline(cin, line);
    if(line.compare(".") == 0) break;
    lines.push_back(line);
  }

  for(int i = 0 ; i < lines.size() ; i++) {
    int flag = 0;
    line = lines[i];

    for(int j = 0 ; j < line.length() ; j++) {
      char current = line[j];

      if(current == '(' || current == '[') stk.push(current);
      else if(current == ')' || current == ']') {
        if(stk.empty()) {
          flag = 1;
          break;
        }
        if((current == ')' && stk.top() != '(')
        || (current == ']' && stk.top() != '[')) {
          flag = 1;
          break;
        }

        stk.pop();
      }
    }
    if(flag || !stk.empty()) cout << "no\n";
    else cout << "yes\n";;

    while(!stk.empty()) stk.pop();
  }
  return 0;
}