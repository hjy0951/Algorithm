/*
코딩테스트 연습
연습문제
옹알이 (2)
: 발음할 수 있는 옹알이가 주어지고, 연속으로는 발음하지 못한다고 할 때,
  발음할 수 있는 단어의 수를 구하라

- 옹알이(1)에서는 단어를 한번씩만 말할 수 있다는 제약이 있었는데,
  2에는 해당 제약에 대한 말이 없어 좀 모호했던 것 같음
- 각 단어를 replace를 이용하여 인덱스로 대체하고, 하나씩 보면서 발음 가능한지 확인
*/

function solution(babbling) {
  var answer = 0;
  const canSpeak = ["aya", "ye", "woo", "ma"];

  babbling.forEach((word) => {
    if (word.length === 1) return;
    let checkWord = word;
    canSpeak.forEach((sound, index) => {
      checkWord = checkWord.replaceAll(sound, `${index}`);
    });

    let prev,
      isOk = true;
    for (let i = 0; i < checkWord.length; i++) {
      const current = Number(checkWord[i]);

      if (isNaN(current) === true) {
        isOk = false;
        break;
      }
      if (i === 0) {
        prev = current;
        continue;
      }
      if (current === prev) {
        isOk = false;
        break;
      }
      prev = current;
    }
    answer += isOk ? 1 : 0;
  });

  return answer;
}
