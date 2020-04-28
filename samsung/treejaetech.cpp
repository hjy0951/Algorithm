// 백준 16235 나무 재테크
/*
    N×N 크기의 땅
    가장 처음에 양분은 모든 칸에 5만큼 들어있다.
    M개의 나무를 구매해 땅에 심었다.
    이 나무는 사계절을 보내며, 아래와 같은 과정을 반복한다.
    봄
        나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 
        각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다. 
        하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 
        만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
    여름
        봄에 죽은 나무가 양분으로 변하게 된다. 
        각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.
    가을
        나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 
        어떤 칸 (r, c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 이다. 
        상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.

    겨울
        S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다. 각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.

    K년이 지난 후 상도의 땅에 살아있는 나무의 개수를 구하는 프로그램
*/
#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n, m, k;
int sup[11][11];
int food[11][11];
deque<int> map[11][11];
queue<pair<int,int> > dead;
queue<pair<int,int> > breed;
// 인접한 8방향
int dy[] = {1,-1,0, 0,1, 1,-1,-1};
int dx[] = {0, 0,1,-1,1,-1, 1,-1};

void spring(){
// 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 
// 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 
// 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(map[i][j].size() >= 1){
                int len = map[i][j].size();
                for(int q = 0 ; q < len ; q++){
                    int cur_age = map[i][j].front();
                    map[i][j].pop_front();

                    if(food[i][j] >= cur_age){
                        food[i][j] -= cur_age;
                        cur_age++;

                        if(cur_age % 5 == 0) breed.push(make_pair(i,j));
                    }
                    else{
                        cur_age = (-1) * cur_age; // 양분을 먹지 못해 죽음
                        dead.push(make_pair(i,j));
                    }

                    map[i][j].push_back(cur_age);
                }
            }
        }
    }
}
void summer(){
// 봄에 죽은 나무가 양분으로 변하게 된다. 
// 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.
    while(!dead.empty()){
        int cy = dead.front().first;
        int cx = dead.front().second;
        dead.pop();

        while(map[cy][cx].back() < 0){
            int cur = (-1) * map[cy][cx].back();
            map[cy][cx].pop_back();
            food[cy][cx] += cur/2;

            if(map[cy][cx].empty() == true) break;
        }
    }
}
void autumn(){
// 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 
// 어떤 칸 (r, c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 이다. 
// 상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.
    while(!breed.empty()){
        int cy = breed.front().first;
        int cx = breed.front().second;
        breed.pop();

        for(int i = 0 ; i < 8 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                map[ny][nx].push_front(1);
            }
        }
    }
}
void winter(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            food[i][j] += sup[i][j];
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> sup[i][j];
        }
    }
    for(int i = 0 ; i < m ; i++){
        int r,c,a;
        cin >> r >> c >> a;
        map[r-1][c-1].push_front(a);
    }
    // 처음 양분 상태
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            food[i][j] = 5;
        }
    }

    while(k--){
        spring();
        summer();
        autumn();
        winter();
    }

    int num = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            num += map[i][j].size();
        }
    }
    cout << num << "\n";

    return 0;
}

/*
    12:20 ~ 13:20
*/