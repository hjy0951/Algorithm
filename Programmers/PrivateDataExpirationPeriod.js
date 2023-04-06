/*
2023 KAKAO BLIND RECRUITMENT
개인정보 수집 유효기간
: 개인정보 수집 일자와 개인정보 유효기간이 주어졌을때, 현재 날짜에 폐기할 개인정보 인덱스를 return하라

- 단순 문자열 문제로, 문자열을 파싱하여 숫자로 비교하는 문제
*/

function solution(today, terms, privacies) {
  var answer = [];
  const splitToday = today.split(".").map(Number);
  const deadline = {};

  terms.forEach((term) => {
    let [type, month] = term.split(" ");
    deadline[type] = Number(month);
  });

  for (let i = 0; i < privacies.length; i++) {
    const [currentDate, type] = privacies[i].split(" ");
    let splitCurrent = currentDate.split(".").map(Number);

    splitCurrent[1] += deadline[type];
    while (splitCurrent[1] > 12) {
      splitCurrent[1] -= 12;
      splitCurrent[0]++;
    }
    splitCurrent[2]--;
    if (splitCurrent[2] === 0) {
      splitCurrent[2] = 28;
      splitCurrent[1]--;
      if (splitCurrent[1] === 0) {
        splitCurrent[1] = 12;
        splitCurrent[0]--;
      }
    }

    if (splitCurrent[0] < splitToday[0]) {
      answer.push(i + 1);
    } else if (splitCurrent[0] === splitToday[0]) {
      if (splitCurrent[1] < splitToday[1]) {
        answer.push(i + 1);
      } else if (splitCurrent[1] === splitToday[1]) {
        if (splitCurrent[2] < splitToday[2]) {
          answer.push(i + 1);
        }
      }
    }
  }
  return answer;
}
