// 백준 17143 낚시왕
/*
    1. 낚시왕이 오른쪽으로 한 칸 이동한다.
    2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
    3. 상어가 이동한다.
    
    상어는 입력으로 주어진 속도로 이동하고, 속도의 단위는 칸/초
    상어가 이동하려고 하는 칸이 격자판의 경계를 넘는 경우에는 방향을 반대로 바꿔서 속력을 유지한채로 이동
    이동을 마친 후에 한 칸에 상어가 두 마리 이상 있을 수 있다. 이때는 크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는다
*/
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Shark{
    // r,c 위치, s는 속력, d는 이동 방향, z는 크기
    // d가 0인 경우는 위, 1인 경우는 아래, 2인 경우는 오른쪽, 3인 경우는 왼쪽
    int r;
    int c;
    int s;
    int d;
    int z;
    bool live;
};
Shark sk[10001];
int n,m,c; // 격자판의 크기 n,m와 상어의 수 c
int map[101][101];
queue<int> q;
int dy[] = {-1,1,0,0}; // 0인 경우는 위, 1인 경우는 아래, 2인 경우는 오른쪽, 3인 경우는 왼쪽
int dx[] = {0,0,1,-1};
int score;
bool live[10001];

void print(){
    cout << "\n";
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void move(){
    int l = q.size();
    for(int i = 0 ; i < l ; i++){
        int cur_sk = q.front();
        
        q.pop();

        if(live[ sk[cur_sk].z ] == false) continue;

        int ny = sk[cur_sk].r;
        int nx = sk[cur_sk].c;
        int cd = sk[cur_sk].d;

        int dist;
        if(cd == 0 || cd == 1) dist = sk[cur_sk].s % ((n-1) * 2);
        else dist = sk[cur_sk].s % ((m-1) * 2);

        for(int i = 0 ; i < dist ; i++){
            ny += dy[cd];
            nx += dx[cd];

            if(ny <= 0 || ny > n || nx <= 0 || nx > m){
                if(cd == 0) cd = 1;
                else if(cd == 1) cd = 0;
                else if(cd == 2) cd = 3;
                else if(cd == 3) cd = 2;

                ny += dy[cd];
                nx += dx[cd];
                i--;
            }
        }

        if(map[ sk[cur_sk].r ][ sk[cur_sk].c ] == sk[cur_sk].z) map[ sk[cur_sk].r ][ sk[cur_sk].c ] = 0;
        if(sk[map[ny][nx]].z < sk[cur_sk].z){
            // sk[map[ny][nx]].live = false;
            live[ map[ny][nx] ] = false;
        }
        map[ny][nx] = sk[cur_sk].z;

        sk[cur_sk].r = ny;
        sk[cur_sk].c = nx;
        sk[cur_sk].d = cd;

        q.push(cur_sk);
    }
}

void fishing(int cur){
    // 2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
    for(int i = 1 ; i <= n ; i++){
        if(map[i][cur] != 0){
            // sk[ map[i][cur] ].live = false; // 이번에 잡은 물고기 표기
            live[ map[i][cur] ] = false;
            score += map[i][cur];
            map[i][cur] = 0;
            break;
        }
    }

    move();
}

int main(){
    score = 0;
    memset(live,0,sizeof(live));
    vector<int> temp;
    cin >> n >> m >> c;
    for(int i = 0 ; i < c ; i++){
        // y위치 x위치 속력 이동방향 크기
        int aa,bb,cc,dd,zz;
        cin >> aa >> bb >> cc >> dd >> zz;

        sk[zz].r = aa;
        sk[zz].c = bb;
        sk[zz].s = cc;
        sk[zz].d = dd-1;
        sk[zz].z = zz;
        live[zz] = true;
        temp.push_back(zz);
        map[aa][bb] = zz;
    }
    sort(temp.begin(), temp.end());
    for(int i = 0 ; i < temp.size() ; i++){
        q.push(temp[i]);
    }
    
    // 1. 낚시왕이 오른쪽으로 한 칸 이동한다.
    // print();
    for(int i = 1 ; i <= m ; i++){
        fishing(i);
        // print();
    }

    cout << score << "\n";

    return 0;
}
/*
    13:02 ~ 14:15
*/