#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int opnum[4];
int arr[20];
int N;
int maxnum;
int minnum;

void makeNum(int curidx, int cur){
    if(curidx == N){
        if(cur > maxnum) maxnum = cur;
        if(cur < minnum) minnum = cur;
        return;
    }
    else{
        for(int i = 0 ; i < 4 ; i++){
            if(opnum[i] == 0) continue;

            if(i == 0){
                opnum[i]--;
                makeNum(curidx+1, cur+arr[curidx]);
                opnum[i]++;
            }
            else if(i == 1){
                opnum[i]--;
                makeNum(curidx+1, cur-arr[curidx]);
                opnum[i]++;
            }
            else if(i == 2){
                opnum[i]--;
                makeNum(curidx+1, cur*arr[curidx]);
                opnum[i]++;
            }
            else if(i == 3){
                opnum[i]--;
                makeNum(curidx+1, cur/arr[curidx]);
                opnum[i]++;
            }
        }
    }
}

int main(){
    int T;
    cin >> T; // 테스트 케이스 개수

    for(int i = 1 ; i <= T ; i++){
        memset(arr,0,sizeof(arr));
        maxnum = -987987987;
        minnum = 987987987;

        cin >> N; // 숫자 개수

        for(int j = 0 ; j < 4 ; j++){ // 각 연산자 개수 입력
            int a;
            cin >> a;
            opnum[j] = a;
        } // 1 : + | 2 : - | 3 : * | 4 : /

        for(int j = 0 ; j < N ; j++){ // n개의 숫자 입력
            int b;
            cin >> b;
            arr[j] = b;
        }

        makeNum(1,arr[0]);

        cout << '#'<< i << " " << maxnum-minnum << endl;

    }

    return 0;
}