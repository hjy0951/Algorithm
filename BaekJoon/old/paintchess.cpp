// 백준 1018 체스판 다시 칠하기
#include <iostream>
#include <string>

using namespace std;

int n,m;
char map[51][51];
string test1[8] = {"WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW"};
string test2[8] = {"BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB"};
int mincnt;

void check(int y, int x){
    int cnt1 = 0;
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(map[y+i][x+j] != test1[i][j]) cnt1++;
        }
    }

    int cnt2 = 0;
    for(int i = 0 ; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(map[y+i][x+j] != test2[i][j]) cnt2++;
        }
    }
    int temp = min(cnt1,cnt2);
    mincnt = min(mincnt, temp);
}

int main(){
    mincnt = 987987987;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        for(int j = 0 ; j < m ; j++) map[i][j] = str[j];
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i+8 <= n && j+8 <= m){
                check(i,j);
            }
        }
    }

    cout << mincnt << '\n';
    return 0;
}