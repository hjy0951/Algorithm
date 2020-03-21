// SWEA 4534 트리 흑백 색칠
/*
    일반적인 DFS가 가능하지만 경우의 수가 엄청나게 많아 시간초과가 날 것.
    DP + DFS로 풀어야 함.
    점화식은 금방 세웠지만, 자식 노드가 여러 개이기 때문에 곱하면서 경우의 수를 따져야 한다는 것을 늦게 깨달음.
*/
#include <iostream>
#include <vector>
#include <cstring>

#define LIM 1000000007
#define ll long long int
using namespace std;

int n;
ll dp[2][100001]; // 0 백 | 1 흑
vector<int> v[100001];

ll solve(int cur, int color, int parent){
    ll& ret = dp[color][cur];
    if(ret != -1) return ret;

    ret = 1;

    for(int i = 0 ; i < v[cur].size() ; i++){
        int next = v[cur][i];
        if(next == parent) continue;

        if(!color) ret *= (solve(next,0,cur) + solve(next,1,cur));
        else ret *= solve(next,0,cur);
        ret = ret % LIM;
    }
    return ret;
}

int main(){
    int t;
    cin >> t;
    for(int x = 1 ; x <= t ; x++){
        memset(dp,-1,sizeof(dp));

        cin >> n;

        for(int i = 0 ; i < n-1 ; i++){
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        ll ans = solve(1,0,0) + solve(1,1,0);
        ans = ans % LIM;

        cout << "#" << x << " " << ans << "\n";

        for(int i = 1 ; i <= n ; i++){
            v[i].clear();
        }
    }

    return 0;
}

/*
2
2
1 2
5
1 3
2 3
3 4
4 5

#1 3
#2 14
*/