// 백준 1072 게임
#include <iostream>
#include <cmath>

using namespace std;
/*
앞으로의 모든 게임에서 지지 않는다
게임 기록
    - 게임 횟수 : X
    - 이긴 게임 : Y (Z %)
    - Z는 승률이다. 소수점은 버린다. 예를 들어, X=53, Y=47이라면, Z = 88이다.
게임을 몇 판 더해야 Z가 변하는지
*/
long long int x,y;
long long int z;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;

    long long int s = 0;
    long long int e = 1000000000;
    int cur_z = (y * 100) / x;

    if(cur_z >= 99){
        cout << "-1" << endl;
        return 0;
    }

    long long int ans = -1;
    while(s <= e){
        long long int mid = (s+e)/2;

        long long int temp_x = x + mid;
        long long int temp_y = y + mid;
        
        int temp_z = (temp_y * 100)/temp_x;

        if(temp_z <= cur_z){
            s = mid + 1;
            ans = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }

    y = y + ans;
    x = x + ans;
    int next_z = (100 * y) / x;
    
    cout << ans << endl;

    return 0;
}