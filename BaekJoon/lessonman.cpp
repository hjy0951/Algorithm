// 백준 5213 과외맨
/*
    반대편으로 넘어가기 위해서 첫 줄의 가장 첫 타일에서 마지막 줄의 가장 마지막 타일로 이동하는 가장 짧은 경로
    => 문제 좀 잘 읽자. 제발.
    내가 생각한 방법도 맞지만 메모리가 커 메모리 초과가 난다..
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n;
short map[501][1001];
bool visit[501][1001];
int dy[] = {0,-1,1,0};
int dx[] = {1,0,0,-1};
int path[501 * 501];
int maxtile;

// 홀수줄 : 0 ~ n*2-1
// 짝수줄 : 1 ~ n*2-2

void print(){
    cout << '\n';
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 2*n ; j++){
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs(){
    queue<pair< pair<int,int>, pair<int,int> > > q;
    queue<int> cq;
    q.push(make_pair(make_pair(0,0),make_pair(0,1)));
    cq.push(1);
    visit[0][0] = true;
    visit[0][1] = true;
    maxtile = 1;

    while(!q.empty()){
        int ly = q.front().first.first;
        int lx = q.front().first.second;
        int ry = q.front().second.first;
        int rx = q.front().second.second;
        q.pop();
        int cc = cq.front();
        cq.pop();
        int ln = map[ly][lx];
        int rn = map[ry][rx];

        int ct;
        if(ry%2 == 0) ct = n*ry + rx/2+1 - ry/2; // 홀수
        else ct = n*ry + (rx+1)/2 - ry/2; // 짝수
        
        if(maxtile < ct) maxtile = ct;

        // left
        for(int i = 1 ; i < 4 ; i++){
            int ny = ly + dy[i];
            int nx = lx + dx[i];

            if( (ny%2 == 0 && ny >= 0 && ny < n && nx >= 0 && nx < 2*n) || (ny%2 == 1 && ny >= 0 && ny < n && nx >= 1 && nx < 2*n-1) ){
                if(!visit[ny][nx]){
                    if(map[ny][nx] == ln){
                        visit[ny][nx] = true;
                        visit[ny][nx-1] = true;
                        q.push(make_pair(make_pair(ny,nx-1),make_pair(ny,nx)));
                        cq.push(cc+1);

                        int nt;
                        if(ny%2 == 0) nt = n*ny + nx/2+1 - ny/2; // 홀수
                        else nt = n*ny + (nx+1)/2 - ny/2; // 짝수
                        path[ nt ] = ct;
                    }
                }
            }
        }
        //right
        for(int i = 0 ; i < 3 ; i++){
            int ny = ry + dy[i];
            int nx = rx + dx[i];

            if( (ny%2 == 0 && ny >= 0 && ny < n && nx >= 0 && nx < 2*n) || (ny%2 == 1 && ny >= 0 && ny < n && nx >= 1 && nx < 2*n-1) ){
                if(!visit[ny][nx]){
                    if(map[ny][nx] == rn){
                        visit[ny][nx] = true;
                        visit[ny][nx+1] = true;
                        q.push(make_pair(make_pair(ny,nx),make_pair(ny,nx+1)));
                        cq.push(cc+1);

                        int nt;
                        if(ny%2 == 0) nt = n*ny + nx/2+1 - ny/2; // 홀수
                        else nt = n*ny + (nx+1)/2 - ny/2; // 짝수
                        path[ nt ] = ct;
                    }
                }
            }            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int a;
        if(i%2 == 0){
            for(int j = 0 ; j < n*2 ; j++){
                cin >> a;
                map[i][j] = a;
            }
        }
        else{
            map[i][0] = 0;
            for(int j = 0 ; j < (n-1)*2 ; j++){
                cin >> a;
                map[i][j+1] = a;
            }
            map[i][n*2-1] = 0;
        }
    }

    bfs();
    // print();

    vector<int> ans;
    int temp = maxtile;
    ans.push_back(temp);

    while(path[temp] != 0){
        temp = path[temp];
        ans.push_back(temp);
    }

    cout << ans.size() << '\n';
    for(int i = ans.size()-1 ; i >= 0 ; i--) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}