// 백준 1010 다리 놓기
#include <iostream> 

using namespace std;
// 강의 서쪽에는 N개의 사이트
// 동쪽에는 M개의 사이트 (N <= M)
// 다리끼리는 서로 겹쳐질 수 없다
// M개 중 N개를 뽑는 경우의 수
int t;
int n,m;
int tri[1001][1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	
	// 파스칼의 삼각형 만들기
	tri[0][0] = 1;
	tri[1][0] = 1;
	tri[1][1] = 1;
	for(int i = 1 ; i <= 30 ; i++){
		for(int j = 0 ; j <= i ; j++){
			if(j ==0 || j == i) tri[i][j] = 1;
			else tri[i][j] = (tri[i-1][j-1] + tri[i-1][j]); 
		}
	}
	
	for(int i = 0 ; i < t ; i++){
		cin >> n >> m;
		
		if(n == m){
			cout << "1\n";
		}
		else{
			int k = m-n;
			cout << tri[m][k] << "\n";
		}
	}
	
	
	return 0;
}
