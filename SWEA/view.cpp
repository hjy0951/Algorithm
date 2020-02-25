/*
SWEA S/W 문제해결 1일차 view
    왼쪽과 오른쪽으로 창문을 열었을 때, 양쪽 모두 거리 2 이상의 공간이 확보될 때 조망권이 확보된다
    빌딩들에 대한 정보가 주어질 때, 조망권이 확보된 세대의 수를 반환하는 프로그램

    가로 길이는 항상 1000이하로 주어진다.
    맨 왼쪽 두 칸과 맨 오른쪽 두 칸에는 건물이 지어지지 않는다.
    각 빌딩의 높이는 최대 255이다.
*/

#include <iostream>

using namespace std;

int ans;
int map[1010];
int n;

void find(int cur){
    /*
        1. 양 옆 두칸을 보고 각각 가장 높은 높이를 찾음
        2a. 만약, 둘 중 하나의 높이라도 현재 건물보다 높다면 조망권 X
        2b. 아니라면, 현재 건물의 높이 - 둘 중 더 큰 높이 = 조망권을 가진 세대 수
    */
    int r, l;
    if(map[cur-2] > map[cur-1]){
        l = map[cur-2];
    }
    else{
        l = map[cur-1];
    }

    if(map[cur+2] > map[cur+1]){
        r = map[cur+2];
    }
    else{
        r = map[cur+1];
    }

    if(map[cur] <= l || map[cur] <= r){
        return;
    }
    else{
        if(l > r){
            ans += map[cur] - l;
        }
        else{
            ans += map[cur] - r;
        }
    }
}

int main (){
    for(int i = 1 ; i <= 10 ; i++){ // 총 10개의 케이스가 주어짐
        // init
        ans = 0;

        // input
        cin >> n;
        for(int j = 0 ; j < n ; j++){
            cin >> map[j];
        }

        // algorithm
        for(int j = 2 ; j < n-2 ; j++){
            find(j);
        }

        // output
        cout << "#" << i << " " << ans << endl;
    }
    return 0;
}

/*
#1 691
#2 9092
#3 8998
#4 9597
#5 8757
#6 10008
#7 10194
#8 10188
#9 9940
#10 8684
*/