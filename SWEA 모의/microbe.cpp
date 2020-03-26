#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

struct Microbe{
    int n;
    int x;
    int y;
    int num;
    int onum;
    int dir; // 1 상 , 2 하 , 3 좌 , 4 우
    int live;
    int moved;
};

int K,N,M; // M : 시간 | K : 군집 수 | N : NxN map
Microbe mic[1010];
int map[110][110];

void move(){
    for(int i = 0 ; i < M ; i++){

        for(int j = 0 ; j < K ; j++){
            if(mic[j].live == 0) continue;

            int ny, nx;
            switch(mic[j].dir){
                case 1 :
                    ny = mic[j].y-1;
                    nx = mic[j].x;
                    break;
                case 2 :
                    ny = mic[j].y+1;
                    nx = mic[j].x;
                    break;
                case 3 :
                    ny = mic[j].y;
                    nx = mic[j].x-1;
                    break;
                case 4 :
                    ny = mic[j].y;
                    nx = mic[j].x+1;
                    break;
            }

            if(ny > 0 && ny < N-1 && nx > 0 && nx < N-1){
                mic[j].y = ny;
                mic[j].x = nx;
            }
            else if(ny == 0 || ny == N-1 || nx == 0 || nx == N-1){
                mic[j].y = ny;
                mic[j].x = nx;
                mic[j].num = mic[j].num/2;

                if(mic[j].dir == 1) mic[j].dir = 2;
                else if(mic[j].dir == 2) mic[j].dir = 1;
                else if(mic[j].dir == 3) mic[j].dir = 4;
                else if(mic[j].dir == 4) mic[j].dir = 3;
            }
            mic[j].moved = 1;
        }

        memset(map,0,sizeof(map));

        for(int j = 0 ; j < K ; j++){
            if(mic[j].live == 1){
                if(mic[j].moved == 1){
                    int cy = mic[j].y;
                    int cx = mic[j].x;

                    if(map[cy][cx] != 0){
                        if(mic[j].onum < mic[map[cy][cx]-1].onum){
                            mic[j].live = 0;
                            mic[map[cy][cx]-1].num+= mic[j].num;
                        }
                        else{
                            mic[map[cy][cx]-1].live = 0;
                            mic[j].num += mic[map[cy][cx]-1].num;
                            map[cy][cx] = mic[j].n;
                        }
                    }
                    else if(map[cy][cx] == 0){
                        map[cy][cx] = mic[j].n;
                    }
                    mic[j].moved = 0;
                }
            }
        }

        for(int j = 0 ; j < K ; j++){
            if(mic[j].live == 0) continue;
            mic[j].onum = mic[j].num;
        }

        // cout << "after move " ;
        // cout << endl;
        // for(int q = 0 ; q < N ; q++){
        //     for(int z = 0 ; z < N ; z++){
        //         if(map[q][z] == 0) cout << map[q][z] << " ";
        //         else cout << map[q][z] << ':' << mic[map[q][z]-1].num << " ";
        //         // cout << map[q][z] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        memset(map,0,sizeof(map));
        memset(mic,0,sizeof(mic));

        cin >> N >> M >> K;

        for(int j = 0 ; j < K ; j++){
            int a,b,c,d;
            cin >> a >> b >> c >> d;

            mic[j].n = j+1;
            mic[j].y = a;
            mic[j].x = b;
            mic[j].num = c;
            mic[j].onum = c;
            mic[j].dir = d;
            mic[j].live = 1;
            mic[j].moved = 0;

            map[a][b] = j+1;
        }

        move();

        int numOfMic = 0;
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                if(mic[map[j][k]-1].live == 1){
                    numOfMic += mic[map[j][k]-1].num;
                }
            }
        }

        cout << "#" << i << " " << numOfMic << endl;
    }

    return 0;
}

/*
1
7 2 9
1 1 7 1
2 1 7 1
5 1 5 4
3 2 8 4
4 3 14 1
3 4 3 3
1 5 8 2
3 5 100 1
5 5 1 1
*/

/*
1
10 7 15
3 4 227 1
4 7 109 1
3 7 487 2
2 3 627 2
6 1 520 4
7 3 596 4
2 6 525 4
1 5 116 3
7 7 771 4
4 4 520 2
7 5 763 1
5 4 829 3
5 2 578 3
6 8 200 2
3 8 760 4
*/

/*
#1 145
#2 5507
#3 9709
#4 2669
#5 3684
#6 774
#7 4797
#8 8786
#9 1374
#10 5040
*/

/*
1
10 5 28
3 3 796 1
7 2 798 2
2 6 622 1
3 5 179 3
7 8 888 4
5 8 634 3
1 8 646 1
3 7 433 4
6 7 416 1
2 7 651 3
6 4 476 2
5 6 712 4
1 7 869 4
6 1 789 2
8 8 585 3
7 6 426 1
1 5 154 2
1 2 692 1
2 4 549 3
2 1 60 2
4 8 996 4
8 2 437 2
3 6 195 2
1 3 734 4
3 8 355 2
1 1 945 1
2 5 558 2
7 7 144 2
*/