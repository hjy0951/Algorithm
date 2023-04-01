/*
2018 KAKAO BLIND RECRUITMENT
[3차] 압축
: LZW(Lempel–Ziv–Welch) 압축을 구현하여 주어진 문자를 압축하여라.

- LZW 압축에 대한 설명을 자세히 읽고 그대로 구현하는 문제
- 문제 설명을 잘 읽고 구현하는 것과 인덱스 관리가 중요한 문제
*/

function solution(msg) {
  var answer = [];
  const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const dictionary = new Map();
  let word = "",
    prevIdx = -1;

  for (let i = 0; i < alphabet.length; i++) {
    dictionary.set(alphabet[i], i + 1);
  }

  for (let i = 0; i < msg.length; i++) {
    word = msg[i];
    let subIdx = 0;
    let dictionaryIdx = "";

    while (1) {
      dictionaryIdx = dictionary.get(word);

      if (dictionaryIdx === undefined) {
        const newIdx = dictionary.size + 1;
        answer.push(prevIdx);
        dictionary.set(word, newIdx);
        i += subIdx - 1;
        break;
      }
      subIdx++;
      word += msg[i + subIdx];
      prevIdx = dictionaryIdx;
    }
  }

  return answer;
}
