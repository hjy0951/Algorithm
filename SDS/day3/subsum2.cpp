// 백준 2042 구간 합 구하기
// 세그먼트 트리를 이용해 푸는 것이 일반적인 듯
// 하지만 슬라이딩 윈도우로 간단히 풀 수 았을 것 같았다.
#include <iostream>

using namespace std;

int n,m,k;
// M은 수의 변경이 일어나는 회수 = O(1)
// K는 구간의 합을 구하는 회수 = O(n)
long long int arr[1000000];
long long int sum;
int s,e;
int ns,ne;

int main(){
	cin >> n >> m >> k;	
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	s = -1;
	e = -1;
	ns = -1;
	ne = -1;
	sum = 0; 
	for(int i = 0 ; i < m+k ; i++){
		int a,b,c;
		cin >> a >> b >> c;
		
		if(a == 1){ // 변경 
			// s <= b <= e 라면 변경 사항을 구간의 합에 반영
			if(s >= 0 && e >= 0){
				if(b-1 >= s && b-1 <= e){
					int mod = arr[b-1];
					sum -= mod;
					arr[b-1] = c;
					sum += c;	
				}
				else arr[b-1] = c;
			}
			else{ // s,e가 설정 안된 경우 그냥 변경
				arr[b-1] = c;
			}
		}
		else{ // 구간의 합
			if(s >= 0 && e >= 0){
				ns = b-1;
				ne = c-1;
				
				if(ns > s){
					for(int i = s ; i < ns ; i++){
						sum -= arr[i];
					}
				}
				else if(ns < s){
					for(int i = ns ; i < s ; i++){
						sum += arr[i];
					}
				}
				
				if(ne > e){
					for(int i = e+1 ; i <= ne ; i++){
						sum += arr[i];
					}
				}
				else if(ne < e){
					for(int i = ne+1 ; i <= e ; i++){
						sum -= arr[i];
					}
				}
				
				s = ns;
				e = ne;
			}
			else{
				 s = b-1;
				 e = c-1;
				 for(int i = s ; i <= e ; i++){
				 	sum += arr[i];
				 }
			}
			cout << sum << endl;
		}
	}
	return 0;
}
