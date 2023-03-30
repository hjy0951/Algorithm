/*
2018 KAKAO BLIND RECRUITMENT
[1차] 캐시 - lv2
: LRU 알고리즘을 사용하여 캐시 아이템을 관리하는 문제

- LRU를 cache hit 수를 priority로 관리하는 정책으로 잘못 이해하여 시간이 좀 걸림.
- splice를 사용해야했는데, slice라고 오타를 내 디버깅에 많은 시간을 사용함.

-> 문제를 꼼꼼히 읽고 종이에 먼저 작성해보자.
*/

function solution(cacheSize, cities) {
  var answer = 0;
  const cache = [];

  if (cacheSize === 0) return cities.length * 5;

  for (let i = 0; i < cities.length; i++) {
    const currentCity = cities[i].toLowerCase();
    let findIdx = -1;

    for (let i = 0; i < cache.length; i++) {
      if (cache[i] === currentCity) {
        findIdx = i;
        break;
      }
    }

    if (findIdx >= 0) {
      cache.splice(findIdx, 1);
      cache.unshift(currentCity);
      answer += 1;
    } else {
      if (cacheSize <= cache.length) cache.pop();
      cache.unshift(currentCity);
      answer += 5;
    }
  }
  return answer;
}
/*
3 ["a", "b", "c", "a"] 16
3 ["a", "b", "c", "a", "b"] 17
3 ["a", "b", "c", "a", "b", "d", "c"] 27
*/
