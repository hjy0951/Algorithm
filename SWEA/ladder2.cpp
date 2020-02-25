/*
SWEA SW 문제해결 ladder2
     100 x 100 크기의 2차원 배열로 주어진 사다리에 대해서, 모든 출발점을 검사하여 가장 짧은 이동 거리를 갖는 시작점 x(복수 개인 경우 가장 큰 x좌표)를 반환하는 코드
     ladder1과 다른 조건은 동일
*/

#include <iostream>

using namespace std;

int mindist; // 최단 거리
int num;
int map[100][100]; 

void start(int y, int x){
    int sx = x;
    int dist = 0; // 현재 거리

    for(int i = 0 ; i < 99 ; i++){
        y++;
        dist++;

        if(x == 0 && map[y][x+1] == 0){
            continue;
        }
        else if(x == 0 && map[y][x+1] == 1){
            while(map[y][x+1] == 1 && x+1 < 100){
                x++;
                dist++;
            }
            continue;
        }

        if(x == 99 && map[y][x-1] == 0){
            continue;
        }
        else if(x == 99 && map[y][x-1] == 1){
            while(map[y][x-1] == 1 && x-1 >= 0){
                x--;
                dist++;
            }
            continue;
        }

        if(map[y][x+1] == 0 && map[y][x-1] == 0){

        }
        else if(map[y][x-1] == 0 && map[y][x+1] == 1){
            while(map[y][x+1] == 1 && x+1 < 100){
                x++;
                dist++;
            }
        }
        else if(map[y][x-1] == 1 && map[y][x+1] == 0){
            while(map[y][x-1] == 1 && x-1 >= 0){
                x--;
                dist++;
            }
        }
    }

    if(dist <= mindist){
        mindist = dist;
        num = sx;
    }
}

int main(){
    for(int q = 1 ; q <= 10 ; q++){
        mindist = 987987987;
        num = -1;

        // input
        int t;
        cin >> t;
        for(int i = 0 ; i < 100 ; i++){
            for(int j = 0 ; j < 100 ; j++){
                cin >> map[i][j];
            }
        }

        for(int i = 0 ; i < 100 ; i++){
            if(map[0][i] == 1){
                start(0,i);
            }
        }

        cout << "#" << q << " " << num << endl;
    }
    return 0;
}

/*
#1 18
#2 96
#3 16
#4 5
#5 99
#6 0
#7 97
#8 0
#9 62
#10 3

*/