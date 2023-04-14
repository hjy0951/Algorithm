/*
2019 카카오 개발자 겨울 인턴십
튜플
: 튜플을 유추하는 그룹이 주어질때, 해당하는 튜플을 return하라

- 단순히 문자열을 parsing하고, 그룹의 길이에 따라 정렬 후 그룹을 찾아가면 됨.
*/

function solution(s) {
  var answer = [];
  const groups = parsing(s);
  const isExist = {};
  groups.sort((a, b) => a.length - b.length);
  groups.forEach((group) => {
    for (const member in group) {
      const current = group[member];
      const result = isExist[current];
      if (result === undefined) {
        answer.push(current);
        isExist[current] = 1;
      }
    }
  });
  return answer;
}

function parsing(str) {
  return str
    .substr(2, str.length - 4)
    .split("},{")
    .map((group) => group.split(",").map(Number));
}
