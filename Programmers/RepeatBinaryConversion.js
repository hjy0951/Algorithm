/*
월간 코드 챌린지 시즌1
이진 변환 반복하기
: 이진수에서 0을 제거하고, 남은 수의 길이를 이진수로 변환하는 과정을 1이 될 때까지 반복하면서 
  변환 횟수, 제거한 0의 수를 구하라
  
- 단순 구현 문제
- 0을 이용하여 split하고, join하는 과정을 거치며 변환 이전, 이후 string의 길이를 비교하여
  제거한 0의 갯수를 구함
*/

function solution(s) {
  let temp = s;
  let prevLen = 0,
    currentLen = 0,
    stageCount = 0,
    zeroCount = 0;

  while (temp !== "1") {
    prevLen = temp.length;
    temp = temp.split("0").join("");
    currentLen = temp.length;
    temp = temp.length.toString(2);
    zeroCount += prevLen - currentLen;
    stageCount++;
  }

  return [stageCount, zeroCount];
}
