// 백준 : 1920 수 찾기
// 정렬 후 이분 탐색으로 간단하게 찾음
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int num[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        cin >>  num[i];
    }
    sort(num, num+n);

    cin >> m;
    for(int i = 0 ; i < m ; i++){
        int a;
        cin >> a;

        if(binary_search(num,num+n, a) == 1) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
