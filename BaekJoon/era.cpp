// 백준 2960 에라토스테네스의 체
#include <iostream>

/*
    1. 2부터 N까지 모든 정수를 적는다.
    2. 아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이것을 P라고 하고, 이 수는 소수이다.
    3. P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
    4. 아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.

    N, K가 주어졌을 때, K번째 지우는 수를 구하는 프로그램을 작성하시오.
*/

using namespace std;

int n,k; // 1 ≤ K < N, max(2, K) < N ≤ 1000
int check[1001] = {0,}; // 이미 지워진 수인지 체크
int prev_p; // 이전 p
int flag; // while문 종료 flag

int find_p(){ // 다음 차례의 P return
    for(int i = prev_p ; i <= n ; i++){
        if(check[i] == 0) return i;
    }
    return -1;
}

int main(){
    cin >> n >> k;

    int cnt = 0;
    int p = 2;
    prev_p = p;
    flag = 0;

    while(1){
        p = find_p();
        prev_p = p;
        check[p] = 1;
        cnt++;
        
        if(cnt == k) break;  // k번째 지워진 수이면 끝냄

        int next = p+p;
        
        while(n >= next){
            if(check[next] == 0){
                check[next] = 1;
                cnt++;
                
                if(cnt == k){ // k번째 지워진 수이면 끝냄
                    p = next;
                    flag = 1;
                    break;
                }
            }
            next += p; // p의 배수 탐색
        }
        if(flag == 1) break;
    }

    cout << p << endl;

    return 0;
}
