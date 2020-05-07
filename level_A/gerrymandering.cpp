// 백준 17471 게리멘더링
/*
    선거에서는 최대한 공평하게 선거구를 획정하려고 한다.
    백준시는 N개의 구역으로 나누어져 있고, 구역은 1번부터 N번까지 번호가 매겨져 있다. 
    구역을 두 개의 선거구로 나눠야 하고, 각 구역은 두 선거구 중 하나에 포함되어야 한다. 
    선거구는 구역을 적어도 하나 포함해야 하고, 한 선거구에 포함되어 있는 구역은 모두 연결되어 있어야 한다.
    구역 A에서 인접한 구역을 통해서 구역 B로 갈 수 있을 때, 두 구역은 연결되어 있다고 한다.
    중간에 통하는 인접한 구역은 0개 이상이어야 하고, 모두 같은 선거구에 포함된 구역이어야 한다.
    공평하게 선거구를 나누기 위해 두 선거구에 포함된 인구의 차이를 최소로 하려고 한다.
    백준시의 정보가 주어졌을 때, 인구 차이의 최솟값
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n;
int mingap;
int cnt;
vector<int> v[11];
int p[11];
int visit[11];
int total;

void print(){
    cout << "\n";
    for(int i = 1 ; i <= n ; i++) cout << visit[i] << " ";
    cout << "\n";
}

bool check(){
    for(int i = 1 ; i <= n ; i++){
        if(visit[i] == 0) return false;
    }
    return true;
}

void group(int s){
    queue<int> q;
    q.push(s);
    visit[s] = cnt;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0 ; i < v[cur].size() ; i++){
            int next = v[cur][i];

            if(visit[next] == 0){
                q.push(next);
                visit[next] = cnt;
            }
        }
    }
}

bool ox(){
    queue<int> q;
    int temp[11] = {0,};
    q.push(1);
    int col = visit[1];
    temp[1] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0 ; i < v[cur].size() ; i++){
            int next = v[cur][i];

            if(visit[next] == col && temp[next] == 0){
                q.push(next);
                temp[next] = 1;
            }
        }
    }

    int s;
    for(int i = 2 ; i <= n ; i++){
        if(visit[i] != col){
            s = i;
            break;
        }
    }
    q.push(s);
    col = visit[s];
    temp[s] = 2;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0 ; i < v[cur].size() ; i++){
            int next = v[cur][i];

            if(visit[next] == col && temp[next] == 0){
                q.push(next);
                temp[next] = 2;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(temp[i] == 0) return false;
    }

    if(visit[1] == 1){
        for(int i = 1 ; i <= n ; i++){
            if(temp[i] != visit[i]) return false;
        }
    }
    else if(visit[1] == 0){
        for(int i = 1 ; i <= n ; i++){
            if(temp[i] == visit[i]) return false;
        }
    }
    return true;
}

// void cal(){
//     int res1 = 0;
//     int res2 = 0;
//     for(int i = 1 ; i <= n ; i++){
//         if(visit[i] == 1) res1 += p[i];
//         else res2 += p[i];
//     }

//     mingap = min(mingap, abs(res1 - res2));
// }

int main(){
    mingap = 987987987;

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> p[i];
        total += p[i];
    }
    for(int i = 1 ; i <= n ; i++){
        int num;
        cin >> num;
        for(int j = 0 ; j < num ; j++){
            int r;
            cin >> r;
            v[i].push_back(r); // 그래프 형성
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(visit[i] == 0){
            cnt++;
            group(i);
        }
    }

    int ans = 0;
    if(cnt > 2) ans = -1;        
    else if(cnt == 2){
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 1 ; i <= n ; i++){
            if(visit[i] == 1) sum1 += p[i];
            else sum2 += p[i];
        }
        ans = abs(sum1 - sum2);
    }
    else{
        vector<int> reg;
        for(int i = 1 ; i <= n ; i++) reg.push_back(i);
        // int len = n/2;
        // if(n % 2 == 1) len++;

        for(int i = 1 ; i < n ; i++){
            vector<int> idx;
            for(int j = 0 ; j < i ; j++) idx.push_back(1);
            for(int j = 0 ; j < n-i ; j++) idx.push_back(0);
            sort(idx.begin(), idx.end());
            
            do{
                memset(visit,0,sizeof(visit));
                int sum = 0;
                for(int j = 0 ; j < idx.size() ; j++){
                    if(idx[j] == 1){
                        visit[reg[j]] = 1;
                        sum += p[reg[j]];
                    }
                }
                if(ox() == true){
                    for(int j = 1 ; j <= n ; j++) cout << visit[j] << " ";
                    cout << "\n";

                    mingap = min(mingap, abs(total - sum - sum));
                }
            }while(next_permutation(idx.begin(), idx.end()));
        }

        ans = mingap;
    }

    cout << ans <<'\n';
    return 0;
}

/*
6
2 3 4 5 6 7
2 2 3
2 1 3
2 1 2
2 5 6
2 4 6
2 4 5

1 - 2   4 - 5
|  /    |  /
 3       6
*/