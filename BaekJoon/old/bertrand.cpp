// 백준 4948 베르트랑 공준
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parr[123456*2+1];
vector<int> prime; // 소수를 담아둘 벡터

int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    prime.push_back(1);
    for(int i = 2 ; i <= 123456*2 ; i++){
        if(parr[i] == 0){
            prime.push_back(i);

            int temp = i*2;
            while(temp <= 123456*2){
                parr[temp] = 1;
                temp += i;
            }
        }
    }

    int n = -1;
    while(1){
        cin >> n;
        if(n == 0) return 0;

        if(n == 1){
            cout << "1\n";
            continue;
        }
        int ub = upper_bound(prime.begin(), prime.end(), n) - prime.begin(); // n보다 큰 소수 중 가장 작은 소수 탐색
        int lb = lower_bound(prime.begin(), prime.end(), 2*n) - prime.begin(); // 2*n과 같거나 작은 소수 탐색

        cout << lb - ub << "\n";
    } 

    return 0;
}