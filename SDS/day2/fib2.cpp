// 백준 2748 피보나치 2
#include <iostream> 

using namespace std;
long long int arr[200];
int n;
int main(){
	cin >> n;
	arr[0] = 0;
	arr[1] = 1;
	
	for(int i = 1 ; i < n ; i++){
		arr[i+1] = arr[i] + arr[i-1];
	}
	cout << arr[n] << endl;
	return 0;
}
