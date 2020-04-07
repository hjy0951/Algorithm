// SWEA 7988 내전 경기
/*
    1.
    해쉬맵을 사용하면 편하게 풀 수 있을 것 같다.
    c++ 에서 hash_map 대신 unordered_map, map 권장.
    map 대신 unordered_map을 사용하였다.
    사용법은 같고 다만 생성과정에서 정렬을 하지 않기 때문에 메모리 상에 절약을 한다고 한다.
    unordered_map 사용법
        .end() 메소드는 자료의 마지막값의 다음값인 빈iterator의 메모리를 반환한다.
        .find() 메소드 역시 iterator를 반환하는데 이 때 찾지 못할 경우 역시 빈 iterator를 반환한다.
        make_pair를 이용하여 pair로 insert
    이후 유니온 파인드 사용
    
    2.
    로직이 잘못된 것 같아 유니온파인드 -> BFS -> 시간초과
    3.
    unordered_mapa -> map
    4.
    BFS -> 재귀로 이분그래프

*/
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int k;
int visit[201];
int cnt;
vector<int> v[201];
map<string,int> m;
int ox;

void rec(int cur, int color){
    visit[cur] = color;
    for(int i = 0 ; i < v[cur].size() ; i++){
        int next = v[cur][i];

        if(visit[next] == 0){
            if(color == 1) rec(next, 2);
            else if(color == 2) rec(next, 1);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    for(int t = 1 ; t <= tc ; t++){
        cin >> k;

        for(int i = 0 ; i < k ; i++){
            string s1, s2;
            cin >> s1 >> s2;

            if(m.count(s1) == 0) m[s1] = ++cnt;
            if(m.count(s2) == 0) m[s2] = ++cnt;

            v[m[s1]].push_back(m[s2]);
            v[m[s2]].push_back(m[s1]); // 해싱 후 그래프 만들기.
        }

        ox = 1;
        // DFS
        for(int i = 1 ; i <= cnt ; i++){
            if(visit[i] == 0) rec(i,1);
        }

        for(int i = 1 ; i <= cnt ; i++){
            if(ox == 0) break;
            int cur = i;

            for(int j = 0 ; j < v[cur].size() ; j++){
                int next = v[cur][j];
                if(visit[next] == visit[cur]){
                    ox = 0;
                    break;
                }
            }
        }
        // BFS
        // queue<int> q;
        // q.push(1);
        // visit[1] = 1;
        // while(!q.empty()){
        //     if(ox == 0) break;
        //     int cur = q.front();
        //     q.pop();

        //     for(int i = 0 ; i < v[cur].size() ; i++){
        //         int next = v[cur][i];
        //         if(visit[next] == 0){
        //             if(cur == 1) visit[next] = 2;
        //             else if(cur == 2) visit[next] = 1;
        //             q.push(next);
        //         }
        //         else{
        //             if(visit[cur] == visit[next]){
        //                 ox = 0;
        //                 break;
        //             }
        //         }
        //     }
        // }

        if(ox == 1){
            for(int i = 1 ; i <= cnt ; i++){
                if(visit[i] == 0){
                    ox = 0;
                    break;
                }
            }
        }

        cout << "#" << t << " ";
        if(ox == 1) cout << "YES\n";
        else cout << "NO\n";

        m.clear();
        for(int i = 1 ; i <= cnt ; i++) v[i].clear();
        cnt = 0;
        ox = 1;
        memset(visit,0,sizeof(visit));
    }
    return 0;
}
/*
3
2
Alex Tom
Paul Alex
4
A B
B C
C D
D A
3
z d
d u_i
z u_i
*/