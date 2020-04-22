// 백준 14891 톱니바퀴
/*
    총 8개의 톱니를 가지고 있는 톱니바퀴 4개
    톱니는 N극 또는 S극 중 하나
    톱니바퀴에는 번호가 매겨져 있는데, 가장 왼쪽 톱니바퀴가 1번, 그 오른쪽은 2번, 그 오른쪽은 3번, 가장 오른쪽 톱니바퀴는 4번
    톱니바퀴를 총 K번 회전
    회전은 시계 방향과 반시계 방향 = 방향이 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향
    톱니바퀴를 회전시키려면, 회전시킬 톱니바퀴와 회전시킬 방향을 결정
    톱니바퀴 A를 회전할 때, 그 옆에 있는 톱니바퀴 B와 서로 맞닿은 톱니의 극이 다르다면, B는 A가 회전한 방향과 반대방향으로 회전
    톱니바퀴의 초기 상태와 톱니바퀴를 회전시킨 방법이 주어졌을 때, 최종 톱니바퀴의 상태를 구하는 프로그램
    회전 후,
        1번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 1점
        2번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 2점
        3번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 4점
        4번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 8점
*/
#include <iostream>
#include <string>

using namespace std;

int g[4][8];
int k;
int moved[4];

void print(){
    cout << "\n";
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void rotate(int n, int d){
    int temp;
    if(d == 1){
        temp = g[n][7];
        for(int i = 7 ; i > 0 ; i--) g[n][i] = g[n][i-1];
        g[n][0] = temp;
    }
    else if(d == -1){
        temp = g[n][0];
        for(int i = 0 ; i < 7 ; i++) g[n][i] = g[n][i+1];
        g[n][7] = temp;
    }
}

void move(int n, int d){
    rotate(n,d);
    if(n == 0){
        moved[0] = 1;
        if(d == 1){
            if(moved[1] == 0 && g[1][6] != g[0][3]) move(1,-1);
        }
        else{
            if(moved[1] == 0 && g[1][6] != g[0][1]) move(1,1);
        }
        moved[0] = 0;
    }
    else if(n == 1){
        moved[1] = 1;
        if(d == 1){
            if(moved[0] == 0 && g[0][2] != g[1][7]) move(0,-1);
            if(moved[2] == 0 && g[2][6] != g[1][3]) move(2,-1);
        }
        else{
            if(moved[0] == 0 && g[0][2] != g[1][5]) move(0,1);
            if(moved[2] == 0 && g[2][6] != g[1][1]) move(2,1);
        }
        moved[1] = 0;
    }
    else if(n == 2){
        moved[2] = 1;
        if(d == 1){
            if(moved[1] == 0 && g[1][2] != g[2][7]) move(1,-1);
            if(moved[3] == 0 && g[3][6] != g[2][3]) move(3,-1);
        }
        else{
            if(moved[1] == 0 && g[1][2] != g[2][5]) move(1,1);
            if(moved[3] == 0 && g[3][6] != g[2][1]) move(3,1);
        }
        moved[2] = 0;
    }
    else{
        moved[3] = 1;
        if(d == 1){
            if(moved[2] == 0 && g[2][2] != g[3][7]) move(2,-1);
        }
        else{
            if(moved[2] == 0 && g[2][2] != g[3][5]) move(2,1);
        }
        moved[3] = 0;
    }
}

int main(){
    for(int i = 0 ; i < 4 ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < str.size() ; j++){
            g[i][j] = str[j] - '0';
        }
    }

    cin >> k;
    // print();

    for(int i = 0 ; i < k ; i++){
        int n,d;
        cin >> n >> d;
        move(n-1,d);
        // print();
    }

    cout << g[0][0] + g[1][0] * 2 + g[2][0] * 4 + g[3][0] * 8 << "\n";

    return 0;
}

/*
    13:20 ~ 13:54
*/