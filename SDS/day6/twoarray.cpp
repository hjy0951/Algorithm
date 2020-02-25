// 백준 2143 두 배열의 합
// int 범위 조심 : long long 잘 사용하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int t;
int n;
int a[1000];
vector<long long int> av;
int m;
int b[1000];
vector<long long int> bv;
long long int cnt;

int main(){
    cnt = 0;

    cin >> t;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i = 0 ; i < m ; i++){
        cin >> b[i];
    }

    // 모든 부 배열의 합 구하기 (1000 * 1000 * 2)
    for(int i = 0 ; i < n ; i++){
        int sum = a[i];
        av.push_back(sum);

        for(int j = i+1 ; j < n ; j++){
            sum += a[j];
            av.push_back(sum);
        }
    }

    for(int i = 0 ; i < m ; i++){
        int sum = b[i];
        bv.push_back(sum);

        for(int j = i+1 ; j < m ; j++){
            sum += b[j];
            bv.push_back(sum);
        }
    }

    // 부 배열의 합 정렬 (1000 * log1000)
    sort(bv.begin(), bv.end());

    // upper/lower bound 구하기 (각 log n : binary search 기반이기 때문)
    for(long long int i = 0 ; i < av.size() ; i++){
        long long int cur = av[i];

        long long int lb = lower_bound(bv.begin(), bv.end(), t - cur) - bv.begin(); // 벡터의 경우, begin()을 빼줌 / 배열의 경우 배열 포인터 뺌
        long long int ub = upper_bound(bv.begin(), bv.end(), t - cur) - bv.begin();

        cnt += ub - lb;
    }

    cout << cnt << endl;

    return 0;
}