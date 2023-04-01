/*
2018 KAKAO BLIND RECRUITMENT
[3차] n진수 게임
: m명이 게임을 할 때, 주어진 n에 대한 진법으로 숫자를 변환하여 내 차례 p에 불러야할 숫자를 t개 구하는 문제

- JavaScript에서는 toString을 통해 숫자를 n진수로 만들기가 매우 편리
- 위 toString을 이용하여 미리 숫자에 대한 문자열을 만들어둠
- 게임 인원 m명과 구할 숫자 t에 대해서 (m * t)가 최대 문자열의 길이로 생각하고 푸는 것이 포인트
*/

function solution(n, t, m, p) {
  var answer = "";
  let numbers = "";
  let number = 0;

  while (numbers.length <= t * m) {
    numbers += number.toString(n).toUpperCase();
    number++;
  }

  let index = p - 1;
  while (index < numbers.length && answer.length < t) {
    answer += numbers[index];
    index += m;
  }
  return answer;
}
