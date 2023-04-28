/*
연습문제
다음 큰 숫자
: 주어진 수를 이진수로 변환하였을때, 1의 개수가 같고 주어진 수보다 큰 가장 작은 자연수를 찾아라

- 규칙을 찾아서 구현해야할 것 같았는데, 주어진 수에서 1씩 증가하면서 찾아도 모든 케이스를 통과
*/

function solution(n) {
  let answer = 0,
    current = n + 1,
    currentCount = 0;
  const count = n.toString(2).split("0").join("").length;

  while (1) {
    currentCount = current.toString(2).split("0").join("").length;
    if (count === currentCount) {
      answer = current;
      break;
    }
    current++;
  }

  return answer;
}
