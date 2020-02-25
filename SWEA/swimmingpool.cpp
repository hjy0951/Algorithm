// SWEA 수영장
/*
   ① 1일 이용권 : 1일 이용이 가능하다.

   ② 1달 이용권 : 1달 동안 이용이 가능하다. 1달 이용권은 매달 1일부터 시작한다.

   ③ 3달 이용권 : 3달 동안 이용이 가능하다. 3달 이용권은 매달 1일부터 시작한다.
       (11월, 12월에도 3달 이용권을 사용할 수 있다)

   ④ 1년 이용권 : 1년 동안 이용이 가능하다. 1년 이용권은 매년 1월 1일부터 시작한다.

    각 이용권의 요금과 각 달의 이용 계획이 입력으로 주어질 때,

    가장 적은 비용으로 수영장을 이용할 수 있는 방법을 찾고 그 비용을 정답으로 출력하는 프로그램을 작성하라.
*/
#include <iostream>

using namespace std;

int cost[4]; // 수영장 이용 요금
int plan[12]; // 1년 간 이용 계획
int mincost; // 최소 비용

void cal(int cur, int curcost){
    if(cur >= 12){
        if(mincost > curcost) mincost = curcost;
        if(mincost > cost[3]) mincost = cost[3];
        return;
    }
    else{
        if(plan[cur] == 0){
            cal(cur+1, curcost);
        }
        else{
            cal(cur+1, plan[cur] * cost[0] + curcost); // 1일권
            cal(cur+1, cost[1] + curcost); // 1달권
            cal(cur+3, cost[2] + curcost); // 3달권
        }
    }
}

int main(){
    int T;
    cin >> T;

    for(int i = 1 ; i <= T ; i++){
        mincost = 987987987; // 최소 요금 초기화

        // 기간별 수영장 요금
        for(int j = 0 ; j < 4 ; j++){
            cin >> cost[j];
        }
        // 1년간 이용 계획
        for(int j = 0 ; j < 12 ; j++){
            cin >> plan[j];
        }

        cal(0,0); // 최소 비용 계산

        cout << "#" << i << " " << mincost << endl;
    }
    return 0;
}