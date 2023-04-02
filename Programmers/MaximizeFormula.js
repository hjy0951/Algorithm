/*
2020 카카오 인턴십
수식 최대화
: 주어진 수식에 연산문자의 계산 우선순위를 달리하여 최대가 되는 절대값을 return

- +,-,*에 대한 우선순위를 설정하기 위해 순열이 필요하여 구글링함
- 이외에는 숫자와 연산문자를 분리하는 split 함수를 구현하였고, 이를 가지고 완전 탐색으로 풀이
*/

function solution(expression) {
  var answer = 0;
  let originSplitExp = splitExpression(expression);
  let priorities = [];
  let maxResult = 0;
  permutation([], ["+", "-", "*"], priorities);

  for (let i = 0; i < priorities.length; i++) {
    let priority = 0;
    const operators = priorities[i];
    let splitExp = originSplitExp;

    while (priority < 3) {
      const stk = [];
      const currentOp = operators[priority];

      for (let j = 0; j < splitExp.length; j++) {
        const current = splitExp[j];

        if (current === currentOp) {
          const left = stk.pop();
          const right = splitExp[j + 1];
          if (currentOp === "+") stk.push(left + right);
          else if (currentOp === "-") stk.push(left - right);
          else if (currentOp === "*") stk.push(left * right);
          j++;
        } else {
          stk.push(current);
        }
      }

      splitExp = stk;
      priority++;
    }

    let result = splitExp[0];
    if (result < 0) result *= -1;
    if (maxResult < result) maxResult = result;
  }
  answer = maxResult;
  return answer;
}

function permutation(permu, rests, output) {
  if (rests.length == 0) {
    return output.push(permu);
  }
  rests.forEach((v, idx) => {
    const rest = [...rests.slice(0, idx), ...rests.slice(idx + 1)];
    permutation([...permu, v], rest, output);
  });
}

function splitExpression(expression) {
  let num = "";
  const result = [];

  for (let i = 0; i < expression.length; i++) {
    const current = expression[i];

    if ("0" <= current && current <= "9") num += current;
    else {
      result.push(parseInt(num));
      num = "";
      result.push(current);
    }
  }
  result.push(parseInt(num));
  return result;
}
