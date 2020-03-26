//고객만족도 설문지에는 고객이 이용했던 접수 창구번호와 정비 창구번호가 있다.
//차량 정비소에는 N개의 접수 창구와 M개의 정비 창구가 있다.
//접수 창구는 1부터 N까지 번호가 붙어 있다. 정비 창구도 1부터 M까지 번호가 붙어 있다.

//  첫 단계는 접수 창구에서 고장을 접수하는 것
//  두 번째 단계는 정비 창구에서 차량을 정비하는 것
//차량 정비가 끝난 고객은 고객만족도 조사를 위해 고객만족도 설문지를 받는다.
//접수 창구 및 정비 창구의 담당자 업무 능력이 달라서 담당자 별 처리 시간이 다르다.

//접수 창구 i에서 고객 한 명의 고장을 접수하는 데 걸리는 처리 시간은 ai이다. (1 ≤ i ≤ N)
//정비 창구 j에서 고객 한 명의 차량을 정비하는 데 걸리는 처리 시간은 bj이다. (1 ≤ j ≤ M)
//고객번호 k의 고객이 차량 정비소에 도착하는 시간은 tk이다. (1 ≤ k ≤ K)

//1. 지금까지 차량 정비소를 방문한 고객은 K명이다. 도착하는 대로 1번부터 고객번호를 부여

//2. 고객이 차량 정비소에 도착하면, 빈 접수 창구가 있는 경우 빈 접수 창구에 가서 고장을 접수한다
//   빈 접수 창구가 없는 경우 빈 접수 창구가 생길 때까지 기다린다.

//3. 고장 접수를 완료하면 정비 창구로 이동
//   빈 정비 창구가 있는 경우 빈 정비 창구에 가서 차량을 정비 받는다.
//   빈 정비 창구가 없는 경우 빈 정비 창구가 생길 때까지 기다린다.

//접수 창구 우선순위
//  ① 여러 고객이 기다리고 있는 경우 고객번호가 낮은 순서대로 우선 접수한다.
//  ② 빈 창구가 여러 곳인 경우 접수 창구번호가 작은 곳으로 간다.

//정비 창구 우선순위
//  ① 먼저 기다리는 고객이 우선한다.
//  ② 두 명 이상의 고객들이 접수 창구에서 동시에 접수를 완료하고 정비 창구로 이동한 경우, 이용했던 접수 창구번호가 작은 고객이 우선한다.
//  ③ 빈 창구가 여러 곳인 경우 정비 창구번호가 작은 곳으로 간다.

//고객의 도착 시간 tk, 접수 창구의 처리 시간 ai, 정비 창구의 처리 시간 bj가 주어졌을 때,
// "지갑을 분실한 고객과 같은 접수 창구와 같은 정비 창구를 이용한 고객의 고객번호들" 을 찾아 그 합을 출력하는 프로그램을 작성하라.
// --------------------------------------------------------------//
//만약, 그런 고객이 없는 경우 -1을 출력한다.

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct Cus{
    int a1;
    int a2;
};

// 접수 창구의 개수 N | 정비 창구의 개수 M
// 차량 정비소를 방문한 고객의 수 K
// 지갑을 두고 간 고객이 이용한 접수 창구번호 A와 정비 창구번호 B
int N,M,K,A,B;
int recept[11]; // 각 접수 창구의 처리 시간 | 0 - 시간 1 - 고객번호
int recept_counter[11][2]; // 접수 창구 | 0 - 시간 1 - 고객번호
int receptnum; // 남아 있는 접수 창구 수
int repair[11]; // 각 정비 창구의 차량 정비 시간 |  0 - 시간 1 - 고객번호
int repair_counter[11][2]; // 정비 창구 | 0 - 시간 1 - 고객번호
int repairnum; // 남아 있는 정비 창구 수
int arrive[1010]; // 손님의 도착시간
int point;
Cus cus[1010];
queue<int> customer; // 손님들 도착시간 입력
queue<int> wait_repair; // 접수 마친 고객의 번호 입력


