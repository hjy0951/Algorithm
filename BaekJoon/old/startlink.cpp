// 백준 5014 스타트링크
#include <iostream>
#include <queue>

using namespace std;

int f,s,g,u,d; // 맨 위층 | 시작 위치 | 목표 위치 | 위로 u칸 | 밑으로 d칸
int visit[1000001];

void print(){
    cout << endl;
    for(int i = 1 ; i <= f ; i++){
        cout << visit[i] << " ";
    }
    cout << endl;
}

void find(){
    queue<int> q;
    q.push(s);
    visit[s] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        int up_stair = cur + u;
        if(up_stair >= 1 && up_stair <= f && visit[up_stair] == 0){
            q.push(up_stair);
            visit[up_stair] = visit[cur] + 1;
            if(up_stair == g) return;
        }
        int down_stair = cur - d;
        if(down_stair >= 1 && down_stair <= f && visit[down_stair] == 0){
            q.push(down_stair);
            visit[down_stair] = visit[cur] + 1;
            if(down_stair == g) return;
        }
    }

}

int main(){
    cin >> f >> s >> g >> u >> d;
    find();
    // print();
    if(visit[g] != 0) cout << visit[g]-1 << "\n";
    else cout << "use the stairs\n";
    return 0;
}