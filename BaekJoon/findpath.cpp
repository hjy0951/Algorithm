// 백준 11403 경로 찾기
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n;
vector<int> v[101];
int mat[101][101];

int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            int ox;
            cin >> ox;
            if(ox == 1){
                v[i].push_back(j);
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        int visit[101] = {0, };
        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int j = 0 ; j < v[cur].size() ; j++){
                int next = v[cur][j];

                if(visit[next] == 0){
                    q.push(next);
                    mat[i][next] = 1;
                    visit[next] = 1;
                }
            }
        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}