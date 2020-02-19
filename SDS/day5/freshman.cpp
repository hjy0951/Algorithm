// 백준 5557 1학년 (DP) 
// 부분 문제로 쪼개고, 쪼개진 문제로 전체를 해결할 수 있을 때, DP
// 마지막 두 숫자 사이에 '='
// 나머지 숫자 사이에는 '+' 또는 '-'를 넣어 등식을 만듦
#include <iostream> 
#include <vector>

using namespace std;

int n;
vector<int> v;
long long int cnt;
long long int arr[101][21]; // long long 주의 

//시간 초과 코드
//void rec(int next, int res){
//	if(res < 0 || res > 20) return;
//	
//	if(next == n-1 && res == v[n-1]){
//		cnt++;
//		return;
//	}
//	else{
//		rec(next+1, res+v[next]);
//		rec(next+1, res-v[next]);
//	}
//}

int main(){
	cin >> n;
	
	for(int i = 0 ; i < n-1 ; i++){
		int a;
		cin >> a;
		
		if(i == 0){
			arr[i][a] = 1;
			continue;
		}
		
		for(int j = 0 ; j < 21 ; j++){
			if(arr[i-1][j]){
				if(j+a < 21) arr[i][j+a] += arr[i-1][j]; // 21보다 작고
				if(j-a >= 0) arr[i][j-a] += arr[i-1][j]; // 0보다 큰
			}
		}
//		for(int j = 0 ; j < 21 ; j++){
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
	}
	
	int ans;
	cin >> ans;
	
	cout << arr[n-2][ans] << "\n";
	return 0;
}
