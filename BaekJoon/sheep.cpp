// 백준 3184 양
/*
    미키의 뒷마당에는 특정 수의 양이 있다. 
    배고픈 늑대는 마당에 들어와 양을 공격했다.
    마당은 행과 열로 이루어진 직사각형 모양이다. 
    글자 '.' (점)은 빈 필드를 의미하며, 글자 '#'는 울타리를, 'o'는 양, 'v'는 늑대를 의미한다.
    한 칸에서 수평, 수직만으로 이동하며 울타리를 지나지 않고 다른 칸으로 이동할 수 있다면, 두 칸은 같은 영역 안에 속해 있다고 한다.
    마당에서 "탈출"할 수 있는 칸은 어떤 영역에도 속하지 않는다고 간주한다.
    다행히 우리의 양은 늑대에게 싸움을 걸 수 있고 영역 안의 양의 수가 늑대의 수보다 많다면 이기게 된다. 
    그렇지 않다면 늑대가 그 지역 안의 모든 양을 먹는다.
    맨 처음 모든 양과 늑대는 마당 안 영역에 존재한다.
    아침이 도달했을 때 살아남은 양과 늑대의 수를 출력하는 프로그램을 작성하라.
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct Animal{
    int type;
    int y;
    int x;
    bool live;
};

int r,c;
char map[251][251];
bool visit[251][251];
int ani[251][251];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
Animal a[60000];
int cnt;

void print(){
    cout << '\n';
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs(int y, int x){
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    visit[y][x] = true;

    vector<int> sv;
    vector<int> wv;
    
    if(ani[y][x] > 0){
        int cur = ani[y][x];
        if(a[cur].live == true){
            if(a[cur].type == 1) sv.push_back(cur);
            else if(a[cur].type == 2) wv.push_back(cur);
        }
    }

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < r && nx >= 0 && nx < c){
                if(visit[ny][nx] == false && map[ny][nx] == '.'){
                    visit[ny][nx] = true;
                    q.push(make_pair(ny,nx));

                    if(ani[ny][nx] > 0){
                        int cur = ani[ny][nx];

                        if(a[cur].live == 1){
                            if(a[cur].type == 1){
                                sv.push_back(cur);
                            }
                            else if(a[cur].type == 2){
                                wv.push_back(cur);
                            }
                        }
                    }
                }
            }
        }
    }

    if(sv.size() == 0 || wv.size() == 0) return;

    // 양의 수가 늑대의 수보다 많다면 이기게 된다.
    if(sv.size() > wv.size()){
        for(int i = 0 ; i < (int)wv.size() ; i++){
            int cur = wv[i];
            a[cur].live = false;
        }
    }
    // 그렇지 않다면 늑대가 그 지역 안의 모든 양을 먹는다.
    else{
        for(int i = 0 ; i < (int)sv.size() ; i++){
            int cur = sv[i];
            a[cur].live = false;
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i = 0 ; i < r ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < c ; j++){
            map[i][j] = str[j];

            if(map[i][j] == 'o'){ // 양
                ani[i][j] = ++cnt;
                map[i][j] = '.';

                a[cnt].live = true;
                a[cnt].y = i;
                a[cnt].x = j;
                a[cnt].type = 1;
            }
            else if(map[i][j] == 'v'){ // 늑대
                ani[i][j] = ++cnt;
                map[i][j] = '.';

                a[cnt].live = true;
                a[cnt].y = i;
                a[cnt].x = j;
                a[cnt].type = 2;
            }
        }
    }

    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            if(visit[i][j] == false && map[i][j] == '.'){
                bfs(i,j);
            }
        }
    }

    int sheep = 0;
    int wolf = 0;
    for(int i = 1 ; i <= cnt ; i++){
        if(a[i].live == true){
            if(a[i].type == 1) sheep++;
            else if(a[i].type == 2) wolf++;
        }
    }

    cout << sheep << ' ' << wolf << '\n';
    return 0;
}