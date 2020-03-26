#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int D,W,K; // D : 세로 | W : 가로
int film[25][25];
char alp[25][25];
int minn;
int finish = 0;

int check(char arr[][25]){ // 필름의 모든 부분이 검사 가능한지 체크
    // cout << endl;
    // for(int i = 0 ; i < D ; i++){
    //     for(int j = 0 ; j < W ; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // cout << endl;

    for(int i = 0 ; i < W ; i++){
        int temp = arr[0][i];
        int cnt = 1;

        for(int j = 1 ; j < D ; j++){
            if(arr[j][i] == temp){
                cnt++;
                if(cnt >= K) break;
            }
            else{
                cnt = 1;
            }
            temp = arr[j][i];
        }
        if(cnt < K){ // 필름 확인 x
            // cout << "block : " << i << endl;
            return 0;
        }
    }
    return 1; // 필름 확인 가능 
}

void find(int cn, int tn, int cur){
    if(finish != 0) return;

    if(cn >= tn){
        int ox = check(alp);
        if(ox == 1){
            minn = tn;
            finish = 1;
            // cout << endl;
            // for(int i = 0 ; i < D ; i++){
            //     for(int j = 0 ; j < W ; j++){
            //         cout << alp[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            // cout << endl;

            return;
        }
        else return;
    }
    else{
        for(int i = cur ; i < D ; i++){
            char str[25];
            char temp[25];
            memcpy(temp, alp[i], 25*sizeof(char));

            memset(str,'A',sizeof(str));
            memcpy(alp[i], str, 25*sizeof(char));
            find(cn+1, tn, i+1);

            memset(str,'B',sizeof(str));
            memcpy(alp[i], str, 25*sizeof(char));
            find(cn+1, tn, i+1);

            memcpy(alp[i], temp, 25*sizeof(char));
        }
    }
}

int main(){
    int T;
    cin >> T;
    for(int i = 1 ; i <= T ; i++){
        minn = 987987987;
        cin >> D >> W >> K;

        for(int j = 0 ; j < D ; j++){
            for(int k = 0 ; k < W ; k++){
                cin >> film[j][k]; // | 0 = A | 1 = B |
                if(film[j][k] == 0) alp[j][k] = 'A';
                else alp[j][k] = 'B';
            }
        }

        // cout << check(alp) << endl;
        for(int j = 0 ; j < D ; j++){
            find(0,j,0);
            if(minn < 100) break;
        }

        cout << "#" << i << " " << minn << endl;
        finish = 0;
    }

    
    return 0;
}
/*
1
6 8 3
0 0 1 0 1 0 0 1
0 1 0 0 0 1 1 1
0 1 1 1 0 0 0 0
1 1 1 1 0 0 0 1
0 1 1 0 1 0 0 1
1 0 1 0 1 1 0 1
*/
/*
1
6 8 3
0 0 1 0 1 0 0 1
0 1 0 1 0 1 1 1
0 1 1 1 0 0 0 0
1 1 1 1 0 0 0 1
0 1 1 0 1 0 0 1
1 0 1 0 1 1 0 1
*/

/*
#1 2
#2 0
#3 4
#4 2
#5 2
#6 0
#7 3
#8 2
#9 3
#10 4
*/