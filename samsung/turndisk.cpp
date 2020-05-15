// 백준 17822 원판 돌리기
/*
    원판의 회전은 독립적으로 이루어진다
    n번 원판을 회전했을 때, 나머지 원판은 회전하지 않는다.
    원판 회전 후 처리.
        1. 번호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다. di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
        2. 원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
            (1) 그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
            (2) 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.

    원판을 T번 회전시킨 후 원판에 적힌 수의 합을 구해보자.
*/
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int n,m,t; // 원판의 반지름, 원판의 숫자 수, 회전 수
int disc[51][51];
int visit[51][51];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
int flag;

void print(int arr[][51]){  
    cout << "\n";
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// 0인 경우는 시계 방향, 1인 경우는 반시계 방향
// num의 배수의 디스크를 모두 회전
void rotate(int dir, int num){
    if(dir == 0){ // 시계
        for(int i = num ; i <= n ; i += num){
            for(int j = m ; j > 1 ; j--){
                int temp = disc[i][j];
                disc[i][j] = disc[i][j-1];
                disc[i][j-1] = temp;
            }
        }
    }
    else if(dir == 1){ // 반시계
        for(int i = num ; i <= n ; i += num){
            for(int j = 1 ; j < m ; j++){
                int temp = disc[i][j];
                disc[i][j] = disc[i][j+1];
                disc[i][j+1] = temp;
            }
        }
    }
}

// 인접한 수들을 찾기 위함
bool bfs(int y, int x){
    queue<pair<int,int> > del; // 원판 위에 없앨 수
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    del.push(make_pair(y,x));
    visit[y][x] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        int cn = disc[cy][cx];
        q.pop();

        if(cx == 1){
            if(disc[cy][m] == cn && visit[cy][m] == 0){
                del.push(make_pair(cy,m));
                q.push(make_pair(cy,m));
                visit[cy][m] = 1;
            }
            if(cx+1 <= m && disc[cy][cx+1] == cn && visit[cy][cx+1] == 0){
                del.push(make_pair(cy,cx+1));
                q.push(make_pair(cy,cx+1));
                visit[cy][cx+1] = 1;
            }
            if(cy+1 <= n && disc[cy+1][cx] == cn && visit[cy+1][cx] == 0){
                del.push(make_pair(cy+1,cx));
                q.push(make_pair(cy+1,cx));
                visit[cy+1][cx] = 1;
            }
            if(cy-1 >= 1 && disc[cy-1][cx] == cn && visit[cy-1][cx] == 0){
                del.push(make_pair(cy-1,cx));
                q.push(make_pair(cy-1,cx));
                visit[cy-1][cx] = 1;
            }
        }
        else if(cx == m){
            if(disc[cy][1] == cn && visit[cy][1] == 0){
                del.push(make_pair(cy,1));
                q.push(make_pair(cy,1));
                visit[cy][1] = 1;
            }
            if(cx-1 >= 1 && disc[cy][cx-1] == cn && visit[cy][cx-1] == 0){
                del.push(make_pair(cy,cx-1));
                q.push(make_pair(cy,cx-1));
                visit[cy][cx-1] = 1;
            }
            if(cy+1 <= n && disc[cy+1][cx] == cn && visit[cy+1][cx] == 0){
                del.push(make_pair(cy+1,cx));
                q.push(make_pair(cy+1,cx));
                visit[cy+1][cx] = 1;
            }
            if(cy-1 >= 1 && disc[cy-1][cx] == cn && visit[cy-1][cx] == 0){
                del.push(make_pair(cy-1,cx));
                q.push(make_pair(cy-1,cx));
                visit[cy-1][cx] = 1;
            }
        }
        else{
            for(int i = 0 ; i < 4 ; i++){
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if(ny >= 1 && ny <= n && nx >= 1 && nx <= m){
                    if(visit[ny][nx] == 0 && disc[ny][nx] == cn && disc[ny][nx] != 0){
                        del.push(make_pair(ny,nx));
                        q.push(make_pair(ny,nx));
                        visit[ny][nx] = 1;
                    }
                }
            }
        }
    }

    if(del.size() == 1) return false;
    else{
        // (1) 그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
        while(!del.empty()){
            int cy = del.front().first;
            int cx = del.front().second;
            del.pop();

            disc[cy][cx] = 0;
        }
        return true;
    }
}

int main(){
    cin >> n >> m >> t;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> disc[i][j];
        }
    }
    // rotate(1,2);
    // print();

    while(t--){
        flag = 0;
        
        int x,d,k;
        cin >> x >> d >> k;

        // 1. 번호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다. di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
        while(k--) rotate(d,x);

        // 2. 원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(visit[i][j] == 0 && disc[i][j] != 0){
                    bool ox = bfs(i,j);
                    if(ox == true) flag = 1;
                }
            }
        }

        // (2) 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
        if(flag == 0){
            int sum = 0;
            int num = 0;
            for(int i = 1 ; i <= n ; i ++){
                for(int j = 1 ; j <= m ; j++){
                    if(disc[i][j] != 0){
                        sum += disc[i][j];
                        num++;
                    }
                }
            }
            if(num > 0){
                double avg = (double)(sum) / (double)(num);
                for(int i = 1 ; i <= n ; i++){
                    for(int j = 1 ; j <= m ; j++){
                        if(disc[i][j] > 0){
                            if((double)(disc[i][j]) < avg) disc[i][j]++;
                            else if((double)(disc[i][j]) > avg) disc[i][j]--;
                        }
                    }
                }
            }
        }
        memset(visit,0,sizeof(visit));
    }

    int total = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            total += disc[i][j];
        }
    }
    cout << total << '\n';

    return 0;
}
