/*
코딩테스트 연습
코딩테스트 입문
옹알이 (1)
: "aya", "ye", "woo", "ma"을 한번씩만 조합하여 옹알이하는 아기가 있을때, 
  주어진 단어중 발음 가능한 단어의 수를 구하라

- 발음할 수 있는 단어사전을 만들어서 includes를 이용할까 했지만, 비효율적일 것 같다는 생각이 듦
- string 관련 기본 함수중 replace가 존재하여 이를 이용
*/

function solution(babbling) {
  var answer = 0;
  const canSpeak = ["aya", "ye", "woo", "ma"];
  babbling.forEach((word) => {
    let checkWord = word;
    canSpeak.forEach((sound) => {
      checkWord = checkWord.replace(sound, "1");
    });
    checkWord = checkWord.replaceAll("1", "");
    answer += checkWord === "" ? 1 : 0;
  });
  return answer;
}
