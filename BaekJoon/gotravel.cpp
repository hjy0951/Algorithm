// 백준 1976 여행 가자
/*
도시들의 개수와 도시들 간의 연결 여부가 주어져 있고,
여행 계획에 속한 도시들이 순서대로 주어졌을 때(중복 가능) 가능한지 여부를 판별하는 프로그램
 = 계획에 포함된 도시들이 하나의 집합 안에 포함되어 있다면 가능

> Union-Find Algorithm을 이용하여 해결
*/
#include <iostream>
#include <set>

using namespace std;

int n, m; // 전체 도시 수 | 여행할 도시 수
set<int> s;
int p[201];

int f(int x){ // find
    if(p[x] == x) return x;
    else return f(p[x]);
}

void u(int x, int y){ // union
    x = f(x);
    y = f(y);

    if(x != y){
        if(x > y) p[x] = y;
        else p[y] = x;
    }
}

int main(){
    cin >> n >> m;

    // 초기화
    for(int i = 1 ; i <= n ; i++){
        p[i] = i;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int a;
            cin >> a;
            if(i >= j) continue;
            
            if(a == 1){ // union-find를 위해 트리 구조 형성
                u(i,j);
            }
        }
    }
    for(int i = 0 ; i < m ; i++){
        int a;
        cin >> a;
        s.insert(a);
        // 양방향 그래프이므로 중복된 도시일 경우 한번 도착하면 다시 갈 수 있다.
        // 따라서 set을 통해 중복 제거
    }
    
    int ox = 1;
    int rep = -1;

    set<int>::iterator it;
    for(it = s.begin() ; it !=  s.end() ; it++){ // set을 돌아보면서 같은 집합인지 확인
        if(rep < 0) rep = f(*it);
        else{
            int temp = f(*it);
            if(temp != rep){
                ox = 0;
                break;
            }
        }
    }

    if(ox == 1) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}