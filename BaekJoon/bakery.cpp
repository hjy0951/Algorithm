// 백준 3109 빵집
/*
    빵집이 있는 곳은 R*C 격자로 표현할 수 있다. 첫째 열은 근처 빵집의 가스관이고, 마지막 열은 원웅이의 빵집
    빵집과 가스관 사이에는 건물이 있을 수도 있다. 건물이 있는 경우에는 파이프를 놓을 수 없다.
    가스관과 빵집을 연결하는 모든 파이프라인은 첫째 열에서 시작해야 하고, 마지막 열에서 끝나야 한다. 
    각 칸은 오른쪽, 오른쪽 위 대각선, 오른쪽 아래 대각선으로 연결할 수 있고, 각 칸의 중심끼리 연결하는 것이다.
    가스를 되도록 많이 훔치려고 한다. 
    따라서, 가스관과 빵집을 연결하는 파이프라인을 여러 개 설치할 것이다. 
    이 경로는 겹칠 수 없고, 서로 접할 수도 없다. 즉, 각 칸을 지나는 파이프는 하나이어야 한다.

    빵집의 모습이 주어졌을 때, 원웅이가 설치할 수 있는 가스관과 빵집을 연결하는 파이프라인의 최대 개수를 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <string>

using namespace std;

int n,m;
char map[10001][501];
bool visit[10001][501];
// 오른쪽, 오른쪽 대각선 두 방향
int dy[] = {-1,0,1};
int dx[] = {1,1,1};
int cnt;
bool fin;

void bt(int y, int x){
    if(x == m-1){
        cnt++;
        fin = true;
        return;
    }
    else{
        for(int i = 0 ; i < 3 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if(!visit[ny][nx] && map[ny][nx] == '.'){
                visit[ny][nx] = true;
                bt(ny,nx);
                
                if(fin) return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < m ; j++){
            map[i][j] = str[j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        fin = false;
        visit[i][0] = true;
        bt(i,0);
    }
    cout << cnt << '\n';
    return 0;
}