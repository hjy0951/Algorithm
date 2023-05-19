#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<int> buildings;
stack<int> stk;

int main() {
  long long count = 0;
  cin >> n;
  
  for(int i = 0, height ; i < n ; i++) {
    cin >> height;
    buildings.push_back(height);
  }
  
  for(int i = 0 ; i < n ; i++) {
    int current = buildings[i];

    if(stk.empty()) {
      stk.push(current);
      continue;
    }

    while(stk.top() <= current) {
      stk.pop();
      if(stk.empty()) break;
    }

    count += stk.size();
    stk.push(current);
  }

  cout << count << '\n';
  return 0;
}