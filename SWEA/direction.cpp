// SWEA 8382 방향 전환
/*
    dfs나 bfs같이 생겼지만 규칙을 찾으면 빠르고 쉽게 풀리는 문제
    지그재그로 최대한 간 다음, 남은 길이에서 한칸씩 전진해 나갈 때의 최소값을 구하면 된다.
    0,0 에서 2,4로 이동한다면
        1. 지그재그로 2,2로 먼저 이동 : 4만큼의 거리 ( (가로 세로 가로 세로) 혹은 순서 반대로 )
        2. 2,2 에서 2,4로 이동 시, 2,3으로 가로 이동 후 바로 가로 이동을 할 수 없기 때문에 (세로 가로 세로) 세번의 움직임이 필요하다
            따라서 1+3의 거리 이동이 필요하다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int sy, sx;
int ey, ex;
int mincnt;

int main(){
    int tc;
    cin >> tc;
    for(int t = 1 ; t <= tc ; t++){
        mincnt = 987987987;
        cin >> sy >> sx >> ey >> ex;

        if(sy == ey && sx == ex){
            cout << "#" << t << " 0\n";
            continue;
        }

        int ylen = abs(ey - sy);
        int xlen = abs(ex - sx);
        int dist = 0;
        int temp = abs(ylen - xlen);

        if(xlen == ylen){
            cout << "#" << t << " " << 2*ylen << "\n";
            continue;
        }
        else if(ylen > xlen) dist = 2*xlen;
        else if(ylen < xlen) dist = 2*ylen;
        
        if(temp%2 == 0){
            dist += temp/2 + (temp/2) * 3;
        }
        else dist += (temp/2) * 3 + temp/2 + 1;

        cout << "#" << t << " " << dist << "\n";
    }
    
    return 0;
}