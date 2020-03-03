// 백준 1987 알파벳
/*
    세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다
    보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다
    말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데,
    새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다.

    좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int r,c;
char map[25][25];
int visit[25][25];
int alpha[28];
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
int maxn;

void print(){
    printf("\n");
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void bt(int y, int x, int cnt){
    if(cnt > maxn) maxn = cnt;
    
    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < r && nx >= 0 && nx < c){
            if(visit[ny][nx] == 0 && alpha[ map[ny][nx] - 'A' ] == 0){
                visit[ny][nx] = 1;
                alpha[ map[ny][nx] - 'A' ] = 1;
                bt(ny,nx,cnt+1);
                visit[ny][nx] = 0;
                alpha[ map[ny][nx] - 'A' ] = 0;
            }
        }
    }
    
}

int main(){
    scanf("%d %d", &r, &c);
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            scanf(" %1c", &map[i][j]);
        }
    }
    maxn = 1;

    visit[0][0] = 1;
    alpha[ map[0][0] - 'A' ] = 1;
    bt(0,0,1);

    printf("%d\n", maxn);
    
    return 0;
}