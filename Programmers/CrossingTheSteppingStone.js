/*
2019 카카오 개발자 겨울 인턴십
징검다리 건너기
: 징검다리의 돌에는 숫자가 적혀있고 한 사람이 건널 때마다 -1이 된다고 할 때, 한번에 넘어갈 수 있는 돌의 수 k가 주어지고
  몇명의 사람이 다리를 건널 수 있는지 구하라

- 보자마자 돌의 수가 최대 20만이기 떄문에 시뮬레이션을 통해 -1씩 해갈 경우 무조건 timeout이라 생각함
- 돌에 적혀진 수들을 가지고 Binary Search를 해야하나 싶었지만, 이 또한 20만개의 수가 모두 다를 경우 최악의 시나리오임
- 이전에 leetcode에서 풀었던 sliding window maximum과 비슷한 유형이지 않을까 생각하였음
- 주어진 k만큼의 sliding window를 가지고 window가 꽉 찼을때 max 값을 비교하여 값이 최소가 되는 값이 정답이라고 판단
- JavaScript에는 deque가 없고, shift를 사용할 경우 배열 길이만큼의 시간복잡도가 걸리기 때문에 비효율적이라는 것을 알지만 우선 논리 확인을 위해 구현
- 역시나 시간초과. 하지만 deque를 직접 구현해보기로 함
- 배열을 통해 index관리보다는 Linked List가 더 빠르고 좋을 것이라고 생각함. 맨 앞과 맨 뒤만 보기 때문
- Deque를 직접 구현하여 효율성까지 모두 통과

-> 이런 문제는 오히려 다른 언어를 사용하는게 나을지도..? C++ Deque 썼으면 금방 풀었을듯
*/

class Node {
  constructor(data) {
    this.next = null;
    this.tail = null;
    this.data = data;
  }
}

class Deque {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  size() {
    return this.length;
  }
  isEmpty() {
    return this.length === 0;
  }
  back() {
    return this.length === 0 ? undefined : this.tail.data;
  }
  front() {
    return this.length === 0 ? undefined : this.head.data;
  }

  push(data) {
    let node = new Node(data);

    if (this.length === 0) {
      this.head = node;
      this.tail = node;
    } else {
      node.prev = this.tail;
      this.tail.next = node;
      this.tail = node;
    }
    this.length++;
  }

  pushFront(data) {
    let node = new Node(data);

    if (this.length === 0) {
      this.head = node;
      this.tail = node;
    } else {
      node.next = this.head;
      this.head.prev = node;
      this.head = node;
    }
    this.length++;
  }

  pop() {
    if (this.length === 0) return undefined;

    const target = this.tail;
    if (this.length === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.tail = target.prev;
      target.prev.next = null;
    }
    this.length--;
    target.next = null;
    target.prev = null;
    return target.data;
  }

  popFront() {
    if (this.length === 0) return undefined;

    const target = this.head;
    if (this.length === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.head = target.next;
      target.next.prev = null;
    }
    this.length--;
    target.next = null;
    target.prev = null;
    return target.data;
  }

  printNode() {
    let current = this.head;
    while (current !== null) {
      process.stdout.write(`${current.data} -> `);
      current = current.next;
    }
    process.stdout.write("\n");
  }
}

function solution(stones, k) {
  let answer = 987987987;
  const deque = new Deque();
  let s = 0,
    e = 0;

  for (let i = 0; i < stones.length; i++) {
    const stone = stones[i];
    let backData = deque.back();

    while (backData !== undefined && backData[0] < stone) {
      deque.pop();
      if (deque.length === 0) break;
      backData = deque.back();
    }

    deque.push([stone, i]);

    if (e - s < k) {
      e++;
      if (e - s === k) answer = deque.front()[0];
      continue;
    }

    let frontData = deque.front();
    if (frontData[1] === s) {
      deque.popFront();
      frontData = deque.front();
    }
    // deque.printNode();

    if (answer > frontData[0]) answer = frontData[0];
    e++;
    s++;
  }

  return answer;
}
