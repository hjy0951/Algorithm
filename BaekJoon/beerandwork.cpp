// 백준 9205 맥주 마시면서 걸어가기
/*
    출발은 상근이네 집에서 하고, 맥주 한 박스를 들고 출발한다. 
    맥주 한 박스에는 맥주가 20개 들어있다. 
    목이 마르면 안되기 때문에 50미터에 한 병씩 마시려고 한다.
    상근이의 집에서 페스티벌이 열리는 곳은 매우 먼 거리이다. 
    따라서, 맥주를 더 구매해야 할 수도 있다. 미리 인터넷으로 조사를 해보니 다행히도 맥주를 파는 편의점이 있다. 
    편의점에 들렸을 때, 빈 병은 버리고 새 맥주 병을 살 수 있다. 
    하지만, 박스에 들어있는 맥주는 20병을 넘을 수 없다.
    편의점, 상근이네 집, 펜타포트 락 페스티벌의 좌표가 주어진다. 
    상근이와 친구들이 행복하게 페스티벌에 도착할 수 있는지 구하는 프로그램을 작성하시오.
    페스티벌에 갈 수 있으면 "happy", 중간에 맥주가 바닥나면 "sad"를 출력
        두 좌표 사이의 거리는 x 좌표의 차이 + y 좌표의 차이 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

int n;
int sy,sx;
vector<pair<int,int> > pos;
int visit[110][110];
int ey,ex;
int beer;
int fin;

int cal(int y1, int x1, int y2, int x2){
    return abs(y1 - y2) + abs(x1 - x2);
}

void bfs(){
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 1 ; i < pos.size() ; i++){
            if(i == cur) continue;
            if(visit[cur][i] != 0) continue;

            int dist = cal(pos[cur].first, pos[cur].second, pos[i].first, pos[i].second);
            if(dist <= beer * 50){
                visit[cur][i] = 1;
                if(i == pos.size()-1){
                    fin = 1;
                    return;
                }
                else{
                    q.push(i);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        pos.clear();
        cin >> n;
        // 상근이네 집 : 0 | 편의점 | pos.size() - 1 :  펜타포트 락 페스티벌 좌표
        for(int i = 0 ; i < n+2 ; i++){
            int ty,tx;
            cin >> ty >> tx;
            pos.push_back(make_pair(ty,tx));
        }

        fin = 0;
        beer = 20;
        memset(visit,0,sizeof(visit));

        bfs();

        if(fin == 1) cout << "happy\n";
        else cout << "sad\n";
    }
    return 0;
}