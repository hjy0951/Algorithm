#include <iostream>
#include <vector>

using namespace std;

long long n, m;
int maxH;
vector<int> trees;

int binarySearch() {
  int sp = 0, ep = maxH-1, mid = 0;
  int ret = 0;

  while(ep - sp >= 0) {
    long long total = 0;
    mid = (sp + ep) / 2;
    for(int i = 0 ; i < trees.size() ; i++) {
      int tree = trees[i];
      if(tree <= mid) continue;
      total += tree - mid;
    }

    if(total == m) {
      return mid;
    } else if(total < m) {
      ep = mid -1;
    } else {
      sp = mid + 1;
      ret = mid;
    }
  }

  return ret;
}

int main() {
  int h = 0;
  cin >> n >> m;

  for(int i = 0 ; i < n ; i++) {
    int tree;
    cin >> tree;
    trees.push_back(tree);
    if(maxH < tree) maxH = tree;
  }

  h = binarySearch();
  cout << h << '\n';
  return 0;
}