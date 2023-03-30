/*
연습문제
호텔 대실 - lv2
: 호텔 예약 시간이 주어지고, 필요한 최소 객실의 수를 return 하는 solution 함수를 완성.

- 문자열을 숫자로 분리하고, 이를 문제 조건에 맞게 다루는 것이 중요했던 문제
- 먼저, 고객이 이용할 예약 시간을 이용 시작 시간으로 정렬하고 예약 시간을 하나씩 불러옴
- 이용 종료 시간에는 청소 시간인 10분을 더해줌
- 만약 rooms 배열 안에 현재 이용 가능한 방이 있다면, 해당 방이 몇시까지 이용되는지 명시
- 이용 가능한 방이 없다면 새로 rooms 배열에 추가
- 매번 rooms 배열을 오름차순으로 정렬 (문자열이 시간 형태로 정해져 있기 때문에 일반적인 sort 함수를 사용하여 정렬 가능)
*/
function solution(book_time) {
  var answer = 0;
  let numOfRooms = 0;
  const rooms = [];

  book_time = sortBookTimes(book_time);

  book_time.forEach((time) => {
    let [start, end] = time;
    end = addRestTime(end);
    if (rooms.length === 0) {
      rooms.push(end);
      numOfRooms++;
    } else {
      const index = findRoomIndex(rooms, start);
      if (index >= 0) {
        rooms[index] = end;
      } else {
        rooms.push(end);
        numOfRooms++;
      }
    }

    rooms.sort((a, b) => {
      if (a > b) return 1;
      else if (a === b) return 0;
      else return -1;
    });
  });
  answer = numOfRooms;
  return answer;
}

function sortBookTimes(times) {
  return times.sort((a, b) => {
    if (a[0] > b[0]) return 1;
    else if (a[0] === b[0]) return 0;
    else return -1;
  });
}

function findRoomIndex(rooms, startTime) {
  for (let i = 0; i < rooms.length; i++) {
    if (rooms[i] <= startTime) return i;
  }
  return -1;
}

function addRestTime(endTime) {
  let [hour, minute] = endTime.split(":");
  hour = parseInt(hour);
  minute = parseInt(minute);
  minute += 10;
  if (minute > 60) {
    hour++;
    minute -= 60;
  }
  minute = minute < 10 ? `0${minute}` : `${minute}`;
  hour = hour < 10 ? `0${hour}` : `${hour}`;
  return [hour, minute].join(":");
}
