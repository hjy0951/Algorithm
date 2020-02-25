// SWEA 특이한 자석
#include <iostream>
#include <cstring>

using namespace std;

int mv[4];
int K; // 회전시킬 횟수
int magnet[4][8]; // 자석 상태 | 날의 자성은 N 극이 0 으로, S 극이 1 로 주어진다.
// 자석을 회전시키는 방향은 시계방향이 1 로, 반시계 방향이 -1 로 주어진다.

void print(int* arr){
    for(int i = 0 ; i < 8 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rotate(int* mgnt, int dir){ // 자석 회전
    int temp;
    if(dir == 1){ // 시계 방향
        for(int i = 7 ; i > 0 ; i--){
            temp = mgnt[i];
            mgnt[i] = mgnt[i-1];
            mgnt[i-1] = temp;
        }
    }
    else{ // 반시계 방향
        for(int i = 0 ; i < 7 ; i++){
            temp = mgnt[i];
            mgnt[i] = mgnt[i+1];
            mgnt[i+1] = temp;
        }
    }
}

void operation(int num, int dir){ // 회전 명령 실행
    if(mv[num] == 1){
        return;
    }
    else{
        rotate(magnet[num], dir); // 회전
        mv[num] = 1;

        if(dir == 1){ // 시계 방향
            if(num == 0){
                if(magnet[1][6] != magnet[0][3]){
                    operation(1,-1);
                }
            }
            else if(num == 3){
                if(magnet[2][2] != magnet[3][7]){
                    operation(2,-1);
                }
            }
            else if(num == 2){
                if(magnet[3][6] != magnet[2][3]){
                    operation(3,-1);
                }
                if(magnet[1][2] != magnet[2][7]){
                    operation(1,-1);
                }
            }
            else if(num == 1){
                if(magnet[2][6] != magnet[1][3]){
                    operation(2,-1);
                }
                if(magnet[0][2] != magnet[1][7]){
                    operation(0,-1);
                }
            }
        }
        else{ // 반시계 방향
            if(num == 0){
                if(magnet[1][6] != magnet[0][1]){
                    operation(1,1);
                }
            }
            else if(num == 3){
                if(magnet[2][2] != magnet[3][5]){
                    operation(2,1);
                }
            }
            else if(num == 2){
                if(magnet[3][6] != magnet[2][1]){
                    operation(3,1);
                }
                if(magnet[1][2] != magnet[2][5]){
                    operation(1,1);
                }
            }
             else if(num == 1){
                if(magnet[2][6] != magnet[1][1]){
                    operation(2,1);
                }
                if(magnet[0][2] != magnet[1][5]){
                    operation(0,1);
                }
            }
        }
    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        // 명령 수 입력
        cin >> K;

        //자석 상태 입력
        for(int j = 0 ; j < 4 ; j++){
            for(int k = 0 ; k < 8 ; k++){
                cin >> magnet[j][k];
            }
        }
        
        // 명령 입력, 실행
        for(int j = 0 ; j < K ; j++){
            memset(mv,0,sizeof(mv));

            int num, dir;
            cin >> num >> dir; // 자석 번호 | 회전 방향

            operation(num-1, dir); // 명령 실행
        }

        // 점수 계산
        int total = magnet[0][0] + magnet[1][0] * 2 + magnet[2][0] * 4 + magnet[3][0] * 8;

        cout << "#" << i << " " << total << endl;
    }
    return 0;
}