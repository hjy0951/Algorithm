#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x, temp;
vector<int> v;

void input() {
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  cin >> x;
}

int main() {
  int count = 0;
  int p = 0, q, sum;

  input();
  sort(v.begin(), v.end());
  q = n-1;
  
  while(p < q) {
    sum = v[p] + v[q];

    if (sum > x) q--;
    else if (sum < x) p++;
    else {
      count++;
      p++;
      q--;
    }
  }

  cout << count << '\n';
  return 0;
}