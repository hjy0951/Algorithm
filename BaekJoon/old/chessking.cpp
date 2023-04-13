// 백준 1063 킹
/*
    열은 가장 왼쪽 열이 A이고, 가장 오른쪽 열이 H까지 이고, 행은 가장 아래가 1이고 가장 위가 8이다. 
    예를 들어, 왼쪽 아래 코너는 A1이고, 그 오른쪽 칸은 B1
    체스판에는 돌이 하나 있는데, 돌이 있는 곳으로 이동할 때는, 돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동시킨다. 
    입력으로 킹이 어떻게 움직여야 하는지 주어진다. 
    입력으로 주어진 대로 움직여서 킹이나 돌이 체스판 밖으로 나갈 경우에는 그 이동은 건너 뛰고 다음 이동을 한다.
    킹과 돌의 마지막 위치를 구하는 프로그램을 작성하시오.

    ***** string의 compare는 같은 경우에 0....
*/
#include <iostream>
#include <string>

using namespace std;

int ky,kx;
int sy,sx;
int dy[] = {0, 0,-1, 1,-1,-1, 1, 1};
int dx[] = {1,-1, 0, 0, 1,-1, 1,-1};
//          R, L, B, T,RB,LB,RT,LT
int n;

void print(){
    cout << '\n';
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(i == ky && j == kx) cout << "K ";
            else if(i == sy && j == sx) cout << "S ";
            else cout << "0 ";
        }
        cout <<'\n';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0 ; i < 2 ; i++){
        string str;
        cin >> str;

        if(i == 0){
            ky = str[1] - '1';
            kx = str[0] - 'A';
        }
        else{
            sy = str[1] - '1';
            sx = str[0] - 'A';
        }
    }

    cin >> n;

    while(n--){
        string mv;
        cin >> mv;

        int dir;
        if(!mv.compare("R")) dir = 0;
        else if(!mv.compare("L")) dir = 1;
        else if(!mv.compare("B")) dir = 2;
        else if(!mv.compare("T")) dir = 3;
        else if(!mv.compare("RB")) dir = 4;
        else if(!mv.compare("LB")) dir = 5;
        else if(!mv.compare("RT")) dir = 6;
        else if(!mv.compare("LT")) dir = 7;

        int ny = ky + dy[dir];
        int nx = kx + dx[dir];

        if(ny >= 0 && ny < 8 && nx >= 0 && nx < 8){
            // 돌이 있는 위치
            if(ny == sy && nx == sx){
                int nsy = sy + dy[dir];
                int nsx = sx + dx[dir];

                if(nsy >= 0 && nsy < 8 && nsx >= 0 && nsx < 8){
                    sy = nsy;
                    sx = nsx;

                    ky = ny;
                    kx = nx;
                }
            }
            else{
                ky = ny;
                kx = nx;
            }
        }
    }

    for(int i = 0 ; i < 2 ; i++){
        string str;

        if(i == 0){
            str += kx + 'A';
            str += '1' + ky;
        }
        else{
            str += sx + 'A';
            str += '1' + sy;
        }

        cout << str << '\n';
    }

    return 0;
}

/*
B2 A1 1
L
*/