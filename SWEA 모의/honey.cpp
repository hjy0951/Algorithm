#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 일꾼은 두명.
int N,M,C; // N : 벌통 크기 N X N | M : 선택할 수 있는 벌통의 개수 | C : 채취할 수 있는 꿀의 최대 양
int map[15][15];
int visit[15][15];
int worker[2][10];
int maxhoney;
int temptotal;

void combi(int worknum, int check[10], int cur, int sum){
    if(sum > C || cur >= M){
        if(sum > C) check[cur-1] = 0;

        int total = 0;
        for(int i = 0 ; i < M ; i++){
            if(check[i] == 1){
                total += worker[worknum][i]*worker[worknum][i];
            }
        }
        if(total == 0) return;

        // cout << endl;
        // cout << "honey : ";
        // for(int i = 0 ; i < M ; i++){
        //     if(check[i] == 1) cout << worker[worknum][i] << " ";
        // }
        // cout << endl;
        // cout << "total : " << total << endl;
        
        if(total > temptotal) temptotal = total;
        return;
    }
    else{
        check[cur] = 1;
        //if(sum+ worker[workernum][cur] <= C) 
        combi(worknum, check, cur+1, sum + worker[worknum][cur]);
        check[cur] = 0;
        combi(worknum, check, cur+1, sum);

        // for(int i = 0 ; i < M ; i++){
        //     if(check[i] == 1) continue;
        //     check[cur] = 1;
        //     // combi(worknum, i, sum + worker[worknum][cur]);
        //     check[cur] = 0;
        //     combi(worknum, i, sum);
        // }
    }
    return;
}

void honey(int cy, int cx, int work){
    if(work == 1){
        for(int i = 0 ; i < M ; i++){
            worker[1][i] = map[cy][cx-i];
        }

        // sort(worker[0],worker[0]+M);
        // sort(worker[1],worker[1]+M);

        // cout << endl;
        // for(int i = 0 ; i < 2 ; i++){
        //     cout << "worker" << i << ": ";
        //     for(int j = M-1 ; j >= 0 ; j--){
        //         cout << worker[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        int total_honey = 0;

        for(int i = 0 ; i < 2 ; i++){
            // int maxtemp = 0;
            int check[10];

            for(int j = 0 ; j < M ; j++){
                memset(check,0,sizeof(check));
                combi(i, check, j, 0);
            }
            // cout << i+1 << " temptotal : " << temptotal <<endl;
            total_honey += temptotal;
            temptotal = 0;
            // for(int j = M-1 ; j >= 0 ; j--){
            //     int temp = 0;
            //     int tempcheck[10];
            //     memset(tempcheck,0,sizeof(tempcheck));

            //     for(int k = j ; k >= 0 ; k--){
            //         temp += worker[i][k];
            //         tempcheck[k] = 1;
            //         if(temp > C){
            //             temp -= worker[i][k];
            //             tempcheck[k] = 0;
            //         }
            //     }
            //     if(maxtemp < temp){
            //         maxtemp = temp;
            //         for(int k = 0 ; k < M ; k++){
            //             check[k] = tempcheck[k];
            //         }
            //     }
            // }

            // for(int j = 0 ; j < M ; j++){
            //     if(check[j] == 1){
            //         total_honey += worker[i][j] * worker[i][j];
            //     }
            // }
        }
        // cout << "total_honey : " << total_honey << endl << endl;

        if(maxhoney < total_honey) maxhoney = total_honey;
        return;
    }
    else if(work == 0){
        for(int i = 0 ; i < M ; i++){
            worker[0][i] = map[cy][cx-i];
        }

        for(int i = cy ; i < N ; i++){
            if(i == cy){
                for(int j = 0 ; j < N ; j++){
                    if(j - M+1 > cx){
                        if(visit[i][j] == 0){
                            honey(i, j, 1);
                        }
                    }
                    
                }
            }
            else{
                for(int j = M-1 ; j < N ; j++){
                    if(j >= M-1 && j < N){
                        if(visit[i][j] == 0){
                            honey(i, j, 1);
                        }
                    }
                    
                }
            }
        }
    }
}

int main(int argc, char** argv){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        memset(map,0,sizeof(map));
        memset(visit,0,sizeof(visit));
        memset(worker,0,sizeof(worker));
        maxhoney = 0;
        temptotal = 0;

        cin >> N >> M >> C;

        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                cin >> map[j][k];
            }
        }

        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < M-1 ; k++){
                visit[j][k] = 1;
            }
        }

        // cout << endl;
        // for(int j = 0 ; j < N ; j++){
        //     for(int k = 0 ; k < N ; k++){
        //         cout << visit[j][k] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                if(visit[j][k] == 0){
                    visit[j][k] = 1;
                    honey(j, k, 0);

                    // cout << endl;
                    // for(int j = 0 ; j < N ; j++){
                    //     for(int k = 0 ; k < N ; k++){
                    //         cout << visit[j][k] << " ";
                    //     }
                    //     cout << endl;
                    // }
                    // cout << endl;
                }
            }
        }

        cout << "#" << i << " " << maxhoney << endl;
    }
    return 0;
}

/*
#1 174
#2 131
#3 145
#4 155
#5 166
#6 239
#7 166
#8 172
#9 291
#10 464
*/

/*
1
4 2 13
6 1 9 7
9 8 5 8
3 4 5 3
8 2 6 7

1
4 3 12
8 8 6 5
5 2 7 4
8 5 1 7
7 8 9 4

1
5 5 10
1 3 5 7 9
1 3 5 7 9
1 3 5 7 9
1 3 5 7 9
1 3 5 7 9
*/