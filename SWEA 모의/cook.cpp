#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int info[20][20];
int arr[20];
int N;
int dif;
int cnt;

void cook(int cur,int curidx){
    arr[curidx] = cur;
    if(curidx == N/2-1){
        int rest[20];
        int ex[20];
        memset(ex,0,sizeof(ex));

        for(int i = 0 ; i <= curidx ; i++){
            ex[arr[i]] = 1;
        }
        int idx = 0;
        
        // //
        // for(int i = 0 ; i <= N ; i++){
        //     cout << ex[i] << " ";
        // }
        // cout << endl;
        // //

        for(int i = 1 ; i <= N ; i++){
            if(ex[i] == 1) continue;
            rest[idx++] = i;
        }

        // //
        // for(int i = 0 ; i <= curidx ; i++){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        // for(int i = 0 ; i <= curidx ; i++){
        //     cout << rest[i] << " ";
        // }
        // cout << endl;
        // //

        int A = 0;
        int B = 0;
        for(int i = 0 ; i <= curidx ; i++){
            for(int j = i ; j <= curidx ; j++){
                A += info[ arr[i] ][ arr[j] ];
                A += info[ arr[j] ][ arr[i] ];

                B += info[ rest[i] ][ rest[j] ];
                B += info[ rest[j] ][ rest[i] ];
            }
        }
        int temp = A-B;
        if(temp < 0) temp = temp*(-1);
        // cout << "temp : " << temp << endl;
        if(dif > temp) dif = temp;

        return;
    }
    else{
        for(int i = cur+1 ; i <= N ; i++){
            cook(i,curidx+1);
            // arr[curidx+1] = 0;
        }
    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        cin >> N;
        dif = 987987987;
        cnt = 0;
        memset(arr, 0, sizeof(arr));

        for(int j = 1 ; j <= N ; j++){
            for(int k = 1 ; k <= N ; k++){
                cin >> info[j][k];
            }
        }

        cook(1,0);

        cout << '#' << i << " " << dif << endl;
    }
    
    return 0;
}