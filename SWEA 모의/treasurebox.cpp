#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// int check[300000000];
int check[17][17][17];
char num[30];
int hexa[2000];
int K,N;
int idx;

void rotate(){ // 비밀번호 회전
    char temp;
    for(int i = N-1 ; i > 0 ; i--){
        temp = num[i-1];
        num[i-1] = num[i];
        num[i] = temp;
    }
}

void trans(){
    char part[4][10];
    int pi = 0;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < N/4 ; j++){
            part[i][j] = num[(N/4) * i + j];
        }
    }

    for(int i = 0 ; i < 4 ; i++){
        int deci = 0;
        int std = 1;

        for(int j = N/4-1 ; j >= 0 ; j--){
            char cur = part[i][j];
            int htd = 0;

            if(cur >= 'A' && cur <= 'F'){ // 'A' = 65 | '1' = 49
                htd = cur - 55;
                deci += htd * std;
            }
            else{
                htd = cur - 48;
                deci += htd * std;
            }
            std = std * 16;
        }

        hexa[idx++] = deci;
        // if(check[deci] != 1){
        //     check[deci] = 1;
            
        // }
    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        memset(hexa,0, sizeof(hexa));
        // memset(check,0, sizeof(check));
        idx = 0;

        scanf("%d %d", &N, &K);

        for(int j = 0 ; j < N ; j++){
            scanf(" %1c", &num[j]);
        }

        for(int j = 0 ; j < N/4 ; j++){
            trans();
            rotate();
        }

        sort(hexa, hexa + idx);
        int fi = idx;
        for(int j = 0 ; j < idx ; j++){
            int cur = hexa[j];
            for(int k = j+1 ; k < fi ; k++){
                if(cur == hexa[k]){
                    hexa[k] = 0;
                    for(int q = k ; q < fi ; q++){
                        hexa[q] = hexa[q+1];
                    }
                    fi--;
                }
            }
        }

        // for(int j = 0 ; j < fi ; j++){
        //     printf("%d ", hexa[j]);
        // }
        // printf("\n\n");

        cout << "#" << i << " " << hexa[fi - K] << endl;
    }

    return 0;
}
/*
1
12 10
1B3B3B81F75E
*/

/*
#1 503
#2 55541
#3 334454
#4 5667473
#5 182189737
*/

/*
5
12 10
1B3B3B81F75E
16 2
F53586D76286B2D8
20 14
88F611AE414A751A767B
24 16
044D3EBA6A647B2567A91D0E
28 11
8E0B7DD258D4122317E3ADBFEA99
*/