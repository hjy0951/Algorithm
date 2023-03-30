/*
2018 KAKAO BLIND RECRUITMENT
[1차] 프렌즈4블록 - lv2
: 게임 보드를 확인하고 같은 블록이 2x2 형태로 모여있다면 점수 획득 후 보드 정렬.
  이후 정렬된 보드에서 같은 게임을 이어가고, 더이상 점수를 획득할 수 있는 블록이 없다면 종료.

- bfs로 풀까 했지만, 일반적인 구현을 통해 해결 가능한 문제.
- 매 턴마다 보드를 탐색하여 없앨 블록들을 배열에 담고, 이후 한번에 없애며 중복되지 않도록 점수 획득.
- 점수 획득 후 보드 정렬.
*/

function solution(m, n, board) {
  var answer = 0;
  const clearQ = [];
  let isBoom = true;
  const dy = [0, 1, 0, 1];
  const dx = [0, 0, 1, 1];
  const splitBoard = board.map((line) => line.split(""));

  while (isBoom === true) {
    isBoom = false;
    // 4블록 찾기
    for (let i = 0; i < m; i++) {
      for (let j = 0; j < n; j++) {
        if (splitBoard[i][j] === "X") continue;
        if (canBoom(splitBoard, m, n, i, j) === false) continue;

        isBoom = true;
        for (let k = 0; k < 4; k++) clearQ.push([i + dy[k], j + dx[k]]);
      }
    }
    // 찾은 블록 확인
    if (isBoom === false) break;

    // 터트리기
    while (clearQ.length > 0) {
      const [y, x] = clearQ.pop();

      if (splitBoard[y][x] !== "X") answer++;
      splitBoard[y][x] = "X";
    }

    // 공간 채우기
    for (let i = 0; i < n; i++) {
      for (let j = m - 1; j > 0; j--) {
        const current = splitBoard[j][i];
        if (current !== "X") continue;

        for (let k = 1; k < m; k++) {
          const nextIdx = j - k;
          if (nextIdx < 0) break;
          if (splitBoard[nextIdx][i] === "X") continue;

          splitBoard[j][i] = splitBoard[nextIdx][i];
          splitBoard[nextIdx][i] = "X";
          break;
        }
      }
    }
  }
  return answer;
}

function canBoom(board, m, n, y, x) {
  const current = board[y][x];
  if (y + 1 >= m || x + 1 >= n) return false;
  return (
    current === board[y + 1][x] &&
    current === board[y][x + 1] &&
    current === board[y + 1][x + 1]
  );
}
