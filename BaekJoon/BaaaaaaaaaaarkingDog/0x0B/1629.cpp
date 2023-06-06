#include <iostream>

using namespace std;

long long int mul(long long int num, long long int cnt, long long int div) {
  if(cnt == 0) return 1;
  else if(cnt == 1) return num % div;
  
  long long int temp = mul(num, cnt/2, div) % div;
  if(cnt % 2) return temp * temp % div * num % div;
  else return temp * temp % div;
}

int main() {
  long long int a,b,c;
  cin >> a >> b >> c;
  cout << mul(a, b, c) << '\n';
  return 0;
}