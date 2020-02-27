// 백준 9466 텀 프로젝트
// 'Brainf**k 인터프리터' 문제 풀기 전에 연습할 사이클 찾기 문제
/*
    프로젝트 팀을 구성하기 위해, 모든 학생들은 프로젝트를 함께하고 싶은 학생을 선택해야 한다.
    (단, 단 한 명만 선택할 수 있다.)
    혼자 하고 싶어하는 학생은 자기 자신을 선택하는 것도 가능
    팀을 구성할 수 있는 경우
        1. s1이 s1을 선택하는 경우
        2. s1이 s2를 선택하고, s2가 s3를 선택하고,..., sr-1이 sr을 선택하고, sr이 s1을 선택하는 경우
    => 사이클이 존재해야지만 팀을 구성할 수 있다.
*/
#include <iostream>
#include <cstring>

using namespace std;

int n;
int arr[100001];
int visit[100001];
int cnt;
int f;
int e;
int ft;

void find_cycle(int cur, int x, int t){ // 현재 노드 / 탐색 순서 / 현재 순서에서 몇 번째 방문 중인지에 대한 시간
    if(visit[cur] != 0){ // 이미 방문한 노드
        if(visit[cur] == x){ // 현재 탐색 순서에 방문한 노드일 경우
            f = 1; // 사이클 탐지
            e = cur; // 사이클이 발생한 노드
            ft = t; // 사이클에 도달한 시간
        }
        return;
    }
    else{
        visit[cur] = x; // 방문 표시
        find_cycle(arr[cur], x, t+1); // DFS

        if(f == 0){ // cycle이 존재하지 않은 경우, 다시 탐색해도 사이클이 생기지 않으므로 -1 처리
            visit[cur] = -1;
        }
        else{ // 생성된 사이클에 대한 처리를 마침
            if(e == cur){
                f = 0;
                cnt += ft - t; // 사이클이 발생한 노드에 도달한 두 시간의 차를 이용하여 사이클의 길이를 구함
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; // test case
    cin >> t;
    for(int q = 0 ; q < t ; q++){
        cnt = 0;

        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cin >> arr[i];
        }

        for(int i = 1 ; i <= n ; i++){
            if(visit[i] == 0){ // DFS로 Cycle 찾기
                find_cycle(i, i, 0);
            }
        }

        memset(visit, 0, sizeof(visit));
        cout << n - cnt << "\n"; // 전체 학생 수 - 팀을 맺은 학생 = 팀을 맺지 못한 학생
    }
    return 0;
}