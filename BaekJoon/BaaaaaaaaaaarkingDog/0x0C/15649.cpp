#include <iostream>
#include <vector>

using namespace std;

#define MAXN 9

int n, m;
int used[MAXN];
vector<int> arr;

void push(int num) {
  used[num] = 1;
  arr.push_back(num);
}

void pop(int num) {
  used[num] = 0;
  arr.pop_back();
}

void print() {
  for(int i = 0 ; i < arr.size() ; i++) cout << arr[i] << ' ';
  cout << '\n';
}

void makeArr(int cnt) {
  if(cnt == m) {
    print();
    return;
  }

  for(int i = 1 ; i <= n ; i++) {
    if(used[i]) continue;

    push(i);
    makeArr(cnt+1);
    pop(i);
  }

}

int main() {
  cin >> n >> m;

  for(int i = 1 ; i <= n ; i++) {
    push(i);
    makeArr(1);
    pop(i);
  }
  return 0;
}