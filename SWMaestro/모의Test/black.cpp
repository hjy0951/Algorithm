// 구름level 근묵자흑
/*
    수열에서 특정 윈도우 내에 값들은 그중 최소값으로 값들이 바뀌게 된다.
    이때 모든 값들이 같은 값으로 바뀌는 최소 횟수를 구하는 문제.

	주어지는 수들은 중복되지 않는다.
	어차피 최종 결과는 최소값으로 모든 배열이 바뀌게 된다.
    DP인줄 알았지만 단순 계산문제.
    최솟값을 기준으로 윈도우를 잡고 윈도우를 옮겨가면서 최소 횟수를 구하면 된다.
*/
#include <iostream>

using namespace std;

int n; // 2 ~ 10만 => N^2으로 안풀림
int k; // 2 ~ n
int arr[100000];
int test[100000];
int minn;
int minidx;
int mincnt;

void copy_arr(int arr1[], int arr2[]){
	for(int i = 0 ; i < n ; i++){
		arr2[i] = arr1[i];
	}
}

void find(int s, int e){
	// for(int i = s ; i <= e ; i++) test[i] = minn;
	int cnt = 1;
	while(s > 0){
		s -= k-1;
		cnt++;
	}
	while(e < n-1){
		e += k-1;
		cnt++;
	}
	
	if(cnt < mincnt) mincnt = cnt;
}

int main() {
	minn = 987987987;
	mincnt = 987987987;
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
		if(minn > arr[i]){
			minn = arr[i];
			minidx = i;
		}
	}
	
	for(int i = 0 ; i < k ; i++){
		int s = minidx - i;
		if(s < 0) break;
		int e = minidx + k - 1 - i;
		if(e > n) continue;
		copy_arr(arr,test);
		find(s,e);
	}
	
	cout << mincnt << "\n";
	return 0;
}