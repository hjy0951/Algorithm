// 백준 17779 게리맨더링2
/*
    구역을 다섯 개의 선거구로 나눠야 하고, 각 구역은 다섯 선거구 중 하나에 포함되어야 한다.
    선거구는 구역을 적어도 하나 포함해야 하고, 한 선거구에 포함되어 있는 구역은 모두 연결되어 있어야 한다.
    구역 A에서 인접한 구역을 통해서 구역 B로 갈 수 있을 때, 두 구역은 연결되어 있다고 한다.
    중간에 통하는 인접한 구역은 0개 이상이어야 하고, 모두 같은 선거구에 포함된 구역이어야 한다.
    선거구를 나누는 방법은 다음과 같다.
        1. 기준점 (x, y)와 경계의 길이 d1, d2를 정한다. (d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N)
        2. 다음 칸은 경계선이다.
            (x, y), (x+1, y-1), ..., (x+d1, y-d1)
            (x, y), (x+1, y+1), ..., (x+d2, y+d2)
            (x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
            (x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
        3. 경계선과 경계선의 안에 포함되어있는 곳은 5번 선거구이다.
        4. 5번 선거구에 포함되지 않은 구역 (r, c)의 선거구 번호는 다음 기준을 따른다.
            1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
            2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
            3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
            4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N

    구역 (r, c)의 인구는 A[r][c]이고, 선거구의 인구는 선거구에 포함된 구역의 인구를 모두 합한 값이다.
    선거구를 나누는 방법 중에서, 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이의 최솟값을 구해보자.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[21][21];
int visit[21][21];
int mingap;
int total;

void print(){
    cout << "\n";
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void solve(int y, int x, int d1, int d2){
    vector<int> p;
    for(int i = 0 ; i <= 5 ; i++) p.push_back(0);
/*
다음 칸은 경계선이다.
    (x, y), (x+1, y-1), ..., (x+d1, y-d1)
    (x, y), (x+1, y+1), ..., (x+d2, y+d2)
    (x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
    (x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
*/
    memset(visit,0,sizeof(visit));
    for(int i = 0 ; i <= d1 ; i++) visit[y+i][x-i] = 5;
    for(int i = 0 ; i <= d2 ; i++) visit[y+i][x+i] = 5;
    for(int i = 0 ; i <= d2 ; i++) visit[y+d1+i][x-d1+i] = 5;
    for(int i = 0 ; i <= d1 ; i++) visit[y+d2+i][x+d2-i] = 5;

    // 1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
    for(int i = 0 ; i < y+d1 ; i++){
        for(int j = 0 ; j <= x ; j++){
            if(visit[i][j] == 5) break;
            p[1] += a[i][j];
        }
    }
    // 2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
    for(int i = 0 ; i <= y+d2 ; i++){
        for(int j = n-1 ; j > x  ; j--){
            if(visit[i][j] == 5) break;
            p[2] += a[i][j];
        }
    }
    // 3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
    for(int i = y+d1 ; i <= n-1 ; i++){
        for(int j = 0 ; j < x-d1+d2 ; j++){
            if(visit[i][j] == 5) break;
            p[3] += a[i][j];
        }
    }
    // 4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
    for(int i = y+d2+1 ; i <= n-1 ; i++){
        for(int j = n-1 ; j >= x-d1+d2  ; j--){
            if(visit[i][j] == 5) break;
            p[4] += a[i][j];
        }
    }

    p[5] = total - p[1] - p[2] - p[3] - p[4];
    sort(p.begin(), p.end());
    mingap = min(mingap, abs(p[5] - p[1]));
}

int main(){
    mingap = 987987987;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< n ; j++){
            cin >> a[i][j];
            total += a[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){ // y
        for(int j = 0 ; j < n ; j++){ // x
            for(int k = 1 ; k < n ; k++){ // d1
                for(int l = 1 ; l < n ; l++){ // d2
                    if(i+1 + k + l <= n && j+1 - k >= 1 && j+1 + l <= n) solve(i,j,k,l);
                }
            }
        }
    }

    cout << mingap << "\n";
    return 0;
}
/*
    14:20 ~ 15:08
*/