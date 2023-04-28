/*
Summer/Winter Coding(~2018)
영어 끝말잇기
: 영어 끝말잇기 게임을 진행할 때, 탈락한 사람과 그 사람의 몇번째 차례인지를 구하라

- 단순 구현 문제
*/

function solution(n, words) {
  const dictionary = {};
  let current = words[0],
    last = current[current.length - 1],
    i,
    flag = false;
  dictionary[current] = 1;

  for (i = 1; i < words.length; i++) {
    current = words[i];
    if (current[0] !== last || dictionary[current] !== undefined) {
      flag = true;
      break;
    }
    dictionary[current] = 1;
    last = words[i][words[i].length - 1];
  }

  return flag ? [(i % n) + 1, (i - (i % n)) / n + 1] : [0, 0];
}
