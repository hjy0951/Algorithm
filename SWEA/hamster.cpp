// SWEA 8275 햄스터
/*
    처음에 하드코딩, dfs, 백트래킹으로 생각했지만 주어진 input의 크기가 작아서 완전탐색으로 풀이가능한 문제.
    모든 햄스터의 총합이 가장 큰쪽으로, 그리고 사전 순으로 출력으로 해야해서 고민을 많이 했지만,
    모든 우리의 햄스터들을 각각 0~X 까지 순차적으로 넣어보면서 탐색하면 자동으로 그렇게 된다는 점을 빨리 파악하지 못함
*/
#include <iostream>
#include <cstring>

using namespace std;

int n,x,m;
int ham[10];
int visit[10];
int ans[10];
int cond[10][3];
int maxsum;

void fc(int cur, int sum){
    if(cur > n){
        if(maxsum < sum){
            for(int i = 0 ; i < m ; i++){
                int l = cond[i][0];
                int s = cond[i][1];
                int r = cond[i][2];
                int subsum = 0;
                for(int j = l ; j <= s ; j++){
                    subsum += ham[j];
                }
                if(subsum != r) return;
            }

            maxsum = sum;
            for(int i = 1 ; i <= n ; i++){
                ans[i] = ham[i];
            }
        }
        return;
    }
    else{
        if(visit[cur] == 0){
            fc(cur+1,sum+x);
        }
        else{
            for(int i = 0 ; i <= x ; i++){
                ham[cur] = i;
                fc(cur+1,sum+i);
            }
        }
    }
}

int main(){
    int tc;
    cin >> tc;
    for(int t = 1 ; t <= tc ; t++){
        cin >> n >> x >> m;

        for(int i = 0 ; i < m ; i++){
            // a~b 우리 까지 다 더했을때 c 마리
            cin >> cond[i][0] >> cond[i][1] >> cond[i][2];
            for(int j = cond[i][0] ; j <= cond[i][1] ; j++){
                if(visit[j] == 0){
                    ham[j] = 0;
                    visit[j] = 1;
                }
            }
        }
        for(int i = 1 ; i <= n ; i++) if(visit[i] == 0) ham[i] = x;

        fc(1,0);

        if(maxsum == -1) cout << "#" << t << " -1\n";
        else{
            cout << "#" << t << " ";
            for(int i = 1 ; i <= n ; i++) cout << ans[i] << " ";
            cout <<"\n";
        }

        memset(ham,-1,sizeof(ham));
        memset(ans,0,sizeof(ans));
        maxsum = -1;
    }
    return 0;
}