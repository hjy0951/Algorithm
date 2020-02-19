// 백준 1735 분수의 합  
#include <iostream>

using namespace std;

int gcd(int a, int b){ // 최대공약수 구하기
	if(a < b){ // 항상 a > b
		int temp = a;
		a = b;
		b = temp;
	}
	
	int gcd;
	while(b != 0){
		gcd = a % b;
		a = b;
		b = gcd;
	}
	return a;
}

int main(){
	int c1,p1;
	int c2,p2;
	cin >> c1 >> p1;
	cin >> c2 >> p2;
	
	int g = gcd(p1,p2); // 분모의 최대 공약수를 구함
	int np = p1 * (p2/g);
	int nc = c1*(p2/g) + c2*(p1/g); // 분모에 곱한 값을 분자에도 곱하여 더함
	int ng = gcd(np,nc); // 분모 분자의 최대 공약수를 구해 나눠줌
	
	cout << nc/ng << " " << np/ng << "\n";
	return 0;
}
