/*
2022 KAKAO TECH INTERNSHIP
성격 유형 검사하기
: 사용자가 설문한 내용과 성격 유형이 주어졌을때, 사용자의 성격 유형을 return하라

- Object로 설문에 대한 결과를 저장하고, type 배열에 상반되는 성격 유형을 저장하여 결과값에 따라 성격 유형을 return
*/

function solution(survey, choices) {
  var answer = "";
  const type = [
    ["R", "T"],
    ["C", "F"],
    ["J", "M"],
    ["A", "N"],
  ];
  const property = { R: 0, T: 0, C: 0, F: 0, J: 0, M: 0, A: 0, N: 0 };

  for (let i = 0; i < survey.length; i++) {
    const [disagree, agree] = survey[i].split("");
    const point = choices[i];

    if (point === 0) continue;
    else if (point < 4) property[disagree] += 4 - (point % 4);
    else property[agree] += point % 4;
  }

  for (let i = 0; i < type.length; i++) {
    const [t1, t2] = type[i];
    const point1 = property[t1];
    const point2 = property[t2];

    if (point1 > point2) answer += t1;
    else if (point1 < point2) answer += t2;
    else answer += t1 < t2 ? t1 : t2;
  }
  return answer;
}
/*
비동의 -> RT <- 동의
  1 ~~~~~~~~~~~ 7
매우 비동의    매우 동의
1 3
2 2
3 1
4 0
5 1
6 2
7 3
*/
