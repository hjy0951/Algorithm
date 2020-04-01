// SWEA 1808 지희의 고장난 계산기
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<int> button;
vector<int> ps;
vector<int> pos;
int num[1000001];
int x;
int digit;
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