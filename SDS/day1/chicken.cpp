// 백준 : 15686 치킨 배달
#include <iostream>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;

/*
치킨 거리는 집과 가장 가까운 치킨집 사이의 거리
치킨 거리는 집을 기준으로 정해지며, 각각의 집은 치킨 거리를 가지고 있다.
도시의 치킨 거리는 모든 집의 치킨 거리의 합
임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다
도시에 있는 치킨집 중에서 "최대 M개를 고르고", 나머지 치킨집은 모두 폐업시켜야 한다.
어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램을 작성하시오
*/
int n, m; // n x n | 치킨집 M개
int map[55][55]; // 0 : 빈칸 | 1 : 집 | 2 : 치킨집
int total_dist; // 도시의 치킨거리
queue<pair<int,int> > hq; // 집의 위치를 담아둘 큐
int chicken[13][2]; // 치킨집의 위치
int check[13]; // 치킨집 방문 여부
int cnt;

void deliv(int idx, int c){
    if(c == m){
        int len = hq.size();
        int each_dist = 0;

        for(int j = 0 ; j < len ; j++){
            int hy = hq.front().first;
            int hx = hq.front().second;
            hq.pop();

            int min_dist = 987987987;

            // 현재 집과 가장 가까운 치킨집의 위치를 구해서 총 거리에 더해줌
            for(int i = 0 ; i < cnt ; i++){
                if(check[i] == 0) continue;
                int cy = chicken[i][0];
                int cx = chicken[i][1];
                
                int dist = abs(cy - hy) + abs(cx - hx); // 집과 치킨집 사이의 거리
                if(min_dist > dist) min_dist = dist;
            }
            each_dist += min_dist;

            hq.push(make_pair(hy,hx));
        }
        // 위에서 구한 총 거리보다 현재 까지의 최소 도시의 치킨 거리가 크다면 업데이트
        if(total_dist > each_dist) total_dist = each_dist;
        return;
    }
    else{
        for(int i = idx + 1 ; i < cnt ; i++){
            check[i] = 1;
            deliv(i, c+1);  // DFS
            check[i] = 0;
        }
    }
}

int main(){
    total_dist = 987987987;
    cnt = 0;

    cin >> n >> m;
    for(int i =  0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                chicken[cnt][0] = i;
                chicken[cnt][1] = j;
                cnt++;
            }
            else if(map[i][j] == 1) hq.push(make_pair(i,j));
        }
    }

    for(int i = 0 ; i < cnt - m + 1 ; i++){
        check[i] = 1;
        deliv(i,1);
        check[i] = 0;
    }

    cout << total_dist << endl;
    return 0;
}