#include <iostream>
#include <deque>

using namespace std;

int t, n, mode;
deque<int> numbers;
string cmd, arrStr;

void init() {
  numbers.clear();
  mode = 0;

  cin >> cmd;
  cin >> n;
  cin >> arrStr;
}

void parseArr() {
  string temp = "";
  string subArrStr = arrStr.substr(1, arrStr.size()-2);
  int number;

  if(n == 0) return;

  for(int i = 0 ; i < subArrStr.length() ; i++) {
    char current = subArrStr[i];

    if(current == ',') {
      number = atoi(temp.c_str());
      numbers.push_back(number);
      temp.clear();
    }
    else temp = temp + current;
  }
  number = atoi(temp.c_str());
  numbers.push_back(number);
}

int executeCmd() {  
  for(int i = 0 ; i < cmd.length() ; i++) {
    char currentCmd = cmd[i];

    if(currentCmd == 'R') mode = !mode;
    else if(currentCmd == 'D') {
      if(numbers.size() == 0) return 0;

      if(mode) numbers.pop_back();
      else numbers.pop_front();
    }
  }
  return 1;
}

void print() {
  cout << '[';
  
  if(mode) {
    for(int i = numbers.size()-1 ; i >= 0 ; i--) {
      cout << numbers[i];
      if(i > 0) cout << ',';
    }
  }
  else {
    for(int i = 0 ; i < numbers.size() ; i++) {
      cout << numbers[i];
      if(i < numbers.size()-1) cout << ',';
    }
  }
  cout << "]\n";
}

int main() {
  int isSuccess;
  cin >> t;

  for(int i = 0 ; i < t ; i++) {
    init();
    parseArr();
    isSuccess = executeCmd();

    if(isSuccess == 1) print();
    else cout << "error\n";
  }
  return 0;
}