// 백준 2960 에라토스테네스의 체
#include <iostream> 

using namespace std;

int n, k;
int visit[1010];
int cnt;

int main(){
	cnt = 0;
	cin >> n >> k;
	for(int i = 2 ; i <= n ; i++){
		if(visit[i] == 0){
			int cur = i;

			while(cur <= n){
				if(visit[cur] == 0){
					visit[cur] = 1;
					cnt++;
					if(cnt == k){
						cout << cur << "\n";
						return 0;
					}
				}
				cur += i;
			}
		}
	}
	return 0;
}
