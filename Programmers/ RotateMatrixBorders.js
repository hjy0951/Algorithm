/*
2021 Dev-Matching: 웹 백엔드 개발자(상반기)
행렬 테두리 회전하기
: 주어진 쿼리에 해당하는 범위의 테두리를 회전시키고 각 쿼리에서 움직이는 테두리중 가장 작은 수를 추출하라

- 시계방향으로 회전하지만, 오히려 반시계로 작업하면 회전 코드가 더욱 깔끔하게 나오는 것 같음
- 더 깔끔한 방법이 있을 것 같지만.... 오늘의 내 머리로는 저렇게 하나하나 돌리면서 최소값을 찾는게 최선...
*/

function solution(rows, columns, queries) {
  var answer = [];
  const board = Array.from(new Array(rows), () =>
    new Array(columns).fill(1)
  ).map((row, r) => row.map((v, c) => r * columns + (c + 1)));

  queries.forEach((query) => {
    answer.push(
      rotate(
        board,
        query.map((e) => e - 1)
      )
    );
  });
  return answer;
}

function rotate(board, query) {
  const [y1, x1, y2, x2] = query;
  const height = y2 - y1;
  const width = x2 - x1;
  let temp = board[y1][x1];
  let minNum = temp;

  for (let i = 0; i < height; i++) {
    const current = board[y1 + i + 1][x1];
    if (minNum > current) minNum = current;
    board[y1 + i][x1] = current;
  }
  for (let i = 0; i < width; i++) {
    const current = board[y1 + height][x1 + i + 1];
    if (minNum > current) minNum = current;
    board[y1 + height][x1 + i] = current;
  }
  for (let i = 0; i < height; i++) {
    const current = board[y1 + height - i - 1][x1 + width];
    if (minNum > current) minNum = current;
    board[y1 + height - i][x1 + width] = current;
  }
  for (let i = 0; i < width; i++) {
    if (i === width - 1) board[y1][x1 + width - i] = temp;
    else {
      const current = board[y1][x1 + width - i - 1];
      if (minNum > current) minNum = current;
      board[y1][x1 + width - i] = current;
    }
  }

  return minNum;
}
