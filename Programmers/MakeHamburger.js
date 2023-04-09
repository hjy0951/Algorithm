/*
연습문제
햄버거 만들기
: 재료 정보가 주어졌을때 만들 수 있는 햄버거의 수를 구하라.

- 전형적인 Stack 문제
- 1이 나왔을때 stack의 top-2 ~ top이 123으로 존재하는지만 확인
*/

function solution(ingredient) {
  var answer = 0;
  const stk = [];

  for (let i = 0; i < ingredient.length; i++) {
    const current = ingredient[i];
    if (stk.length === 0 || current > 1) {
      stk.push(current);
    } else {
      let isPerfect = true;
      for (let j = 0; j < 3; j++) {
        const check = stk[stk.length - 1 - j];
        if (check !== 3 - j) {
          isPerfect = false;
          stk.push(current);
          break;
        }
      }

      if (isPerfect) {
        answer++;
        for (let j = 0; j < 3; j++) stk.pop();
      }
    }
  }
  return answer;
}
