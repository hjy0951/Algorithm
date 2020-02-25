/*
SWEA SW 문제해결 ladder1
    **어느 사다리를 고르면 X표시에 도착하게 되는지**
    아래 방향으로 진행하면서 좌우 방향으로 이동 가능한 통로가 나타나면 방향 전환을 하게 된다.
    방향 전환 이후엔 다시 아래 방향으로만 이동하게 되며, 바닥에 도착하면 멈추게 된다.
    100 x 100 크기의 2차원 배열로 주어진 사다리에 대해서, 지정된 도착점(2)에 대응되는 출발점 X를 반환하는 코드를 작성하라
*/

#include <iostream>

using namespace std;

int map[100][100];
int goal;

int find(int y, int x){ // 목적지부터 거꾸로 올라가 시작 위치 찾기
    for(int i = 98 ; i >= 0 ; i--){
        y--;
        
        // 양쪽에 사다리가 없는 경우
        // 한쪽에 사다리가 있는 경우
        if(x == 0 &&  map[y][x+1] == 0){
            continue;
        }
        else if(x == 0 && map[y][x+1] == 1){
            while(map[y][x+1] == 1 && x+1 < 100){
                x++;
            }
            continue;
        }

        if(x == 99 && map[y][x-1] == 0){
            continue;
        }
        else if(x == 99 && map[y][x-1] == 1){
            while(map[y][x-1] == 1 && x-1 >= 0){
                x--;
            }
            continue;
        }

        if(map[y][x-1] == 0 && map[y][x+1] == 0){

        }
        else if(map[y][x-1] == 0 && map[y][x+1] == 1){
            while(map[y][x+1] == 1 && x+1 < 100){
                x++;
            }
        }
        else if(map[y][x-1] == 1 && map[y][x+1] == 0){
            while(map[y][x-1] == 1 && x-1 >= 0){
                x--;
            }
        }
    }

    return x;
}

int main(){
    for(int x = 1 ; x <= 10 ; x++){
        goal = 0;
        int s;

        // input
        int t;
        cin >> t;
        for(int i = 0 ; i < 100 ; i++){
            for(int j = 0 ; j < 100 ; j++){
                cin >> map[i][j];

                if(map[i][j] == 2) s = j; // 목적지 위치
            }
        }

        goal = find(99,s); // 목적지부터 거꾸로 올라감

        // output
        cout << "#" << x << " " << goal << endl;
    }
    return 0;
}

/*
#1 67
#2 45
#3 39
#4 24
#5 91
#6 93
#7 90
#8 4
#9 99
#10 35
*/