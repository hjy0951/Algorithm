// 백준 16234 인구 이동
/*
    각각의 땅에는 나라가 하나씩 존재
    인접한 나라 사이에는 국경선이 존재
    오늘부터 인구 이동이 시작되는 날
    인구 이동은 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속
        국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루동안 연다.
        위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
        국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
        연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
        연합을 해체하고, 모든 국경선을 닫는다.
    각 나라의 인구수가 주어졌을 때, 인구 이동이 몇 번 발생하는지 구하는 프로그램을
*/
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int n,l,r;
int map[51][51];
int moving[51][51];
int p[2501];
int pn[2501];
int num;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
int ox;

void clearq(queue<int> &fq){
    queue<int> empty;
    swap(fq, empty);
}

void open(int y, int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    moving[y][x] = num;
    p[num] += map[y][x];
    pn[num]++;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                int gap = abs(map[ny][nx] - map[cy][cx]);

                if(moving[ny][nx] == 0 && gap >= l && gap <= r){
                    q.push(make_pair(ny,nx));
                    moving[ny][nx] = num;
                    p[num] += map[ny][nx];
                    pn[num]++;
                    ox = 1;
                }
            }
        }
    }
}

void move(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(moving[i][j] == 0){
                num++;
                open(i,j);
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(moving[i][j] == 0) continue;

            int cur = moving[i][j];
            map[i][j] = p[cur]/pn[cur];
            moving[i][j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }

    int cnt = 0;

    while(1){
        num = 0;
        memset(p,0,sizeof(p));
        memset(pn,0,sizeof(pn));

        move();
        if(ox == 0) break;
        else cnt++;
        ox = 0;
    }

    cout << cnt << "\n";

    return 0;
}

/*
    14:37 ~ 15:12
*/