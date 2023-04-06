/*
2019 카카오 개발자 겨울 인턴십
불량 사용자
: 제재 사용자 목록이 주어지고 사용자 아이디 목록이 주어졌을때, 제재 당한 사용자 아이디 목록의 경우의 수를 구하라.

- 문제를 잘못 이해하여 시간이 좀더 걸렸다.
- 백트래킹? DFS?를 통해 조건에 맞는 경우 1을 리턴하여 최종 결과값을 도출하였다.
- 위를 위해 Set 자료구조를 전역변수로 사용하였는데, 좀더 좋은 방법이 있나 찾아봐야할 것 같다.

-> 문제 잘 읽자!
*/

const set = new Set();

function solution(user_id, banned_id) {
  var answer = 0;
  const bannedLen = banned_id.length;
  const userLen = user_id.length;
  const possibleList = Array.from({ length: bannedLen }, () => []);

  for (let i = 0; i < bannedLen; i++) {
    const currentBan = banned_id[i];

    for (let j = 0; j < userLen; j++) {
      const currentUser = user_id[j];
      if (isPossibleBannedId(currentBan, currentUser)) possibleList[i].push(j);
    }
  }

  answer = backTracking(possibleList, 0, []);

  return answer;
}

function backTracking(possibleList, idx, idList) {
  if (idx === possibleList.length) {
    const str = idList.sort((a, b) => a - b).join("");
    if (set.has(str) === true) return 0;
    set.add(str);
    return 1;
  }

  let result = 0;
  const currentList = possibleList[idx];

  for (let i = 0; i < currentList.length; i++) {
    const current = currentList[i];

    if (idList.includes(current) === true) continue;
    idList.push(current);
    result += backTracking(possibleList, idx + 1, [...idList]);
    idList.pop();
  }

  return result;
}

function isPossibleBannedId(ban, user) {
  if (ban.length !== user.length) return false;
  for (let i = 0; i < ban.length; i++) {
    if (ban[i] === "*") continue;
    if (ban[i] !== user[i]) return false;
  }
  return true;
}
