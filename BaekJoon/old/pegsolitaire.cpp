// 백준 9207 페그 솔리테어
/*
    핀은 수평, 수직 방향으로 인접한 핀을 뛰어넘어서 그 핀의 다음 칸으로 이동하는 것만 허용된다. 
    인접한 핀의 다음 칸은 비어있어야 하고 그 인접한 핀은 제거된다.
    이때, 핀을 적절히 움직여서 게임판에 남아있는 핀의 개수를 최소로 하려고 한다. 
    또, 그렇게 남기기 위해 필요한 최소 이동횟수를 구하는 프로그램을 작성하시오
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int minpin;
int mincnt;

void print(int arr[][10]){
    cout << '\n';
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

// 남은 핀 수 return
int counting(int arr[][10]){
    int ret = 0;
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 9 ; j++){
            if(arr[i][j] == 1) ret++;
        }
    }
    return ret;
}

// 맵 복사
void copy(int arr1[][10], int arr2[][10]){
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            arr2[i][j] = arr1[i][j];
        }
    }
}

// back tracking
void bt(int game[][10], int cnt){
    bool moved = false;
    int map[6][10];
    copy(game,map);

    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            if(map[i][j] == 1){
                for(int k = 0 ; k < 4 ; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if(ny < 0 || ny >= 5 || nx < 0 || nx >= 9) continue;

                    int nny = ny + dy[k];
                    int nnx = nx + dx[k];

                    if(nny < 0 || nny >= 5 || nnx < 0 || nnx >= 9) continue;

                    if(map[ny][nx] == 1 && map[nny][nnx] == 0){
                        map[i][j] = 0;
                        map[ny][nx] = 0;
                        map[nny][nnx] = 1;

                        moved = true;
                        bt(map, cnt+1);

                        map[i][j] = 1;
                        map[ny][nx] = 1;
                        map[nny][nnx] = 0;
                    }
                }
            }
        }
    }

    int temppin = counting(map);
    if(temppin < minpin){
        minpin = temppin;
        mincnt = cnt;
    }
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int map[6][10];
        mincnt = 987987987;
        minpin = 987987987;

        for(int i = 0 ; i < 5 ; i++){
            string str;
            cin >> str;

            for(int j = 0 ; j < 9 ; j++){
                if(str[j] == '#') map[i][j] = 2; // 벽
                else if(str[j] == '.') map[i][j] = 0; // 빈칸
                else if(str[j] == 'o') map[i][j] = 1; // 핀이 꽂힌 칸
            }
        }

        bt(map, 0);

        cout << minpin << " " << mincnt << '\n';
    }

    return 0;
}
