/*
2021 카카오 채용연계형 인턴십
거리두기 확인하기
: 조건에 따라 거리두기 규칙을 잘 지키고 있는지 확인하는 문제

- 5x5 크기의 대기실이 5개 존재한다는 언급이 있어 속도 제한이 있을 것이라 생각하여 신경씀
- 규칙을 어겼다는 것이 발견되는 순간 해당 대기실에 대한 확인은 멈추고 다음으로 넘어감
- P가 발견되었을때 해당 P를 기준으로 오른쪽과 아래만 확인하면 모든 케이스를 확인할 수 있을 것이라
  생각하였지만, 대각선 왼쪽 아래 부분에 대한 케이스가 빠져 6개 정도 케이스에서 실패가 발견됨
- 직접 그려보며 코너케이스를 발견하였고 이름 구현하여 해결
- 규칙에 맞게 확인하도록 구현하는 것이 핵심인 문제
*/
function solution(places) {
  const answer = [];
  const dy = [1, 2, 1, 1, 0, 0];
  const dx = [0, 0, 1, -1, 1, 2];

  for (let i = 0; i < places.length; i++) {
    const place = places[i];
    let flag = 1;

    for (let j = 0; j < place.length; j++) {
      const row = place[j];

      for (let k = 0; k < row.length; k++) {
        const current = row[k];

        if (current === "X" || current === "O") continue;

        let prev = "";
        for (let l = 0; l < 6; l++) {
          const ny = j + dy[l];
          const nx = k + dx[l];

          if (ny >= 5 || nx >= 5) {
            prev = "";
            continue;
          }

          const next = place[ny][nx];

          if (l === 0 || l === 4) {
            if (next === "P") {
              flag = 0;
              break;
            } else if (next === "X") {
              l++;
            }
            prev = next;
          } else if (l === 1 || l === 5) {
            if (prev !== "X" && next === "P") {
              flag = 0;
              break;
            }
          } else {
            if (next === "P") {
              const up = place[ny - dy[l]][nx];
              const side = place[ny][nx - dx[l]];

              if (up !== "X" || side !== "X") {
                flag = 0;
                break;
              }
            }
          }
        }
        if (flag === 0) break;
      }
      if (flag === 0) break;
    }
    answer.push(flag);
  }

  return answer;
}
