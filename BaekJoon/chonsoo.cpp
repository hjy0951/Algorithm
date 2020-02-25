// 백준 2644 촌수계산
#include <iostream>
#include <cstring>

using namespace std;

int n;
int a,b;
int m;
int p[110]; // 부모 관계 표시

int main(){
    // init
    memset(p,0,sizeof(p));

    // input
    cin >> n;
    cin >> a >> b;
    cin >> m;

    for(int i = 0 ; i < m ; i++){
        int x,y;
        cin >> x >> y;

        p[y] = x; // 부모 관계 표시
    }
    //

    int find = 0;
    int ca = 0;
    int cb = 0;

    for(int i = a ; ; i = p[i]){
        if(i == 0) break;

        cb = 0;
        for(int j = b ; ; j = p[j]){
            if(j == 0) break;
            if(j == i){ // 같은 조상 찾을 시 종료
                find = 1;
                break;
            }
            cb++;
        }

        if(find == 1) break;
        ca++;
    }

    // output
    if(find == 0){
        cout << "-1" << endl;
    }
    else{
        cout << ca + cb << endl; 
    }

    return 0;
}

/*
10
7 6
9
1 2
1 3
1 4
9 1
9 10
3 5
3 6
2 7
2 8

*/