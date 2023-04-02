/*
2020 KAKAO BLIND RECRUITMENT
괄호 변환
: 올바르지 않은 괄호들을 규칙에 맞게 구현하여 올바르게 바꾸는 문제

- 규칙에 대한 설명이 좀 이상한듯...
- 뒤집어라가 reverse가 아닌 ( -> ), ) -> ( 의 의미여서 뭐가 틀렸는지 찾느라 오래 걸림
- 규칙에 대한 이해가 바로 안되서 오래 걸림
*/

function solution(p) {
  let answer = makeRightBrakets(p);

  return answer;
}

function makeRightBrakets(brakets) {
  if (brakets === "") return brakets;

  const [u, v] = splitBrakets(brakets);
  let ret = "";

  if (isRightBrakets(u) === true) {
    ret += u;
    ret += makeRightBrakets(v);
  } else {
    ret = "(";
    ret += makeRightBrakets(v);
    ret += ")";
    ret += reverseBrakets(u.substr(1, u.length - 2));
  }
  return ret;
}

function isRightBrakets(brakets) {
  const stk = [];

  for (let i = 0; i < brakets.length; i++) {
    const current = brakets[i];

    if (current === "(") stk.push(current);
    else {
      if (stk.length === 0) return false;
      else if (stk[stk.length - 1] === "(") stk.pop();
    }
  }
  return stk.length === 0;
}

function splitBrakets(brakets) {
  let left = 0,
    right = 0;
  for (let i = 0; i < brakets.length; i++) {
    const current = brakets[i];
    if (current === "(") left++;
    else right++;

    if (left !== 0 && left === right) break;
  }
  return [brakets.substr(0, left + right), brakets.substr(left + right)];
}

function reverseBrakets(brakets) {
  let ret = "";
  for (let i = 0; i < brakets.length; i++) {
    ret += brakets[i] === "(" ? ")" : "(";
  }
  return ret;
}
