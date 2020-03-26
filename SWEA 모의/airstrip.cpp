#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int N,X; // 경사로 높이 : 1 | 길이 : X
int map[30][30];

int total;

void horizon(){ // 가로
    int check[30];
    memset(check,0,sizeof(check));
    int prev;

    for(int i = 0 ; i < N ; i++){
        int made[30];
        memset(made,0,sizeof(made));
        int cnt = 1;
        prev = map[i][0];
        int no = 1;

        for(int j = 1 ; j < N ; j++){
            
            int gap = prev - map[i][j];
            if(gap < 0) gap = gap*(-1);

            if(gap == 0) cnt++;
            else if(gap > 1){
                check[i] = 0;
                no = 0;
                break;
            }
            else if(gap == 1){
                if(prev > map[i][j]){
                    cnt = 1;
                    prev = map[i][j];

                    for(int k = 1 ; k < X ; k++){
                        if(prev == map[i][j+k]){
                            cnt++;
                        }
                        else{
                            no = 0;
                            check[i] = 0;
                            break;
                        }
                    }
                    if(no == 0) break;

                    if(cnt < X){
                        no = 0;
                        check[i] = 0;
                        break;
                    }
                    else if(cnt >= X){
                        for(int k = 0 ; k < X ; k++){
                            if(made[j+k] == 0) made[j+k] = 1;
                            else{
                                no = 0;
                                check[i] = 0;
                                break;
                            }
                        }
                        if(no == 0) break;
                        check[i] = 1;
                    }

                    j = j + X - 1;
                    continue;
                }
                else if(prev < map[i][j]){
                    if(cnt >= X){
                        for(int k = 1 ; k <= X ; k++){
                            if(made[j-k] == 0) made[j-k] = 1;
                            else{
                                no = 0;
                                check[i] = 0;
                                break;
                            }
                        }
                        if(no == 0) break;
                        check[i] = 1;
                    }
                    else if(cnt < X){
                        no = 0;
                        check[i] = 0;
                        break;
                    }
                    cnt = 1;
                    prev = map[i][j];
                }
            }
        }
        if(cnt == N-1) check[i] = 1;
        if(no == 0) continue;
        int t = 0;
        int prevprev = -1;
        for(int j = N-1 ; j >= 0 ; j--){
            if(prev == map[i][j]) t++;
            else if(prev != map[i][j]){
                prevprev = map[i][j];
                break;
            }
        }
        if(t >= X && prevprev > prev) check[i] = 1;
        if(t >= X && prevprev == -1) check[i] = 1;
    }

    for(int i = 0 ; i < N ; i++){
        if(check[i] == 1){
            total++;
        }
    }

    // cout << endl;
    // cout << "hori : " << endl;
    // for(int i = 0 ; i < N ; i++){
    //     if(check[i] == 1){
    //         cout << i << " ";
    //     }
    // }
    // cout << endl;
}

void vertical(){ // 세로
    int check[30];
    memset(check,0,sizeof(check));
    int prev;

    // cout << "start vertical : " << endl;
    for(int i = 0 ; i < N ; i++){
        int made[30];
        memset(made,0,sizeof(made));
        int cnt = 1;
        prev = map[0][i];
        int no = 1;

        for(int j = 1 ; j < N ; j++){
            // cout << map[j][i] << " " ;

            int gap = prev - map[j][i];
            if(gap < 0) gap = gap*(-1);

            if(gap == 0) cnt++;
            else if(gap > 1){
                check[i] = 0;
                no = 0;
                break;
            }
            else if(gap == 1){
                if(prev > map[j][i]){
                    cnt = 1;
                    prev = map[j][i];

                    for(int k = 1 ; k < X ; k++){
                        if(prev == map[j+k][i]){
                            cnt++;
                        }
                        else{
                            no = 0;
                            check[i] = 0;
                            break;
                        }
                    } 
                    if(no == 0) break;
                    // cout << "cnt: " << cnt << endl;

                    if(cnt < X){
                        no = 0;
                        check[i] = 0;
                        break;
                    }
                    else if(cnt >= X){
                        for(int k = 0 ; k < X ; k++){
                            if(made[j+k] == 0) made[j+k] = 1;
                            else if(made[j+k] != 0){
                                // cout << endl << "2" << endl;
                                no = 0;
                                check[i] = 0;
                                break;
                            }
                        }
                        if(no == 0) break;
                        check[i] = 1;
                    }
                    
                    j = j + X - 2;

                    // cout << "move j : " << j << endl;
                    continue;
                }
                else if(prev < map[j][i]){
                    if(cnt >= X){
                        for(int k = 1 ; k <= X ; k++){
                            if(made[j-k] == 0) made[j-k] = 1;
                            else if(made[j-k] != 0){
                                no = 0;
                                check[i] = 0;
                                break;
                            }
                        }
                        if(no == 0) break;
                        check[i] = 1;
                    }
                    else if(cnt < X){
                        no = 0;
                        check[i] = 0;
                        break;
                    }
                    cnt = 1;
                    prev = map[j][i];
                }
            }
        }
        // cout << endl;
        // cout << "made"<< endl;;
        // for(int q = 0 ; q < N ; q++){
        //     cout << made[q] << " ";
        // }
        // cout << endl;

        // cout << endl;

        // if(cnt == N-1) check[i] = 1;
        if(no == 0) continue;

        int t = 0;
        int prevprev = -1;
        for(int j = N-1 ; j >= 0 ; j--){
            if(prev == map[j][i]) t++;
            else if(prev != map[j][i]){
                prevprev = map[j][i];
                break;
            }
        }
        if(t >= X && prevprev > prev) check[i] = 1;
        if(t >= X && prevprev == -1) check[i] = 1;
    }

    for(int i = 0 ; i < N ; i++){
        if(check[i] == 1){
            total++;
        }
    }

    // cout << endl;
    // cout << "verti : " << endl;
    // for(int i = 0 ; i < N ; i++){
    //     if(check[i] == 1){
    //         cout << i << " ";
    //     }
    // }
    // cout << endl;
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        memset(map,0,sizeof(map));
        total = 0;
        cin >> N >> X;

        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < N ; k++){
                cin >> map[j][k];
            }
        }

        horizon();
        vertical();


        cout << "#" << i << " " << total << endl;
    }
    return 0;
}
/*
#1 7
#2 4
#3 11
#4 11 //
#5 15
#6 4 //
#7 4 //
#8 1
#9 5
#10 8 //
*/
/*
1
6 2
3 3 3 2 1 1
3 3 3 2 2 1
3 3 3 3 3 2
2 2 3 2 2 2
2 2 3 2 2 2
2 2 2 2 2 2

1
8 3
2 2 2 3 3 4 2 2 
2 2 2 3 3 4 2 2 
2 2 2 2 2 2 2 2 
2 2 2 2 2 2 2 2 
2 2 2 2 1 1 2 2 
2 1 1 1 1 1 1 1 
2 1 1 1 1 1 1 1 
2 1 1 1 1 1 1 1 

1
8 4
1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 
2 1 1 1 1 1 1 1 
2 1 1 1 1 1 1 1 
2 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 2 
1 1 1 1 1 1 1 2

1
9 4
4 4 3 3 3 3 2 2 2 
4 4 3 3 1 1 2 2 3 
3 3 2 2 1 1 1 1 2 
1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 
2 2 1 1 1 1 1 1 1 
2 2 1 1 1 1 1 1 1 
2 2 2 2 2 2 1 1 1 
3 3 3 3 2 2 2 2 1 
*/