// 백주 2931 가스관
#include <iostream>
#include <string>

using namespace std;

int n,m;
char map[26][26];
bool visit[26][26];
int sy,sx;
int ey,ex;
int ay,ax;
int dy[] = {0,0,1,-1}; // 우 좌 하 상
int dx[] = {1,-1,0,0};

pair<int,int> p1(pair<int,int> pos, pair<int,int> pipe){ // |
    if(pos.first-1 == pipe.first && pos.second == pipe.second) return make_pair(pos.first-2, pos.second);
    else if(pos.first+1 == pipe.first && pos.second == pipe.second) return make_pair(pos.first+2, pos.second);
    return make_pair(-1,-1);
}
pair<int,int> p2(pair<int,int> pos, pair<int,int> pipe){ // -
    if(pos.first == pipe.first && pos.second-1 == pipe.second) return make_pair(pos.first, pos.second-2);
    else if(pos.first == pipe.first && pos.second+1 == pipe.second) return make_pair(pos.first, pos.second+2);
    return make_pair(-1,-1);
}
pair<int,int> p3(pair<int,int> pos, pair<int,int> pipe){ // +
    if(pos.first-1 == pipe.first && pos.second == pipe.second) return make_pair(pos.first-2, pos.second);
    else if(pos.first+1 == pipe.first && pos.second == pipe.second) return make_pair(pos.first+2, pos.second);
    else if(pos.first == pipe.first && pos.second == pipe.second+1) return make_pair(pos.first, pos.second-2);
    else if(pos.first == pipe.first && pos.second == pipe.second-1) return make_pair(pos.first, pos.second+2);
    return make_pair(-1,-1);
}
pair<int,int> p4(pair<int,int> pos, pair<int,int> pipe){ // ^ ->
    if(pos.first-1 == pipe.first && pos.second == pipe.second) return make_pair(pipe.first, pipe.second+1);
    else if(pos.first == pipe.first && pos.second-1 == pipe.second) return make_pair(pipe.first+1, pipe.second);
    return make_pair(-1,-1);
}
pair<int,int> p5(pair<int,int> pos, pair<int,int> pipe){ // ㄴ
    if(pos.first+1 == pipe.first && pos.second == pipe.second) return make_pair(pipe.first, pipe.second+1);
    else if(pos.first == pipe.first && pos.second-1 == pipe.second) return make_pair(pipe.first-1, pipe.second);
    return make_pair(-1,-1);
}
pair<int,int> p6(pair<int,int> pos, pair<int,int> pipe){ // -> ^
    if(pos.first == pipe.first && pos.second+1 == pipe.second) return make_pair(pipe.first-1, pipe.second);
    else if(pos.first+1 == pipe.first && pos.second == pipe.second) return make_pair(pipe.first, pipe.second-1);
    return make_pair(-1,-1);
}
pair<int,int> p7(pair<int,int> pos, pair<int,int> pipe){ // -> 아래
    if(pos.first == pipe.first && pos.second+1 == pipe.second) return make_pair(pipe.first+1, pipe.second);
    else if(pos.first-1 == pipe.first && pos.second == pipe.second) return make_pair(pipe.first, pipe.second-1);
    return make_pair(-1,-1);
}

pair<int,int> move(int y, int x){
    pair<int,int> s;
    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < n && nx >= 0 && nx < m){ //// 우 좌 하 상
            if(i == 0){
                if(map[ny][nx] == '-' || map[ny][nx] == '+' || map[ny][nx] == '3' || map[ny][nx] == '4'){
                    s = make_pair(ny,nx);
                    break;
                }
            }
            else if(i == 1){
                if(map[ny][nx] == '-' || map[ny][nx] == '+' || map[ny][nx] == '1' || map[ny][nx] == '2'){
                    s = make_pair(ny,nx);
                    break;
                }
            }
            else if(i == 2){
                if(map[ny][nx] == '|' || map[ny][nx] == '+' || map[ny][nx] == '2' || map[ny][nx] == '3'){
                    s = make_pair(ny,nx);
                    break;
                }
            }
            else if(i == 3){
                if(map[ny][nx] == '|' || map[ny][nx] == '+' || map[ny][nx] == '1' || map[ny][nx] == '4'){
                    s = make_pair(ny,nx);
                    break;
                }
            }
        }
    }

    int ty = s.first;
    int tx = s.second;
    while(map[s.first][s.second] != '.'){
        ty = s.first;
        tx = s.second;

        // cout << ty << ' ' << tx << ' ' << '\n';

        if(map[s.first][s.second] == '|'){
            s = p1(make_pair(y,x),s);
            y = ty;
            x = tx;
        }
        else if(map[s.first][s.second] == '-'){
            s = p2(make_pair(y,x),s);
            y = ty;
            x = tx;
        }
        else if(map[s.first][s.second] == '+'){
            s = p3(make_pair(y,x),s);
            y = ty;
            x = tx;
        }
        else if(map[s.first][s.second] == '1'){
            s = p4(make_pair(y,x),s);
            y = ty;
            x = tx;
        }
        else if(map[s.first][s.second] == '2'){
            s = p5(make_pair(y,x),s);
            y = ty;
            x = tx;
        }
        else if(map[s.first][s.second] == '3'){
            s = p6(make_pair(y,x),s);
            y = ty;
            x = tx;
        }
        else if(map[s.first][s.second] == '4'){
            s = p7(make_pair(y,x),s);
            y = ty;
            x = tx;
        }
    }

    ay = s.first;
    ax = s.second;
    return make_pair(ty,tx);
}
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < m ; j++){
            map[i][j] = str[j];
            if(map[i][j] == 'M'){
                sy = i;
                sx = j;
            }
            else if(map[i][j] == 'Z'){
                ey = i;
                ex = j;
            }
        }
    }

    pair<int,int> s1 = move(sy,sx);
    pair<int,int> s2 = move(ey,ex);

    char ans;
    int cnt = 0;
    for(int i = 0 ; i < 4 ; i++){ // 우좌 하상
        int nay = ay + dy[i];
        int nax = ax + dx[i];

        if(nay < 0 || nay >= n || nax < 0 || nax >= m) break;

        if(i == 0){
            if(map[nay][nax] == '-' || map[nay][nax] == '+' || map[nay][nax] == '3' || map[nay][nax] == '4') cnt++;
        }
        else if(i == 1){
            if(map[nay][nax] == '-' || map[nay][nax] == '+' || map[nay][nax] == '1' || map[nay][nax] == '2') cnt++;
        }
        else if(i == 2){
            if(map[nay][nax] == '|' || map[nay][nax] == '+' || map[nay][nax] == '2' || map[nay][nax] == '3') cnt++;
        }
        else if(i == 3){
            if(map[nay][nax] == '|' || map[nay][nax] == '+' || map[nay][nax] == '1' || map[nay][nax] == '4') cnt++;
        }

    }
    if(cnt == 4) ans = '+';
    else{
        if(p1(s1, make_pair(ay,ax)) == s2) ans = '|';
        else if(p2(s1, make_pair(ay,ax)) == s2) ans = '-';
        else if(p4(s1, make_pair(ay,ax)) == s2) ans = '1';
        else if(p5(s1, make_pair(ay,ax)) == s2) ans = '2';
        else if(p6(s1, make_pair(ay,ax)) == s2) ans = '3';
        else if(p7(s1, make_pair(ay,ax)) == s2) ans = '4';
    }

    cout << ay+1 << ' ' << ax+1 << ' ' << ans << '\n';
    return 0;
}