void simul(){ // index 1부터 시작
    int customer_number = 0;

    for(int time = 0 ; ; time++){
        // cout << endl;
        // cout << endl;
        // cout << "time : " << time << endl;
        // cout << "point : " << point << endl;
        // cout << "customer ? : " << customer.empty() << endl;
        // cout << "ox1 : " << receptnum << " " << N << endl;
        // cout << "ox2 : " << repairnum << " " << M << endl;
        // cout << "recept" << endl; 
        // for(int i = 1 ; i<=N ; i++){
        //     cout << recept_counter[i][0] << " ";
        // }
        // cout << endl;
        // cout << "repair" << endl; 
        // for(int i = 1 ; i<=M ; i++){
        //     cout << repair_counter[i][0] << " ";
        // }
        // cout << endl;

        // 손님이 모두 들어오고, 빈 창구가 없을 경우 종료
        if(customer.empty() == 1 && receptnum >= N && repairnum >= M) break;

        // 접수 완료가 되면 정비 창구로.
        for(int i = 1 ; i <= N ; i++){
            if(recept_counter[i][0] == 0 && recept_counter[i][1] != 0){
                if(i == A) cus[recept_counter[i][1]].a1 = 1;

                wait_repair.push(recept_counter[i][1]);
                recept_counter[i][1] = 0;
                receptnum++;
            }
        }

        // 정비가 끝남
        for(int i = 1 ; i <= M ; i++){
            if(repair_counter[i][0] == 0 && repair_counter[i][1] != 0){
                if(i == B) cus[repair_counter[i][1]].a2 = 1;

                repair_counter[i][1] = 0;
                repairnum++;
            }
        }
        
        // 접수 창구로 손님 입장
        while(!customer.empty() && customer.front() <= time && receptnum > 0){ // 기다리는 고객이 있고 빈 창구가 있으면 입장
            customer_number++;
            int cur = customer.front(); // 같은 시간에 올 경우 큐에 먼저 들어온 손님 우선
            customer.pop();

            for(int i = 1 ; i <= N ; i++){
                if(recept_counter[i][0] <= 0){ // 비어있는 창구로 입장
                    recept_counter[i][0] = recept[i];
                    recept_counter[i][1] = customer_number;
                    receptnum--;
                    break;
                }
            }
        }

        while(!wait_repair.empty() && repairnum > 0){ // 기다리는 고객이 있고 빈 창구가 있으면 입장
            int cur = wait_repair.front();
            wait_repair.pop();

            for(int i = 1 ; i <= M ; i++){
                if(repair_counter[i][0] <= 0){ // 비어있는 창구로 입장
                    repair_counter[i][0] = repair[i];
                    repair_counter[i][1] = cur;
                    repairnum--;
                    break;
                }
            }
        }

        //시간 경과
        for(int i = 1 ; i <= N ; i++){
            if(recept_counter[i][0] > 0) recept_counter[i][0] -= 1;
        }
        for(int i = 1 ; i <= M ; i++){
            if(repair_counter[i][0] > 0) repair_counter[i][0] -= 1;
        }
    }

    for(int i = 1 ; i <= K ; i++){ // 지갑 분실한 고객과 같은 창구 이용한 고객들의 번호를 더함
        if(cus[i].a1 == 1 && cus[i].a2 == 1) point += i;
    }
}

int main(){
    int T;
    cin >> T;
    
    for(int i = 1 ; i <= T ; i++){
        memset(recept,0,sizeof(recept));
        memset(repair,0,sizeof(repair));
        memset(arrive,0,sizeof(arrive));
        memset(recept_counter,0,sizeof(recept_counter));
        memset(repair_counter,0,sizeof(repair_counter));
        point = 0;
        
        cin >> N >> M >> K >> A >> B;

        for(int j = 1 ; j <= N ; j++){ // 각 접수 창구의 처리 시간
            cin >> recept[j];
        }
        receptnum = N;

        for(int j = 1 ; j <= M ; j++){ // 각 정비 창구의 차량 정비 시간
            cin >> repair[j];
        }
        repairnum = M;

        for(int j = 1 ; j <= K ; j++){ // 손님의 도착시간
            cin >> arrive[j];
            customer.push(arrive[j]);
            cus[j].a1 = 0;
            cus[j].a2 = 0;
        }
        simul();
        if(point == 0) point = -1;
        cout << "#" << i << " " << point << endl;
    }

    return 0;
}
/*
1
1 1 2 1 1
5
7
7 10
*/
/*
#1 3
#2 7
#3 2
#4 22
#5 18
#6 15
#7 -1
#8 259
#9 100
#10 164
*/