/*
SWEA S/W 문제해결 1일차 Flatten
    높은 곳의 상자를 낮은 곳에 옮기는 방식으로 최고점과 최저점의 간격을 줄이는 작업을 평탄화라고 한다.
    평탄화를 모두 수행하고 나면, 가장 높은 곳과 가장 낮은 곳의 차이가 최대 1 이내가 된다.
    평탄화 작업을 위해서 상자를 옮기는 작업 횟수에 제한이 걸려있을 때, 제한된 횟수만큼 옮기는 작업을 한 후 최고점과 최저점의 차이를 반환하는 프로그램

    가로 길이는 항상 100으로 주어진다.
    모든 위치에서 상자의 높이는 1이상 100이하로 주어진다.
    덤프 횟수는 1이상 1000이하로 주어진다.
    주어진 덤프 횟수 이내에 평탄화가 완료되면 더 이상 덤프를 수행할 수 없으므로 그 때의 최고점과 최저점의 높이 차를 반환한다
    (주어진 data에 따라 0 또는 1이 된다).
*/

#include <iostream>
#include <algorithm>

using namespace std;

int dump;
int map[100];

int main(){
    for(int q = 1 ; q <= 10 ; q++){
        // input
        cin >> dump;
        for(int i = 0 ; i < 100 ; i++){
            cin >> map[i];
        }

        //algorithm
        for(int i = 0 ; i < dump ; i++){
            sort(map, map + 100);

            if(map[99]-map[0] == 0 || map[99]-map[0] == 1){
                break;
            }
            map[99]--;
            map[0]++;
        }
        sort(map, map + 100);

        //output
        cout << "#" << q << " " << map[99]-map[0] << endl;
    }
    return 0;
}
/*
#1 13
#2 32
#3 54
#4 25
#5 87
#6 14
#7 39
#8 26
#9 13
#10 29
*/