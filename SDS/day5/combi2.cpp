// 백준 이항계수2 11051
#include <iostream>

using namespace std;

int n,k;
long long tri[1001][1001];
int main(){
	cin >> n >> k;
	
	// 파스칼 삼각형
	tri[0][0] = 1;
	tri[1][0] = 1;
	tri[1][1] = 1;
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j <= i ; j++){
			if(j ==0 || j == i) tri[i][j] = 1;
			else tri[i][j] = (tri[i-1][j-1] + tri[i-1][j])%10007; 
		}
	}
	
	cout << tri[n][k] << "\n";
	
	return 0;
}
