// 백준 10026 적록색약
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

int n;
char map1[100][100]; // 정상인이 보는 그림
char map2[100][100]; // 적록색약이 있는 사람이 보는 그림
int visit[100][100];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void print(char arr[][100]){
    printf("\n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void print2(int arr[][100]){
    printf("\n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void bfs(char arr[][100], int y, int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    visit[y][x] = 1;
    char cur_color = arr[y][x];

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                if(arr[ny][nx] == cur_color && visit[ny][nx] == 0){
                    q.push(make_pair(ny,nx));
                    visit[ny][nx] = 1;
                }
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            char c;
            scanf(" %1c", &c);
            map1[i][j] = c;
            map2[i][j] = c;
            if(c == 'R' || c == 'G') map2[i][j] = 'G';
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(visit[i][j] == 0){
                bfs(map1, i, j);
                cnt1++;
            }
        }
    }
    memset(visit,0,sizeof(visit));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(visit[i][j] == 0){
                bfs(map2, i, j);
                cnt2++;
            }
        }
    }

    printf("%d %d\n", cnt1, cnt2);

    return 0;
}