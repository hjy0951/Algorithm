/*
SWEA SW 문제해결 Sum
    다음 100X100의 2차원 배열이 주어질 때, 각 행의 합, 각 열의 합, 각 대각선의 합 중 최댓값을 구하는 프로그램을 작성하여라.
    다음과 같은 5X5 배열에서 최댓값은 29이다.
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[100][100]; // 100 x 100 행렬
int row[100]; // 각 행의 합
int col[100]; // 각 열의 합
int d,rd;
int maxn; // 최대값

int main(){
    for(int x = 1 ; x <= 10 ; x++){
        //init
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        d = 0;
        rd = 0;
        maxn = 0;

        //input
        int n;
        cin >> n;

        for(int i = 0 ; i < 100 ; i++){
            for(int j = 0 ; j < 100 ; j++){
                cin >> arr[i][j];

                row[i] += arr[i][j]; // 각 행의 합
                col[j] += arr[i][j]; // 각 열의 합
                if(i == j){
                    d += arr[i][j]; // 대각선 합
                }
                if(i + j == 99){
                    rd += arr[i][j]; // 반대 대각선 합
                }
            }
        }

        // 가장 큰 값 찾기
        sort(row,row+100);
        sort(col,col+100);
        if(row[99] > col[99]) maxn = row[99];
        else maxn = col[99];

        if(d > rd){
            if(maxn < d) maxn = d;
        }
        else{
            if(maxn < rd) maxn = rd;
        }

        //output
        cout << "#" <<  x << " " << maxn << endl;
    }
    return 0;
}

/*
#1 1712
#2 1743
#3 1713
#4 1682
#5 1715
#6 1730
#7 1703
#8 1714
#9 1727
#10 1731

*/