// 백준 17140 2차원 배열과 연산
/*
    1. R 연산: 배열 A의 모든 행에 대해서 정렬을 수행한다. 행의 개수 ≥ 열의 개수인 경우에 적용된다.
    2. C 연산: 배열 A의 모든 열에 대해서 정렬을 수행한다. 행의 개수 < 열의 개수인 경우에 적용된다.

    한 행 또는 열에 있는 수를 정렬하려면, 각각의 수가 몇 번 나왔는지 알아야 한다. 
    그 다음, 수의 등장 횟수가 커지는 순으로, 그러한 것이 여러가지면 수가 커지는 순으로 정렬한다. 
    그 다음에는 배열 A에 정렬된 결과를 다시 넣어야 한다. 
    정렬된 결과를 배열에 넣을 때는, 수와 등장 횟수를 모두 넣으며, 순서는 수가 먼저이다.

    예를 들어, [3, 1, 1]에는 3이 1번, 1가 2번 등장한다. 
    따라서, 정렬된 결과는 [3, 1, 1, 2]가 된다. 다시 이 배열에는 3이 1번, 1이 2번, 2가 1번 등장한다. 
    다시 정렬하면 [2, 1, 3, 1, 1, 2]가 된다.

    정렬된 결과를 배열에 다시 넣으면 행 또는 열의 크기가 달라질 수 있다. 
    R 연산이 적용된 경우에는 가장 큰 행을 기준으로 모든 행의 크기가 변하고, C 연산이 적용된 경우에는 가장 큰 열을 기준으로 모든 열의 크기가 변한다. 
    행 또는 열의 크기가 커진 곳에는 0이 채워진다. 
    수를 정렬할 때 0은 무시해야 한다. 예를 들어, [3, 2, 0, 0]을 정렬한 결과는 [3, 2]를 정렬한 결과와 같다.
    행 또는 열의 크기가 100을 넘어가는 경우에는 처음 100개를 제외한 나머지는 버린다.
    배열 A에 들어있는 수와 r, c, k가 주어졌을 때, A[r][c]에 들어있는 값이 k가 되기 위한 최소 시간을 구해보자.

*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

int n,m,r,c,k;
int map[101][101];
int check[101];

void print(){
    printf("\n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            printf("%3d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void rop(){
    int maxm = 0;
    for(int i = 0 ; i < n ; i++){
        vector<int> num;
        vector<pair<int,int> > v;
        for(int j = 0 ; j < m ; j++){
            if(map[i][j] == 0) continue;
            if(check[ map[i][j] ] == 0) num.push_back(map[i][j]);
            check[ map[i][j] ]++;
        }

        for(int j = 0 ; j < num.size() ; j++){
            v.push_back( make_pair(check[ num[j] ], num[j] ) );
        }
        sort(v.begin(), v.end());

        for(int j = 0 ; j < 101 ; j++){
            map[i][j] = 0;
        }

        for(int j = 0 ; j < v.size()*2 ; j++){
            if(j > 100) break;

            if(j%2 == 0){
                map[i][j] = v[j/2].second;
            }
            else{
                map[i][j] = v[j/2].first;
            }
        }

        int mlen = v.size() * 2;
        if(maxm < mlen){
            maxm = mlen;
            if(maxm > 100) maxm = 100;
        }
        memset(check,0,sizeof(check));
    }
    m = maxm;
}
void cop(){
    int maxn = 0;
    for(int i = 0 ; i < m ; i++){
        vector<int> num;
        vector<pair<int,int> > v;
        for(int j = 0 ; j < n ; j++){
            if(map[j][i] == 0) continue;
            if(check[ map[j][i] ] == 0) num.push_back(map[j][i]);
            check[ map[j][i] ]++;
        }

        for(int j = 0 ; j < num.size() ; j++){
            v.push_back( make_pair(check[ num[j] ], num[j]) );
        }
        sort(v.begin(), v.end());

        for(int j = 0 ; j < 101 ; j++) map[j][i] = 0;

        for(int j = 0 ; j < v.size() * 2 ; j++){
            if(j > 100) break;

            if(j%2 == 0){
                map[j][i] = v[j/2].second;
            }
            else{
                map[j][i] = v[j/2].first;
            }
        }

        int nlen = 2 * v.size();
        if(maxn < nlen ){
            maxn = nlen;
            if(maxn > 100) maxn = 100;
        }
        memset(check,0,sizeof(check));
    }
    n = maxn;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    n = 3;
    m = 3;
    cin >> r >> c >> k;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cin >> map[i][j];
        }
    }

    int t = 0;

    while(1){
        if(map[r-1][c-1] == k) break;

        if(n >= m){
            rop();
        }
        else{
            cop();
        }

        t++;
        if(t > 100) break;
    }

    if(t <= 100) cout << t << '\n';
    else cout << "-1\n";
    return 0;
}