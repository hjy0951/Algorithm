// 백준 1194 달이 차오른다, 가자.
/*
    빈 곳 : 언제나 이동할 수 있다. ('.‘로 표시됨)
    벽 : 절대 이동할 수 없다. (‘#’)
    열쇠 : 언제나 이동할 수 있다. 이 곳에 처음 들어가면 열쇠를 집는다. (a - f)
    문 : 대응하는 열쇠가 있을 때만 이동할 수 있다. (A - F : ABCDEF)
    민식이의 현재 위치 : 빈 곳이고, 민식이가 현재 서 있는 곳이다. (숫자 0)
    출구 : 달이 차오르기 때문에, 민식이가 가야하는 곳이다. 이 곳에 오면 미로를 탈출한다. (숫자 1)

    => 비트마스크를 사용하면 편하겠다고 생각은 했지만, 방문 표시 배열을 3차원으로 하여 이용할 줄은 꿈에도 몰랐다..
       좋은 문제 같지만 정말 생각하기 어려울 것 같다.
       '열쇠' 문제와는 조금 다르지만 BFS 최고 문제 같다.
*/
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n,m;
char map[51][51];
bool visit[51][51][257];
queue<pair<int,int> > q;
queue<int> key;
queue<int> cnt;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int mindist;

void bfs(){
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        int ck = key.front();
        int cc = cnt.front();
        q.pop();
        key.pop();
        cnt.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(!visit[ny][nx][ck]){
                    if(map[ny][nx] == '.'){
                        visit[ny][nx][ck] = true;
                        q.push(make_pair(ny,nx));
                        key.push(ck);
                        cnt.push(cc+1);
                    }
                    else if(map[ny][nx] >= 'a' && map[ny][nx] <= 'z'){
                        int temp = 1 << (map[ny][nx] - 'a');
                        int nk = ck | temp;
                        visit[ny][nx][nk] = true;
                        q.push(make_pair(ny,nx));
                        key.push(nk);
                        cnt.push(cc+1);
                    }
                    else if(map[ny][nx] >= 'A' && map[ny][nx] <= 'Z'){
                        int temp = 1 << (map[ny][nx] - 'A');

                        if((ck & temp) == temp){
                            visit[ny][nx][ck] = true;
                            q.push(make_pair(ny,nx));
                            key.push(ck);
                            cnt.push(cc+1);
                        }
                    }
                    else if(map[ny][nx] == '1'){
                        mindist = min(mindist, cc+1);
                        return;
                    }
                }
            }
        }
    }
}

int main(){
    mindist = 987987987;

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;

        for(int j = 0 ; j < m ; j++){
            map[i][j] = str[j];

            if(str[j] == '0'){
                q.push(make_pair(i,j));
                key.push(0);
                cnt.push(1);
                map[i][j] = '.';
                visit[i][j][0] = true;
            }
        }
    }

    bfs();

    if(mindist != 987987987) cout << mindist-1 << '\n';
    else cout << "-1\n";
    return 0;
}