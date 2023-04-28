/*
완전탐색
피로도
: 피로도가 주어졌을때, 돌 수 있는 던전의 최대 수를 구하라

- 최소 필요 피로도가 있어 모든 케이스를 보지 않으면 최적의 값을 찾기 어려움
- 따라서 DFS를 이용하여 모든 케이스를 보는 완전 탐색 문제
*/

function solution(k, dungeons) {
  var answer = 0;

  const dfs = (restK, count, visit) => {
    answer = answer < count ? count : answer;
    let request, consume;
    for (let i = 0; i < dungeons.length; i++) {
      [request, consume] = dungeons[i];
      if (visit[i] !== 0 || restK < request) continue;
      visit[i] = 1;
      dfs(restK - consume, count + 1, [...visit]);
      visit[i] = 0;
    }
  };
  dfs(k, 0, new Array(dungeons.length).fill(0));
  return answer;
}
