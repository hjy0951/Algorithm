/*
연습문제
바탕화면 정리
: 바탕화면 정보가 주어지고, 모든 아이콘을 한번에 드래그할 수 있는 범위를 찾아라.

- 단순 구현 문제
- 파일의 좌표가 특정 점이 아닌 4개의 점을 갖는다는 점만 조심
*/

function isContained(luy, lux, rdy, rdx, ty, tx) {
  if (luy <= ty && ty + 1 <= rdy && lux <= tx && tx + 1 <= rdx) return true;
  return false;
}

function solution(wallpaper) {
  var answer = [];
  const q = [];
  for (let i = 0; i < wallpaper.length; i++) {
    const row = wallpaper[i];
    for (let j = 0; j < row.length; j++) {
      const current = row[j];
      if (current === "#") {
        q.push([i, j]);
      }
    }
  }

  let luy = q[0][0],
    lux = q[0][1],
    rdy = q[0][0] + 1,
    rdx = q[0][1] + 1;
  for (let i = 1; i < q.length; i++) {
    const [cy, cx] = q[i];
    if (isContained(luy, lux, rdy, rdx, cy, cx) === false) {
      if (rdy < cy + 1) rdy = cy + 1;
      if (rdx < cx + 1) rdx = cx + 1;
      if (cy < luy) luy = cy;
      if (cx < lux) lux = cx;
    }
  }
  answer = [luy, lux, rdy, rdx];
  return answer;
}
