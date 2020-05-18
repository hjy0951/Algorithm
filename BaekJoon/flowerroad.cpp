// 백준 14620 꽃길
/*
    식목일마다 꽃을 심는다.
    꽃의 씨앗은 꽃을 심고나면 정확히 1년후에 꽃이 피므로 다음해 식목일 부터 꽃길을 걸을 수 있다.
    하지만 꽃의 씨앗이 세개밖에 없었으므로 세 개의 꽃이 하나도 죽지 않고 1년후에 꽃잎이 만개하길 원한다.

    씨앗      꽃
    0 0 0    0 1 0
    0 1 0 -> 1 1 1
    0 0 0    0 1 0

    꽃을 심을 때는 주의할 점이있다. 
    1. 어떤 씨앗이 꽃이 핀 뒤 다른 꽃잎(혹은 꽃술)과 닿게 될 경우 두 꽃 모두 죽어버린다. 
    2. 화단 밖으로 꽃잎이 나가게 된다면 그 꽃은 죽어버리고 만다.
    화단의 대여 가격은 격자의 한 점마다 다르기 때문에 서로 다른 세 씨앗을 모두 꽃이 피게하면서 가장 싼 가격에 화단을 대여하고 싶다.
    화단을 대여할 때는 꽃잎이 핀 모양을 기준으로 대여를 해야하므로 꽃 하나당 5평의 땅을 대여해야만 한다.
    꽃을 심기 위해 필요한 최소비용을 구해주자!
*/
#include <iostream>

using namespace std;

int n;
int map[11][11];
int mincost;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void print(int arr[][11]){
    cout << '\n';
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void copy(int arr1[][11], int arr2[][11]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            arr2[i][j] = arr1[i][j];
        }
    }
}

void flower(int y, int x, int cnt, int check[][11], int cost){
    if(cnt >= 3){
        mincost = min(mincost, cost);
        print(check);
        return;
    }
    else{
        int temp[11][11];
        copy(check, temp);
        temp[y][x] = 1;
        int tempcost = map[y][x];

        for(int i = 0 ; i < 4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n) return;
            if(temp[ny][nx] != 0) return;

            temp[ny][nx] = 1;
            tempcost += map[ny][nx];
        }

        for(int i = y ; i < n ; i++){
            if(i == y){
                for(int j = x+1 ; j < n-1 ; j++){
                    if(temp[i][j] == 0) flower(i,j,cnt+1,temp,cost+tempcost);
                }
            }
            else{
                for(int j = 1 ; j < n-1 ; j++){
                    if(temp[i][j] == 0) flower(i,j,cnt+1,temp,cost+tempcost);
                }
            }
        }
    }
}

int main(){
    mincost = 987987987;

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < n ; j++){
            int arr[11][11] = {0,};
            flower(i,j,0,arr,0);
        }
    }

    cout << mincost << '\n';

    return 0;
}