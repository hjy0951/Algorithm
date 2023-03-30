/*
연습문제
무인도 여행 - lv2
: 지도에 식량이 표기되어 있고 각 섬에서 최대 며칠씩 머무를 수 있는지 배열에 오름차순으로 담아 return

- 일반적인 BFS 문제.
- 지도를 순회하면서 'X'가 아닌 숫자일 경우, 주변의 숫자들을 탐색하며 모든 숫자를 더해 answer 배열에 push

-> 배열 내장함수인 shift를 사용하였는데, 시간복잡도가 O(N)이므로 매우 비효율적이라고 생각함.
   배열의 가장 앞의 원소를 빼내고, 뒤의 모든 원소들을 앞으로 당겨와야하기 때문.
   다른 방법을 생각해보자.
 */

function solution(maps) {
  const answer = [];
  let visit = makeVisit(maps.length, maps[0].length);

  for (let i = 0; i < maps.length; i++) {
    const row = maps[i];
    for (let j = 0; j < row.length; j++) {
      const current = row[j];
      if (maps[i][j] !== "X" && visit[i][j] === 0) {
        const [count, newVisit] = bfs(maps, visit, i, j);
        answer.push(count);
        visit = newVisit;
      }
    }
  }

  if (answer.length === 0) answer.push(-1);
  else
    answer.sort((a, b) => {
      return a - b;
    });
  return answer;
}

function makeVisit(h, w) {
  return Array.from(Array(h), () => Array(w).fill(0));
}

function bfs(maps, visit, sy, sx) {
  const dy = [0, 0, -1, 1];
  const dx = [1, -1, 0, 0];
  const h = maps.length;
  const w = maps[0].length;
  const q = [];
  let total = parseInt(maps[sy][sx]);
  visit[sy][sx] = 1;
  q.push([sy, sx]);

  while (q.length > 0) {
    const [cy, cx] = q[0];
    q.shift();

    for (let i = 0; i < 4; i++) {
      const ny = cy + dy[i];
      const nx = cx + dx[i];

      if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      if (maps[ny][nx] === "X" || visit[ny][nx] !== 0) continue;

      total += parseInt(maps[ny][nx]);
      visit[ny][nx] = 1;
      q.push([ny, nx]);
    }
  }
  return [total, visit];
}
