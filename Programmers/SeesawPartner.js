/*
연습문제
시소 짝꿍 - lv2
: 중심으로부터 2(m), 3(m), 4(m) 거리의 지점에 좌석이 하나씩 있는 시소에 시소 짝꿍이 몇 쌍 존재하는지 구하여 return
  토크를 계산하여 양쪽의 토크가 같은 경우 "시소 짝꿍"이라함. (토크 = 거리 x 무게)

- 비율이 아닌 배수 개념으로 생각하여 시간이 많이 걸림.
*/
function solution(weights) {
  var answer = 0;
  const check = new Array(4001).fill(0);

  for (let i = 0; i < weights.length; i++) {
    const current = weights[i];

    answer +=
      check[current] +
      check[current * 2] +
      (current % 2 === 0 ? check[(current / 2) * 3] + check[current / 2] : 0) +
      (current % 3 === 0
        ? check[(current / 3) * 2] + check[(current / 3) * 4]
        : 0) +
      (current % 4 === 0 ? check[(current / 4) * 3] : 0);

    check[current] += 1;
  }
  return answer;
}
