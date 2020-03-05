// 백준 1107 리모컨
/*
    리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다.
    +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다.
    채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.
    지금 이동하려고 하는 채널은 N, 어떤 버튼이 고장났는지 주어졌을 때,
    채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램

    = 자리 수에 맞게 버튼을 안눌러도 된다는 점, 주어진 숫자보다 큰 자리 수에서 -를 눌러 내려오는 것이 더 최소값일 수 있다는 점을 놓혀 오래 걸린 문제
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int e; // 목표 채널
int n; // 고장난 버튼 수
int num[10]; // 고장난 버튼
int digit[10];
int check[10];
int cnt;
int minn;

int to_int(int arr[], int c){
    int t = 1;
    int ret = 0;
    for(int i = 0 ; i <= cnt ; i++){
        ret += arr[i] * t;
        t = t * 10;
    }
    return ret;
}

void solve(int c, int click){
    if(c < 0){
        int res = abs(to_int(check,cnt) - e) + click;
        minn = min(minn, res);
        return;
    }
    else{
        for(int i = 0 ; i < 10 ; i++){
            if(num[i] == 1) continue;
            else{
                check[c] = i;
                    solve(c - 1, click+1);
            }
        }
    }
}

int main(){
    cin >> e;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        num[a] = 1; // 고장
    }

    digit[2] = 1;
    
    if(e == 100){
        cout << "0\n";
        return 0;
    }
    else if(e > 100){
        minn = e - 100;
    }
    else{
        minn = 100 - e;
    }

    int clone_e = e;
    while(clone_e >= 0){
        digit[cnt++] = clone_e % 10;
        clone_e = clone_e / 10;

        if(clone_e == 0) break;
    }
    for(int i = 0 ; i <= cnt ; i++){
        memset(check,0,sizeof(check));
        solve(cnt-i, 0);
    }

    cout << minn << "\n";

    return 0;
}
/*
5457
3
6 7 8
*/