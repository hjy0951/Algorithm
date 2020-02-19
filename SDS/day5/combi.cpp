// 백준 11050 이항계수1
#include <iostream>

using namespace std;

int n,k;
int tri[20][20];
int main(){
	cin >> n >> k;
	
	// 파스칼 삼각형 만들기
	tri[0][0] = 1;
	tri[1][0] = 1;
	tri[1][1] = 1;
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j <= i ; j++){
			if(j ==0 || j == i) tri[i][j] = 1;
			else tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
		}
	}
	
	cout << tri[n][k] << "\n";
	
	return 0;
}
