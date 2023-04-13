// 백준 1963 소수경로
/*
    네 자리 소수 두 개를 입력받아서 한 자리 수만 바꿔 두번째 수에 도달하는 데에 몇 단계나 필요한지 계산
    두 소수 A에서 B로 바꾸는 과정에서도 항상 네 자리 소수임을 유지해야 하고
    ‘네 자리 수’라 하였기 때문에 0039 와 같은 1000 미만의 비밀번호는 허용되지 않는다.
*/
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int prime[10000];
int visit[10000];
int s, e;

void copy_arr(int arr1[], int arr2[]){ // 배열 복사
    for(int i = 0 ; i < 4 ; i++){
        arr2[i] = arr1[i];
    }
}

int to_int(int arr[]){ // 각 자리 수를 더해 배열을 정수로 만듦
    return arr[0] + arr[1]*10 + arr[2]*100 + arr[3]*1000;
}

void bfs(){
    queue<int> q;
    q.push(s);
    visit[s] = 1;

    while(!q.empty()){
        int cur = q.front();
        int temp_cur = cur;
        q.pop();
        // if(cur == e) return;

        // cout << cur << "\n";
        int digit[4];
        for(int i = 0 ; i < 4 ; i++){ // 현재 수를 각 자리 수로 나누어 배열에 저장
            digit[i] = temp_cur%10;
            temp_cur = temp_cur / 10;
        }

        int temp[4];
        int tn;
        // 1의 자리
        copy_arr(digit,temp);
        for(int i = 1 ; i < 10 ; i++){
            if(i == digit[0]) continue;

            temp[0] = i;
            tn = to_int(temp);
            if(prime[tn] == 0 && visit[tn] == 0){ // 소수이고 처음 도달한 수라면
                q.push(tn);
                visit[tn] = visit[cur] + 1;
            }
        }
        // 10의 자리
        copy_arr(digit,temp);
        for(int i = 0 ; i < 10 ; i++){
            if(i == digit[1]) continue;

            temp[1] = i;
            tn = to_int(temp);
            if(prime[tn] == 0 && visit[tn] == 0){
                q.push(tn);
                visit[tn] = visit[cur] + 1;
            }
        }
        // 100의 자리
        copy_arr(digit,temp);
        for(int i = 0 ; i < 10 ; i++){
            if(i == digit[2]) continue;

            temp[2] = i;
            tn = to_int(temp);
            if(prime[tn] == 0 && visit[tn] == 0){
                q.push(tn);
                visit[tn] = visit[cur] + 1;
            }
        }
        
        // 1000의 자리
        copy_arr(digit,temp);
        for(int i = 1 ; i < 10 ; i++){
            if(i == digit[3]) continue;

            temp[3] = i;
            tn = to_int(temp);
            if(prime[tn] == 0 && visit[tn] == 0){
                q.push(tn);
                visit[tn] = visit[cur] + 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2 ; i < 10000 ; i++){ // 소수면 prime[i] == 0
        if(prime[i] == 0){
            int temp = 2*i;

            while(temp < 10000){
                if(prime[temp] == 0){
                    prime[temp] = 1;
                }
                temp += i;
            }
        }
    }
    
    int t;
    cin >> t;
    while(t--){
        cin >> s >> e;

        if(s == e){
            cout << "0\n";
            continue;
        }

        bfs();
        
        if(visit[e] != 0) cout << visit[e]-1 << "\n";
        else cout << "impossible\n";

        memset(visit,0,sizeof(visit));
    }

    return 0;
}