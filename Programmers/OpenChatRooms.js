/*
2019 KAKAO BLIND RECRUITMENT
오픈채팅방
: 채팅방 출입 기록과 닉네임 변경 기록이 주어질 때, 최종 닉네임을 가지고 출입 내역을 출력하라

- record를 1번 순회하면서 Map을 이용하여 ID에 대한 닉네임을 미리 저장해둠
- 이후 다시 순회하며 출입 기록을 answer에 push
*/
function solution(record) {
  var answer = [];
  const idMap = new Map();
  const splitRecords = [];

  for (let i = 0; i < record.length; i++) {
    const splitRecord = record[i].split(" ");
    splitRecords.push(splitRecord);
    if (splitRecord.length <= 2) continue;
    const [cmd, id, nick] = splitRecord;

    if (cmd === "Enter") {
      idMap.set(id, nick);
    } else {
      idMap.set(id, nick);
    }
  }

  splitRecords.forEach((splitRecord) => {
    const [cmd, id] = splitRecord;
    const nick = idMap.get(id);
    if (cmd === "Enter") {
      answer.push(`${nick}님이 들어왔습니다.`);
    } else if (cmd === "Leave") {
      answer.push(`${nick}님이 나갔습니다.`);
    }
  });
  return answer;
}
