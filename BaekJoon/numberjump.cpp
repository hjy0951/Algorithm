// 백준 2210 숫자판 점프
/*
    5×5 크기의 숫자판이 있다. 각각의 칸에는 숫자(digit, 0부터 9까지)가 적혀 있다.
    이 숫자판의 임의의 위치에서 시작해서, 인접해 있는 네 방향으로 다섯 번 이동하면서, 각 칸에 적혀있는 숫자를 차례로 붙이면 6자리의 수가 된다. 
    이동을 할 때에는 한 번 거쳤던 칸을 다시 거쳐도 되며, 0으로 시작하는 000123과 같은 수로 만들 수 있다.
    숫자판이 주어졌을 때, 만들 수 있는 서로 다른 여섯 자리의 수들의 개수를 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <string>

using namespace std;

bool ox[1000000];
int map[5][5];
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
int res;

void bt(string num, int cnt, int y, int x){
    if(cnt >= 6){
        int temp = stoi(num);
        if(ox[temp] == false){
            ox[temp] = true;
            res++;
        }
        return;
    }
    else{
        num.push_back(map[y][x] + '0');

        for(int i = 0 ; i < 4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= 0 && ny < 5 && nx >= 0 && nx < 5){
                bt(num, cnt+1, ny, nx);
            }
        }

        num.pop_back();
    }
}
int main(){
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            string str = "";
            bt(str,0,i,j);
        }
    }

    cout << res << '\n';
    return 0;
}