// 백준 1079 마피아
/*
    1. 참가자는 두 그룹으로 나누어진다. 한 그룹은 마피아이고, 또 다른 그룹은 선량한 시민이다. 
       마피아의 정체는 시민에게 알려져 있지 않다. 참가자의 번호는 0번부터 시작한다.
    2. 참가자가 짝수 명 남았을 때는 밤이다. 밤에는 마피아가 죽일 사람 한 명을 고른다. 죽은 사람은 게임에 더 이상 참여할 수 없다.
    3. 참가자가 홀수 명 남았을 때는 낮이다. 낮에는 참가자들이 가장 죄가 있을 것 같은 사람 한 명을 죽인다.
    4. 만약 게임에 마피아가 한 명도 안 남았다면, 그 게임은 시민 팀이 이긴 것이고, 
       시민이 한 명도 안 남았다면, 그 게임은 마피아 팀이 이긴 것이다. 게임은 즉시 종료된다.
    
    지금 이 게임에서 자기가 마지막으로 남은 마피아라는 것을 알았다.
    각 사람의 유죄 지수가 주어진다. 
    이 유죄 지수는 낮에 시민들이 어떤 참가자를 죽일 것인지 고를 때 쓰인다. 
    그리고 참가자 간의 반응을 나타내는 2차원 배열 R이 주어진다.

    게임은 다음과 같이 진행된다.
        1. 밤에는 마피아가 죽일 사람을 한 명 고른다. 이 경우 각 사람의 유죄 지수가 바뀐다. 
           만약 참가자 i가 죽었다면, 다른 참가자 j의 유죄 지수는 R[i][j]만큼 변한다.
        2. 낮에는 현재 게임에 남아있는 사람 중에 유죄 지수가 가장 높은 사람을 죽인다. 
           그런 사람이 여러 명일 경우 그중 번호가 가장 작은 사람이 죽는다. 이 경우 유죄 지수는 바뀌지 않는다.

    되도록이면 이 게임을 오래 하고 싶다. 
    이 게임에 정말 천재적으로 임하여 매번 최적의 선택을 할 때, 몇 번의 밤이 지나는지 출력하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int guilty[17];
int r[17][17];
int me;
int maxcnt;
bool dead[17];

bool check(){
    for(int i = 0 ; i < n ; i++){
        if(dead[i] == false) return false;
    }
    return true;
}

void game(bool day, int cnt){
    if(day){ // 낮
        // 남아있는 사람 중에 유죄 지수가 가장 높은 사람을 죽인다. 
        int victim = -1;
        for(int i = 0 ; i < n ; i++){
            if(dead[i] == true) continue;

            if(victim < 0) victim = i;
            else{
                if(guilty[victim] < guilty[i]){
                    victim = i;
                }
            }
        }

        dead[victim] = true;
        // 마피아가 한 명도 안 남았다면, 그 게임은 시민 팀이 이긴 것
        if(victim == me){
            maxcnt = max(maxcnt, cnt);
        }
        else game(!day, cnt+1);
        dead[victim] = false;
    }
    else{ // 밤
        for(int i = 0 ; i < n ; i++){
            if(dead[i] == true) continue;
            if(i == me) continue;
            
            // 밤에는 마피아가 죽일 사람 한 명을 고른다
            dead[i] = true;
            // 만약 참가자 i가 죽었다면, 다른 참가자 j의 유죄 지수는 R[i][j]만큼 변한다.
            for(int j = 0 ; j < n ; j++){
                if(i == j) continue;
                guilty[j] += r[i][j];
            }
            bool ox = check();
            // 시민이 한 명도 안 남았다면, 그 게임은 마피아 팀이 이긴 것이다. 게임은 즉시 종료
            if(ox == true){
                maxcnt = max(maxcnt, cnt);
            }
            else game(!day, cnt);
            dead[i] = false;
            for(int j = 0 ; j < n ; j++){
                if(i == j) continue;
                guilty[j] -= r[i][j];
            }
        }
    }
}

int main(){
    // 사람 수
    cin >> n;
    // 유죄지수
    for(int i = 0 ; i < n ; i++) cin >> guilty[i];
    // 배열 R
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> r[i][j];
        }
    }
    // 내 번호
    cin >> me;

    if(n%2 == 1) game(true, 0); // 낮
    else game(false, 1); // 밤

    cout << maxcnt << '\n';
    return 0;
}