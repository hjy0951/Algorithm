// 백준 10989 수 정렬하기 3
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; // 범위가 1~10,000,000 으로 모든 수를 저장할 경우, 메모리제한 8MB에 걸림
vector<int> v;
int num[10001]; // 숫자 개수를 저장

int main(){
    // 빠른 입출력
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;

        if(num[a] == 0){ // 처음 들어오는 수의 경우, 벡터에 넣음
            v.push_back(a);
        }
        num[a]++; // 해당 숫자의 개수를 증가
    }

    sort(v.begin(), v.end());
    for(int i = 0 ; i < v.size() ; i++){
        while(num[ v[i] ]){
            cout << v[i] << "\n";
            num[v[i]]--;
        }
    }
    return 0;
}