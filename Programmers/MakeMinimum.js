/*
연습문제
최솟값 만들기
: 길이가 같은 두 배열 A,B에서 숫자를 하나씩 골라 곱하고 모든 결과를 더했을때의 최소값을 구하라

- sort를 그냥 사용할 경우, string에 대한 정렬이라 답이 틀림
- 콜백함수를 넣어 사용하자
*/

function solution(A, B) {
  var answer = 0;
  A.sort((a, b) => a - b);
  B = B.sort((a, b) => a - b).reverse();

  for (let i = 0; i < A.length; i++) {
    answer += A[i] * B[i];
  }
  return answer;
}
