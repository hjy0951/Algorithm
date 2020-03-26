#include <iostream>
#include <cstdio>

using namespace std;

int mgnt[4][8];
int K;
int op[30][2];
int visit[4];

void rotate(int* m, int dir){ // 시계 방향 회전 : 1 | 반시계 방향 회전 : -1
    int temp;

    if(dir == -1){
        for(int i = 0 ; i < 7 ; i++){
            temp = m[i+1];
            m[i+1] = m[i];
            m[i] = temp;
        }
    }
    else{
        for(int i = 7 ; i > 0 ; i--){
            temp = m[i-1];
            m[i-1] = m[i];
            m[i] = temp;
        }
    }
}

void move(int mnum, int dir){
    if(visit[mnum-1] == 1){
        return;
    }
    else{
        visit[mnum-1] = 1;

        if(mnum == 1){
            rotate(mgnt[0],dir);
            if(dir == 1){
                if(mgnt[mnum-1][3] != mgnt[mnum][6]){
                    move(mnum+1,dir*(-1));
                }
            }
            else{
                if(mgnt[mnum-1][1] != mgnt[mnum][6]){
                    move(mnum+1,dir*(-1));
                }
            }
        }
        else if(mnum == 2){
            rotate(mgnt[1],dir);
            if(dir == 1){
                if(mgnt[mnum-1][3] != mgnt[mnum][6]){
                    move(mnum+1,dir*(-1));
                }
                if(mgnt[mnum-2][2] != mgnt[mnum-1][7]){
                    move(mnum-1,dir*(-1));
                }
            }
            else{
                if(mgnt[mnum-1][1] != mgnt[mnum][6]){
                    move(mnum+1,dir*(-1));
                }
                if(mgnt[mnum-2][2] != mgnt[mnum-1][5]){
                    move(mnum-1,dir*(-1));
                }
            }
            
        }
        else if(mnum == 3){
            rotate(mgnt[2],dir);
            if(dir == 1){
                if(mgnt[mnum-1][3] != mgnt[mnum][6]){
                    move(mnum+1,dir*(-1));
                }
                if(mgnt[mnum-2][2] != mgnt[mnum-1][7]){
                    move(mnum-1,dir*(-1));
                }
            }
            else{
                if(mgnt[mnum-1][1] != mgnt[mnum][6]){
                    move(mnum+1,dir*(-1));
                }
                if(mgnt[mnum-2][2] != mgnt[mnum-1][5]){
                    move(mnum-1,dir*(-1));
                }
            }
        }
        else if(mnum == 4){
            rotate(mgnt[3],dir);
            if(dir == 1){
                if(mgnt[mnum-1][7] != mgnt[mnum-2][2]){
                    move(mnum-1,dir*(-1));
                }
            }
            else{
                if(mgnt[mnum-1][5] != mgnt[mnum-2][2]){
                    move(mnum-1,dir*(-1));
                }
            }
        }
    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        memset(op, 0, sizeof(op));
        cin >> K;

        for(int j = 0 ; j < 4 ; j++){
            for(int k = 0 ; k < 8 ; k++){
                cin >> mgnt[j][k]; // N극 = 0 | S극 = 1
            }
        }

        for(int j = 0 ; j < K ; j++){
            int mnum, dir;
            cin >> mnum >> dir; // 시계 방향 회전 : 1 | 반시계 방향 회전 : -1
            memset(visit, 0, sizeof(visit));
            move(mnum, dir);
        }

        int score = 1*mgnt[0][0] + 2*mgnt[1][0] + 4*mgnt[2][0] + 8*mgnt[3][0];

        cout << "#" << i << " " << score << endl;
    }


    return 0;
}
// [ 1번 자석 : 3번 날 | 2,3번 자석 : 7, 3번 날 | 4번 자석 : 7번 날 ] 고려
// 마지막 1번 날의 위치로 점수계산
// N극 = 0점 | S극 = [1 2 4 8] 순으로 점수
// N극 = 0 | S극 = 1
// 시계 방향 회전 : 1 | 반시계 방향 회전 : -1

/*
#1 10
#2 14
#3 3
#4 13
#5 15
#6 10
#7 2
#8 6
#9 5
#10 4
*/