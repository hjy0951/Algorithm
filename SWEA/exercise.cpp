// SWEA 5684 운동
/*
    도로는 '일방' 통행 도로
    운동을 한 후에는 다시 시작점으로 돌아오는 사이클을 찾기
    도로의 정보가 주어졌을 때, 도로의 길이의 합이 가장 작은 사이클을 찾는 프로그램
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n,m; // 400 / 160000
int check[401];
int cost[401][401];
vector<int> v[401];
int mincost;

// dfs - 시간 오래걸림
void dfs(int s, int cur, int dist){
    if(check[cur] != 0){
        if(cur != s) return;

        mincost = min(mincost, dist);
        return;
    }
    else{
        check[cur] = 1;
        for(int i = 0 ; i < v[cur].size() ; i++){
            int next = v[cur][i];
            // 가지치기 안하면 시간초과남 (현재 최단거리보다 거리가 짧은 경우에만 dfs 진행)
            if(mincost > dist+cost[cur][next]) dfs(s, next, dist+cost[cur][next]);
        }
        check[cur] = 0;
    }
}

int main(){
    int tc;
    cin >> tc;
    for(int t = 1 ; t <= tc ; t++){
        mincost = 987987987;
        cin >> n >> m;

        for(int i = 0 ; i < m ; i++){
            int s,e,c; // s --c--> e : 일방 통행 도로
            cin >> s >> e >> c;

            cost[s][e] = c;
            v[s].push_back(e);
        }

        for(int i = 1 ; i <= n ; i++){
            dfs(i,i,0);
        }

        if(mincost == 987987987) cout << "#" << t << " -1\n";
        else cout << "#" << t << " " << mincost << "\n";
        
        memset(cost,0,sizeof(cost)); // 160000
        memset(check,0,sizeof(check)); // 400
        for(int i = 1 ; i <= n ; i++) v[i].clear();
    }
    return 0;
}
/*
1      
3 4    
1 2 1  
3 2 1  
1 3 5
2 3 2
*/