// 백준 17406 배열 돌리기 4
/*
    크기가 N×M 크기인 배열 A가 있을때, 배열 A의 값은 각 행에 있는 모든 수의 합 중 최솟값을 의미한다. 
    배열은 회전 연산을 수행할 수 있다. 
    회전 연산은 세 정수 (r, c, s)로 이루어져 있고, 
    가장 왼쪽 윗 칸이 (r-s, c-s), 가장 오른쪽 아랫 칸이 (r+s, c+s)인 정사각형을 시계 방향으로 한 칸씩 돌린다는 의미이다. 
    배열의 칸 (r, c)는 r행 c열을 의미한다.
    회전 연산이 두 개 이상이면, 연산을 수행한 순서에 따라 최종 배열이 다르다.
    배열 A와 사용 가능한 회전 연산이 주어졌을 때, 배열 A의 값의 최솟값을 구해보자. 
    회전 연산은 모두 한 번씩 사용해야 하며, 순서는 임의로 정해도 된다.
*/
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int n,m,k;
int a[51][51];
int test[51][51];
int op[10][3];
bool used[10];
vector<int> opnum;
int ans;

void print(int arr[][51]){
    printf("\n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void copy(int arr1[][51], int arr2[][51]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            arr2[i][j] = arr1[i][j];
        }
    }
}

int find_min(){
    int minn = 987987987;
    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = 0 ; j < m ; j++){
            sum += test[i][j];
        }
        minn = min(minn, sum);
    }
    return minn;
}

void rotate(int r, int c, int s){
    for(int i = 1 ; i <= s ; i++){
        int temp,temp2;
        temp = test[r-i][c+i];
        for(int j = c+i ; j > c-i ; j--){
            test[r-i][j] = test[r-i][j-1];
        }
        temp2 = test[r+i][c+i];
        for(int j = r+i ; j > r-i+1 ; j--){
            test[j][c+i] = test[j-1][c+i];
        }
        test[r-i+1][c+i] = temp;
        temp = test[r+i][c-i];
        for(int j = c-i ; j < c+i-1 ; j++){
            test[r+i][j] = test[r+i][j+1];
        }
        test[r+i][c+i-1] = temp2;
        for(int j = r-i ; j < r+i-1 ; j++){
            test[j][c-i] = test[j+1][c-i];
        }
        test[r+i-1][c-i] = temp;
    }
}

void dfs(int cnt){
    if(cnt == k){
        copy(a, test);
        print(test);
        for(int i = 0 ; i < opnum.size() ; i++){
            int cn = opnum[i];
            rotate(op[cn][0],op[cn][1],op[cn][2]);
            print(test);
        }
        ans = min(ans, find_min());
        return;
    }
    else{
        for(int i = 0 ; i < k ; i++){
            if(used[i]) continue;

            used[i] = true;
            opnum.push_back(i);
            dfs(cnt+1);
            opnum.pop_back(); 
            used[i] = false;
        }
    }
}

int main(){
    ans = 987987987;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0 ; i < k ; i++){
        cin >> op[i][0] >> op[i][1] >> op[i][2]; // r,c,s
        op[i][0]--;
        op[i][1]--;
    }

    dfs(0);
    cout << ans << '\n';
    return 0;
}