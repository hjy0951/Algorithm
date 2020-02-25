// 백준 : 2096 내려가기
#include <iostream>

using namespace std;

int n;
int maxdp[3];
int mindp[3];

int main(){
    cin >> n;
    cin >> maxdp[0] >> maxdp[1] >> maxdp[2];
    mindp[0] = maxdp[0];
    mindp[1] = maxdp[1];
    mindp[2] = maxdp[2];

    for(int i = 1 ; i < n ; i++){
        int temp1[3], temp2[3];
        int res1[3] = {0,}, res2[3] = {0,};

        cin >> temp1[0] >> temp1[1] >> temp1[2];
        temp2[0] = temp1[0];
        temp2[1] = temp1[1];
        temp2[2] = temp1[2];

        // max 
        for(int j = 0 ; j < 2 ; j++){
            int c = maxdp[0] + temp1[j];
            if(res1[j] < c) res1[j] = c;
        }
        // //
        // cout << endl;
        // for(int j = 0 ; j < 3 ; j++){
        //     cout << res1[j] << " ";
        // }
        // cout << endl;

        for(int j = 0 ; j < 3 ; j++){
            int c = maxdp[1] + temp1[j];
            if(res1[j] < c) res1[j] = c;
        }

        for(int j = 1 ; j < 3 ; j++){
            int c = maxdp[2] + temp1[j];
            if(res1[j] < c) res1[j] = c;
        }
        
        for(int j = 0 ; j < 3 ; j++){
            maxdp[j] = res1[j];
        }
        
        // min
        for(int j = 0 ; j < 2 ; j++){
            int c = mindp[0] + temp2[j];
            if(res1[j] > c) res1[j] = c;
        }
        // //
        // cout << endl;
        // for(int j = 0 ; j < 3 ; j++){
        //     cout << res1[j] << " ";
        // }
        // cout << endl;

        for(int j = 0 ; j < 3 ; j++){
            int c = mindp[1] + temp1[j];
            if(res1[j] > c) res1[j] = c;
        }

        for(int j = 1 ; j < 3 ; j++){
            int c = mindp[2] + temp1[j];
            if(res1[j] > c) res1[j] = c;
        }
        
        for(int j = 0 ; j < 3 ; j++){
            mindp[j] = res1[j];
        }
    }

    int maxn = 0;
    for(int i = 0 ; i < 3 ; i++){
        if(maxn < maxdp[i]) maxn = maxdp[i];
    }
    int minn = 987987987;
    for(int i = 0 ; i < 3 ; i++){
        if(minn > mindp[i]) minn = mindp[i];
    }

    cout << maxn << " " << minn  << "\n";
    return 0;
}

/*
3
1 2 3
4 5 6
4 9 0
*/