// 백준 14889 스타트와 링크
#include <iostream>

using namespace std;

int N; // 사람 수
int p[25][25] = {0,}; // 능력치 표
int check[25]; //  team check
int mingap = 987987987; // 최소 능력치 차이

int ta[15] = {0,};
int tb[15] = {0,};

void printt(){
    for(int i = 0 ; i < N/2 ; i++){
        cout << ta[i] << " ";
    }
    cout << endl;

    for(int i = 0 ; i < N/2 ; i++){
        cout << tb[i] << " ";
    }
    cout << endl;
}

// "1이 무조건 포함된 팀 || 1이 포함되지 않은 팀" 으로 나누어 능력치 비교
void find(int cur, int n){
    if(n >= N/2){ // 팀을 모두 나눈 상태 / 능력치 차이 구함
        int cb = 0;

        for(int i = 1 ; i <= N ; i++){
            if(check[i] == 0){
                tb[cb++] = i;        
            }
        }

        int suma = 0;
        int sumb = 0;

        // cout << endl;
        for(int i = 0 ; i < N/2 -1 ; i++){
            for(int j = i+1 ; j < N/2 ; j++){
                suma += (p[ta[i]][ta[j]] + p[ta[j]][ta[i]]);
                sumb += (p[tb[i]][tb[j]] + p[tb[j]][tb[i]]);
                // cout << "i & j : " << i << " " << j << endl;
            }
        }
        // cout << endl;
        int gap = suma - sumb;
        if(gap < 0) gap = gap * (-1);
        if(mingap > gap) mingap = gap;

        printt();
        cout << endl;
        return;
    }
    else{ // 팀 나누기
        for(int i = cur+1 ; i <= N ; i++){
            if(check[i] == 0){
                check[i] = 1; // 팀 명단에 넣음
                ta[n] = i;
                find(i,n + 1);
                ta[n] = 0;
                check[i] = 0; // 팀 명단 제외
            }
        }
    }
}

int main(){
    cin >> N;

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> p[i][j];
        }
    }

    check[1] = 1;
    ta[0] = 1;
    find(1,1);

    cout << mingap << endl;

    return 0;
}
