// 백준 17825 주사위 윷놀이
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int map[4][24]; // 22:5->(1),10->(2),15->(3) | 14 18 24
int dice[10];
int maxscore;

// 맵 확인용
void print(){
    cout << "\n";
    for(int i = 0 ; i < 24 ; i++) printf("%2d ", i);
    cout << "\n";
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 24 ; j++){
            printf("%2d ", map[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";
}

// 해당 자리에 말이 있는지 없는지 확인
bool check(int num, int p[][2], int nmap, int x, int cur){
    for(int i = 0 ; i < num ; i++){
        // 자기 자신
        if(i == cur) continue;

        // 도착한 경우
        if(nmap == 0 && x >= 21) continue;
        else if(nmap == 1 && x >= 13) continue;
        else if(nmap == 2 && x >= 17) continue;
        else if(nmap == 3 && x >= 23) continue;

        // 이미 다른 말이 해당 자리에 있는 경우
        if(nmap == 0){
            if(p[i][0] == 0 && p[i][1] == x) return false;
            else if(p[i][0] == 1 && ((x == 5 && p[i][1] == 5) || (x == 20 && p[i][1] == 12)) ) return false;
            else if(p[i][0] == 2 && ((x == 10 && p[i][1] == 10) || (x == 20 && p[i][1] == 16)) ) return false;
            else if(p[i][0] == 3 && ((x == 15 && p[i][1] == 15) || (x == 20 && p[i][1] == 22)) ) return false;
        }
        else if(nmap == 1){
            if(p[i][0] == 0 &&  ((x == 5 && p[i][1] == 5) || (x == 12 && p[i][1] == 20)) ) return false;
            else if(p[i][0] == 1 && p[i][1] == x) return false;
            else if(p[i][0] == 2 && x >= 11 && p[i][1] - x == 4) return false;
            else if(p[i][0] == 3 && x >= 11 && p[i][1] - x == 10) return false;
        }
        else if(nmap == 2){
            if(p[i][0] == 0 && ((x == 10 && p[i][1] == 10) || (x == 16 && p[i][1] == 20)) ) return false;
            else if(p[i][0] == 1 && x >= 13 && x - p[i][1] == 4) return false;
            else if(p[i][0] == 2 && p[i][1] == x) return false;
            else if(p[i][0] == 3 && x >= 13 && p[i][1] - x == 6) return false;
        }
        else if(nmap == 3){
            if(p[i][0] == 0 && ((x == 15 && p[i][1] == 15) || (x == 22 && p[i][1] == 20)) ) return false;
            else if(p[i][0] == 1 && x >= 19 && x - p[i][1] == 10) return false;
            else if(p[i][0] == 2 && x >= 19 && x - p[i][1] == 6) return false;
            else if(p[i][0] == 3 && p[i][1] == x) return false;
        }
    }
    return true;
}

// 사용할 말의 개수, 현재 몇번째 주사위, 위치정보, 현재 점수
void play(int num, int cnt, int p[][2], int score){
    if(cnt >= 10){
        maxscore = max(maxscore, score);
        return;
    }
    else{
        for(int i = 0 ; i < num ; i++){ // 현재 말 i
            int tempscore = score;
            int pos[4][2] = {0,};

            for(int j = 0 ; j < num ; j++){
                pos[j][0] = p[j][0];
                pos[j][1] = p[j][1];
            }

            int cmap = pos[i][0];
            int cx = pos[i][1];

            // 이미 도착한 상태
            if(cmap == 0 && cx >= 21) continue;
            else if(cmap == 1 && cx >= 13) continue;
            else if(cmap == 2 && cx >= 17) continue;
            else if(cmap == 3 && cx >= 23) continue;

            // 말 이동
            // 해당 자리에 말이 있는지 확인
            if(check(num, pos, cmap, cx + dice[cnt], i) == false) continue;

            cx += dice[cnt];
            if(cmap == 0 && cx > 21) cx = 21;
            else if(cmap == 1 && cx > 13) cx = 13;
            else if(cmap == 2 && cx > 17) cx = 17;
            else if(cmap == 3 && cx > 23) cx = 23;

            // 지름길로 이동
            if(cmap == 0){
                if(cx == 5) cmap = 1;
                else if(cx == 10) cmap = 2;
                else if(cx == 15) cmap = 3;
            }

            tempscore += map[cmap][cx];

            pos[i][0] = cmap;
            pos[i][1] = cx;

            play(num, cnt+1, pos, tempscore);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // map 만들기
    for(int i = 0 ; i < 21 ; i++) map[0][i] = i*2;

    map[1][5] = 10;
    for(int i = 1 ; i <= 3 ; i++) map[1][i+5] = i*3 + 10;
    for(int i = 0 ; i < 4 ; i++) map[1][9+i] = 25 + i*5;

    map[2][10] = 20;
    for(int i = 1 ; i <= 2 ; i++) map[2][10+i] = 20 + 2*i;
    for(int i = 0 ; i < 4 ; i++) map[2][13+i] = 25 + 5*i;

    map[3][15] = 30;
    for(int i = 1 ; i <= 3 ; i++) map[3][15+i] = 29 - i;
    for(int i = 0 ; i < 4 ; i++) map[3][19+i] = 25 + 5*i;

    // input
    for(int i = 0 ; i < 10 ; i++) cin >> dice[i];

    for(int i = 1 ; i <= 4 ; i++){
        int pos[4][2] = {0,};
        play(i, 0, pos, 0);
    }

    cout << maxscore << "\n";
    return 0;
}

/*
1 2 3 4 1 2 3 4 1 2

3 1 1 5 4 5 3 3 2 5
204
*/