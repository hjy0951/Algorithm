/*
2020 카카오 인턴십
경주로 건설
: 경주로를 건설하려 할 때, 최소 비용을 구하라

- 커브를 건설할 경우 추가 금액이 존재하여 어떤 지점에 도달하였을때, 최소 비용이라 단정지을 수 없음.
- 위의 점을 빠르게 깨닫지 못하여 시간이 오래 걸림.
- 3차원 배열을 통해 한 지점에 도달하였을때의 방향에 따른 비용을 저장하고, 도착 지점에서 모든 방향에 대한 최소값를 구하여 계산.
- 단순 BFS로는 한계가 있는 문제.
- Linked List로 구현한 Queue를 사용하여 시간 단축이 가능하였지만, shift를 이용해도 될 것 같다.
*/

class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.front = null;
    this.rear = null;
    this.size = 0;
  }

  isEmpty() {
    return this.size === 0;
  }

  getSize() {
    return this.size;
  }

  push(data) {
    const newNode = new Node(data);

    if (this.isEmpty()) this.front = newNode;
    else this.rear.next = newNode;

    this.rear = newNode;
    this.size++;
  }

  pop() {
    if (this.isEmpty()) return;

    const data = this.front.data;

    this.front = this.front.next;
    this.size--;
    return data;
  }
}

function bfs(board) {
  const N = board.length;
  const costMap = Array.from({ length: N }, () =>
    Array.from({ length: N }, () => Array(4).fill(Infinity))
  );
  const q = new Queue();

  q.push([0, 0, 0, 0]); // dir, cost, y, x
  q.push([1, 0, 0, 0]);

  while (!q.isEmpty()) {
    const [cd, cost, cy, cx] = q.pop();
    const directions = getNextDirections(cd);

    for (let i = 0; i < directions.length; i++) {
      const [dirIdx, [dy, dx]] = directions[i];
      const [ny, nx] = [cy + dy, cx + dx];
      let ncost = cost + 100;
      if (dirIdx !== cd) ncost += 500;

      if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
      if (board[ny][nx] === 1) continue;
      if (costMap[ny][nx][dirIdx] <= ncost) continue;

      costMap[ny][nx][dirIdx] = ncost;
      q.push([dirIdx, ncost, ny, nx]);
    }
  }

  return Math.min(...costMap[N - 1][N - 1]);
}

function getNextDirections(currentDir) {
  const directions = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0],
  ];
  const nextDirections = [];
  const canNotMove = (currentDir + 2) % 4;

  for (let i = 0; i < 4; i++) {
    if (canNotMove === i) continue;
    nextDirections.push([i, directions[i]]);
  }
  return nextDirections;
}

function solution(board) {
  return bfs(board);
}

/*
[[0,0,0,0,0,0,0,0],
[1,0,1,1,1,1,1,0],
[1,0,0,1,0,0,0,0],
[1,1,0,0,0,1,1,1],
[1,1,1,1,0,0,0,0],
[1,1,1,1,1,1,1,0],
[1,1,1,1,1,1,1,0],
[1,1,1,1,1,1,1,0]]
*/
