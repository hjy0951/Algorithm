// 백준 9019 DSLR
/*
    네 개의 명령어 D, S, L, R 을 이용하는 간단한 계산기가 있다
    이 계산기의 레지스터에는 0 이상 10,000 미만의 십진수를 저장할 수 있다
    
    * 명령어 DSLR *
        D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다.
           그 결과 값(2n mod 10000)을 레지스터에 저장한다.
        S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다.
           n이 0 이라면 9999 가 대신 레지스터에 저장된다.
        L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다.
           이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
        R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다.
           이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.

    서로 다른 두 정수 A와 B(A ≠ B)에 대하여 A를 B로 바꾸는 최소한의 명령어를 생성하는 프로그램
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int s,e;
int visit[10000]; // 방문 여부
int prevnum[10000]; // 현재 인덱스의 숫자에 가장 먼저 도달했을 때, 직전 숫자를 저장
char op[10000]; // 현재 인덱스의 숫자에 가장 먼저 도달했을 때, 직전 명령어를 저장

void copy_arr(int arr1[], int arr2[]){
    for(int i = 0 ; i < 4 ; i++){
        arr2[i] = arr1[i];
    }
}
int to_int(int arr[]){
    return arr[0] + arr[1]*10 + arr[2]*100 + arr[3]*1000;
}

/////////// DSLR 명령어 ////////////
int D(int x){
    return (x * 2) % 10000;
}
int S(int x){
    if(x == 0) return 9999;
    else return x - 1;
}
void L(int arr[]){
    int temp;
    for(int i = 3 ; i > 0 ; i--){
        temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
    }
}
void R(int arr[]){
    int temp;
    for(int i = 0 ; i < 3 ; i++){
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}
//////////////////////////////////

void solve(){
    queue<int> q;
    q.push(s);
    visit[s] = 1;

    while(!q.empty()){
        int cur_num = q.front();
        q.pop();

        if(cur_num == e) return;

        int clone_cur = cur_num;
        int digit[4];
        int temp[4];
        for(int i = 0 ; i < 4 ; i++){ // 각 자리의 숫자를 배열에 저장
            digit[i] = clone_cur % 10;
            clone_cur = clone_cur / 10;
        }

        int next_num;
        next_num = D(cur_num);
        if(visit[next_num] == 0){
            visit[next_num] = 1;
            prevnum[next_num] = cur_num;
            op[next_num] = 'D';
            q.push(next_num);
        }

        next_num = S(cur_num);
        if(visit[next_num] == 0){
            visit[next_num] = 1;
            prevnum[next_num] = cur_num;
            op[next_num] = 'S';
            q.push(next_num);
        }
        
        copy_arr(digit,temp);
        L(temp);
        next_num = to_int(temp);
        if(visit[next_num] == 0){
            visit[next_num] = 1;
            prevnum[next_num] = cur_num;
            op[next_num] = 'L';
            q.push(next_num);
        }

        copy_arr(digit,temp);
        R(temp);
        next_num = to_int(temp);
        if(visit[next_num] == 0){
            visit[next_num] = 1;
            prevnum[next_num] = cur_num;
            op[next_num] = 'R';
            q.push(next_num);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i++){
        // 빠른 입출력
        memset(visit,0,sizeof(visit));
        memset(prevnum,-1,sizeof(prevnum));
        memset(op,0,sizeof(op));

        cin >> s >> e; // 초기값, 나중값

        solve();

        int idx = e;
        // 벡터에 담았다가 다시 역으로 출력
        vector<char> v;
        while(prevnum[idx] != -1){
            // cout << op[idx];
            v.push_back(op[idx]);
            idx = prevnum[idx];
        }

        for(int j = v.size()-1 ; j >= 0 ; j--){
            cout << v[j];
        }
        cout << "\n";
    }
    

    return 0;
}
/*
3
1234 3412
1000 1
1 16
*/