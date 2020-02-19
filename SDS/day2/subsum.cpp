// 백준 1806 부분합
#include <iostream>

using namespace std;
// O(n^2) X
// 연속된 수들의 부분합 중에 그 합이 S '이상'이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램
int n,m;
int arr[1000000];
int min_len;
int flag;

int main(){
    flag = 0;
    min_len = 987987987;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int sum = 0;
    int s = 0;
    int e = 0;

    while(e <= n){
        // m보다 작을 때
		if(sum < m){
			sum += arr[e];
			e++;
		}
		// 이상일 때
		else if(sum >= m){
            flag = 1;
            if(min_len > e-s) min_len = e-s;

            sum -= arr[s];
            s++;
		}
    }

    if(flag) cout << min_len << endl;
    else cout << 0 << endl;
    return 0;
}
/*
10 33961
3446 7276 7627 937 9550 1712 3495 2909 4668 5230
*/