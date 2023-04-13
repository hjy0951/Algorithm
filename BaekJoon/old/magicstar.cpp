// 백준 3967 매직 스타
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

//5 x 9
char map[5][9];
bool ox[30];
vector<pair<int,int> > x;
bool fin;

/*
 012345678
0....x....
1.A.I.D.x.
2..x...x..
3.x.x.x.x.
4....x....
*/

void print(){
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
}

bool check(){
    int ans = 26 + 'A'*4 - 4;

    if(map[0][4] + map[1][3] + map[2][2] + map[3][1] != ans) return false;

    if(map[0][4] + map[1][5] + map[2][6] + map[3][7] != ans) return false;

    if(map[4][4] + map[3][3] + map[2][2] + map[1][1] != ans) return false;

    if(map[4][4] + map[3][5] + map[2][6] + map[1][7] != ans) return false;

    if(map[1][1] + map[1][3] + map[1][5] + map[1][7] != ans) return false;

    if(map[3][1] + map[3][3] + map[3][5] + map[3][7] != ans) return false;

    return true;
}

void bt(int cnt){
    if(x.size() == cnt){
        // print();
        if(check()) fin = true;
        return;
    }
    else{
        for(int i = 0 ; i <= 'L'-'A' ; i++){
            if(ox[i] == true) continue;

            int cy = x[cnt].first;
            int cx = x[cnt].second;

            map[cy][cx] = 'A' + i;
            ox[i] = true;
            bt(cnt+1);
            if(fin) return;
            ox[i] = false;
            map[cy][cx] = 'x';
        }
    }
}

int main(){
    for(int i = 0 ; i < 5 ; i++){
        string str;
        cin >> str;

        for(int j = 0 ; j < 9 ; j++){
            map[i][j] = str[j];
            if(str[j] >= 'A' && str[j] <= 'Z') ox[str[j] - 'A'] = true;
            if(str[j] == 'x') x.push_back(make_pair(i,j));
        }
    }

    bt(0);

    print();
    
    return 0;
}