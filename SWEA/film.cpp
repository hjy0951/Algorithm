// SWEA 보호필름
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int minn;
int D,W,K; // 보호 필름의 두께 D, 가로크기 W, 합격기준 K | 합격기준 K는 1이상 D이하의 정수이다. (1≤K≤D)
char film[15][25]; // 필름의 정보 | (3≤D≤13) | (1≤W≤20)
/*
    보호 필름의 성능을 검사하기 위해 합격기준 K라는 값을 사용한다.
    충격은 보호 필름 단면의 세로 방향으로 가해지므로, 세로 방향 셀들의 특성이 중요하다.
    단면의 모든 세로방향에 대해서 동일한 특성의 셀들이 K개 이상 연속적으로 있는 경우에만 성능검사를 통과하게 된다.
*/
int fin = 0;

int check(){ // 세로방향 성능 검사
    for(int i = 0 ; i < W ; i++){
        char cur = film[0][i];
        int cnt = 1;

        for(int j = 1 ; j < D ; j++){
            if(cur == film[j][i]){
                cnt++;
            }
            else{
                cnt = 1;
                cur = film[j][i];
            }
            
            if(cnt >= K) break; // 성능 검사 통과
        }
        if(cnt < K) return 0; // 같은 특성의 셀들이 K개 이하로 반복된 경우, 성능 검사 통과 X
    }

    return 1;
}

void print(){
    for(int i = 0 ; i < D ; i++){
        for(int j = 0 ; j < W ; j++){
            cout << film[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "check : " << check() << endl;
    cout << endl;
}

void find(int cnt, int cur, int curd){ // 약물 처리할 횟수, 현재 약물 처리 진행한 횟수, 현재 depth (D)
    if(fin == 1) return;

    if(cnt == cur){
        if(check() == 1){ // 성능검사 통과
            minn = cnt;
            fin = 1;
        }
        return;
    }
    else{
        char temp[25] = {0,};

        for(int i = curd ; i < D ; i++){
            memcpy(temp, film[i],sizeof(temp));
            memset(film[i], 'A', sizeof(film[i]));
            find(cnt, cur+1, i+1);
            memset(film[i], 'B', sizeof(film[i]));
            find(cnt, cur+1, i+1);
            memcpy(film[i],temp, sizeof(temp));
        }
    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        minn = 987987987;
        fin = 0;
        // memset(film,0,sizeof(film));
        // 보호 필름의 두께 D, 가로크기 W, 합격기준 K 입력
        cin >> D >> W >> K;
        // D줄에 보호 필름 단면의 정보가 주어진다. 각 줄에는 셀들의 특성 W개가 주어진다. (특성A는 0, 특성B는 1로 표시된다.)
        for(int j = 0 ; j < D ; j++){ // 각 단면
            for(int l = 0 ; l < W ; l++){ // 각 셀
                int num;
                cin >> num;

                if(num == 0){
                    film[j][l] = 'A';
                }
                else{
                    film[j][l] = 'B';
                }
            }
        }
        
        // print();
        int cnt = 0;
        while(1){
            find(cnt,0,0);
            if(fin == 1){
                break;
            }
            cnt++;
        }

        cout << "#" << i << " " << minn << endl;
    }
    return 0;
}

// memcpy = memory 복사 -> 크기 지정해줘야 함
// strcpy = string 복사 -> 초기화 안하면 에러남

/*
6 8 3
0 0 1 0 1 0 0 1
0 1 0 0 0 1 1 1
0 1 1 1 0 0 0 0
1 1 1 1 0 0 0 1
0 1 1 0 1 0 0 1
1 0 1 0 1 1 0 1
6 8 3
1 1 1 1 0 0 1 0
0 0 1 1 0 1 0 1
1 1 1 1 0 0 1 0
1 1 1 0 0 1 1 0
1 1 0 1 1 1 1 0
1 1 1 0 0 1 1 0
6 8 4
1 1 0 0 0 1 1 0
1 0 1 0 0 1 1 1
0 1 0 0 1 1 0 0
1 0 1 0 0 0 0 0
1 1 0 0 0 0 0 0
1 0 0 0 1 1 1 1


6 10 3
0 1 0 0 0 1 0 0 1 1
0 1 1 0 0 1 0 0 1 0
0 1 0 0 1 0 1 1 1 1
0 0 0 0 0 1 1 1 1 0
0 1 0 0 1 1 1 1 1 1
1 0 0 0 1 1 0 0 1 1
*/
