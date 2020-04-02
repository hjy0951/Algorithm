// SWEA 1808 지희의 고장난 계산기
/*
    고장나지 않은 계산기의 숫자들로 처음에 목표 숫자보다 작은 가능한 모든 조합들을 큐에 넣고 bfs를 실행하였다.
    그리고 이 조합들을 따로 벡터에 저장하여 bfs를 통해 탐색할 때 이용하였다.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<int> button; // 고장나지 않은 버튼
vector<int> ps; // 버튼으로 조합을 만들기 위해 사용
vector<int> pos; // 고장나지 않은 버튼으로 가능한 목표 숫자보다 작은 조합들.
int num[1000001]; // 방문했던 숫자인지 판별하기 위함.
int x;
int digit; // 목표 숫자의 자리 수
queue<int> q;

void rec(int cnt){
    if(cnt > digit){
        return;
    }
    else{
        int temp = 0;
        int std = 1;
        for(int i = 0 ; i < cnt ; i++){
            temp += std * ps[i];
            std = std*10;
        }

        if(temp > x) return;
        // cout << temp << "\n";

        if((num[temp] == 0 || (num[temp] != 0 && num[temp] > cnt)) && (temp!= 0 && x%temp == 0)){
            q.push(temp);
            num[temp] = cnt;
            pos.push_back(temp);
            // cout << temp << " " << cnt << "\n";
        }

        for(int i = 0 ; i < button.size() ; i++){
            ps.push_back(button[i]);
            rec(cnt+1);
            ps.pop_back();
        }
    }
}

void bfs(){
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0 ; i < pos.size() ; i++){
            int op = pos[i] * cur;

            if(op > x) continue;
            else{
                if(x%op == 0 && (num[op] == 0 || num[op] > 1+num[pos[i]]+num[cur])){
                    num[op] = 1+num[pos[i]]+num[cur];
                    if(op == x) continue;
                    else q.push(op);
                }
            }
        }
    }
}

int main(){
    int tc;
    cin >> tc;
    for(int t = 1 ; t <= tc ; t++){
        for(int i = 0 ; i < 10 ; i++){
            int ox;
            cin >> ox;
            if(ox == 1) button.push_back(i);
        }
        cin >> x;
        int cx = x;

        while(cx > 0){
            digit++;
            cx = cx/10;
        }

        for(int i = 0 ; i < button.size() ; i++){
            ps.push_back(button[i]);
            rec(1);
            ps.pop_back();
        }

        // if(num[x] == 0) 
        bfs();

        if(num[x] != 0) cout << '#' << t << " " << num[x]+1 << "\n";
        else cout << '#' << t << " -1\n";

        digit = 0;
        button.clear();
        pos.clear();
        ps.clear();
        memset(num,0,sizeof(num));
    }
    return 0;
}
/*
3
0 1 1 0 0 1 0 0 0 0
60
1 1 1 1 1 1 1 1 1 1
128
0 1 0 1 0 1 0 1 0 1
128
 
*/