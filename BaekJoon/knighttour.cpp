// 백준 1331 나이트 투어
#include <iostream>
#include <string>

using namespace std;

int visit[6][6];

void print(){
    cout << '\n';
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 6 ; j++){
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    int cnt = 35;
    int ox = 0;
    string s;
    cin >> s;

    int cy = s[1] - '1';
    int cx = s[0] - 'A';
    int sy = cy;
    int sx = cx;

    visit[cy][cx] = 1;

    for(int i = 0 ; i < cnt ; i++){
        string pos;
        cin >> pos;

        int ny = pos[1] - '1';
        int nx = pos[0] - 'A';

        if(visit[ny][nx] != 0){
            ox = 1;
            break;
        }

        if(abs(ny - cy) == 2 && abs(nx - cx) == 1){
            cy = ny;
            cx = nx;
            visit[cy][cx] = 1;
        }
        else if(abs(ny - cy) == 1 && abs(nx - cx) == 2){
            cy = ny;
            cx = nx;
            visit[cy][cx] = 1;
        }
        else{
            ox = 1;
            break;
        }

        if(i == 34){
            if(abs(sy - cy) == 2 && abs(sx - cx) == 1){

            }
            else if(abs(sy - cy) == 1 && abs(sx - cx) == 2){

            }
            else{
                ox = 1;
            }
        }
    }

    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 6 ; j++){
            if(visit[i][j] == 0){
                ox = 1;
                break;
            }
            if(ox == 1) break;
        }
    }

    if(ox == 1) cout<< "Invalid\n";
    else cout << "Valid\n";
    return 0;
}