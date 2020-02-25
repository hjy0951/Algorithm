// 백준 10775 공항
/*
    공항에는 G개의 게이트가 있으며 각각은 1에서 G까지의 번호를 가지고 있다.
    공항에는 P개의 비행기가 순서대로 도착할 예정이며
    i번째 비행기를 1번부터 gi (1 ≤ gi ≤ G) 번째 게이트중 하나에 영구적으로 도킹하려 한다.
    비행기가 도킹된 게이트에는 다른 비행기가 도착할 수 없다.
    비행기를 최대 몇 대 도킹시킬 수 있는가
*/
#include <iostream>

using namespace std;

int g, p; // 각각 10만이므로 O(n^2)로 풀면 시간초과
int gate[100001] = {0, }; // 도킹 여부 확인을 위한 배열
int total; // 비행기 도킹 수

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // 빠른 입출력

    cin >> g >> p;

    bool event = false; // 사고 발생 여부

    for(int i = 1 ; i <= p ; i++){
        if(event == true) break; // 사고 발생
        int cp;
        cin >> cp; // 현재 비행기가 가장 멀리 갈 수 있는 게이트

        // 이미 게이트에 도킹된 비행기가 있다면 gate[cp] == 1로 loop가 진행됨
        // 그러한 경우 t의 값이 1이므로 cp가 하나씩 줄어들면서 도킹 가능한 게이트를 찾아감
        while(cp > 0 && gate[cp] > 0){ 
            int t = gate[cp];
            gate[cp] = gate[cp] + 1;
            cp = cp - t;
        }

        // 게이트 번호가 0보다 작아질 경우, 도킹 가능한 게이트가 없으므로 사고 발생
        if(cp <= 0) event = true;
        else{ // 그렇지 않은 경우, 도킹했음을 표시하고 도킹된 비행기 수를 +1
            gate[cp] = 1;
            total++;
        }
    }

    cout << total << "\n";
    return 0;
}