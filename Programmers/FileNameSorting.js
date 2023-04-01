/*
2018 KAKAO BLIND RECRUITMENT
[3차] 파일명 정렬
: 파일명을 header, number, tail로 나누어 number를 숫자로 변경하여 정렬하는 문제

- isNaN은 숫자 판별을 위해 사용되는 함수인데, 공백을 숫자라고 판단할줄 몰랐음
- 앞으로도 주의해야할 부분인듯
- 정규표현식을 이용해서 풀면 header, number, tail을 나누는 코드가 좀더 간결해질 것 같음
*/

function solution(files) {
  var answer = [];
  const tempFiles = [];

  files.forEach((file, index) => {
    let numberStartIdx = -1,
      count = 0;
    for (let i = 0; i < file.length; i++) {
      const current = file[i];
      if (numberStartIdx < 0 && current !== " " && isNaN(current) === false) {
        numberStartIdx = i;
        count++;
      } else if (
        numberStartIdx >= 0 &&
        (current === " " || isNaN(current) === true)
      ) {
        break;
      } else if (numberStartIdx >= 0 && isNaN(current) === false) {
        count++;
        if (count === 5) break;
      }
    }
    const splitFileName = [
      file.substr(0, numberStartIdx),
      file.substr(numberStartIdx, count),
      numberStartIdx + count === file.length
        ? ""
        : file.substr(numberStartIdx + count),
    ];
    tempFiles.push([splitFileName, index]);
  });

  //     console.log(tempFiles);

  tempFiles.sort((a, b) => {
    const [[head1, number1], index1] = a;
    const [[head2, number2], index2] = b;
    const lowerHead1 = head1.toLowerCase();
    const lowerHead2 = head2.toLowerCase();

    if (lowerHead1 > lowerHead2) return 1;
    else if (lowerHead1 < lowerHead2) return -1;
    else {
      if (number1 === number2) return index1 - index2;
      else {
        return parseInt(number1) - parseInt(number2);
      }
    }
  });

  answer = tempFiles.map((file) => file[0].join(""));
  return answer;
}
