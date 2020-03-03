// 백준 11724 연결 요소의 개수
#include <iostream>
#include <vector>

using namespace std;

int n,e; // n : 1 ~ 1000
int visit[1001];
vector<int> g[1001];
int cnt;

void find(int cur){
    if(visit[cur] != 0 ) return;

    visit[cur] = cnt;
    for(int i = 0 ; i < g[cur].size() ; i++){
        if(visit[ g[cur][i] ] == 0){
            find(g[cur][i]);
        }
    }
}

int main(){
    cin >> n >> e;

    for(int i = 0 ; i < e ; i++){
        int a,b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i++){
        if(visit[i] == 0){
            cnt++;
            find(i);
        }
    }

    cout <<  cnt << "\n";

    return 0;
}