// SWEA 2814 최장 경로
/*
    N개의 정점과 M개의 간선으로 구성된 가중치가 없는 무방향 그래프에서의 최장 경로의 길이
    경로에는 같은 정점의 번호가 2번 이상 등장할 수 없으며, 경로 상의 인접한 점들 사이에는 반드시 두 정점을 연결하는 간선이 존재해야 함
    경로의 길이는 경로 상에 등장하는 정점의 개수
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int visit[11];
vector<int> v[11];
int maxn;

void find_path(int cur,int cnt){
    for(int i = 0 ; i < v[cur].size() ; i++){
        int next = v[cur][i];

        if(visit[next] == 1) continue;

        visit[next] = 1;
        find_path(next,cnt+1);
        visit[next] = 0;
    }

    if(maxn < cnt) maxn = cnt;
}

int main(){
    int t;
    cin >> t;

    for(int x = 1 ; x <= t ; x++){
        maxn = 1;

        cin >> n >> m;
        
        for(int i = 0 ; i < m ; i++){
            int a,b;
            cin >> a >> b;

            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        for(int i = 1 ; i <= n ; i++){
            visit[i] = 1;
            find_path(i,1);
            visit[i] = 0;
        }

        cout << "#" << x << " " << maxn << "\n";

        for(int i = 1 ; i <= n ; i++){
            v[i].clear();
        }
    }

    return 0;
}