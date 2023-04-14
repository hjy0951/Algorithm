/*
2021 KAKAO BLIND RECRUITMENT
메뉴 리뉴얼
: 손님이 주문한 메뉴 현황을 보고 2명 이상이 주문한 메뉴 조합중 가장 많이 주문된 것을 코스로 지정하라.

- 조합을 이용하여 메뉴 조합을 추출하여 저장하고, 코스 길이에 따라 나누어 저장
- 모든 메뉴 현황에 대한 메뉴 조합을 확인하고 가장 많이 주문된 조합을 코스로 추출
*/

function solution(orders, course) {
  var answer = [];
  let courseMap = {};
  course.forEach((len) => {
    courseMap[len] = {};
  });

  orders.forEach((order) => {
    for (let i = 0; i < course.length; i++) {
      const currentLen = course[i];
      getCourses(order.split(""), currentLen).forEach((menu) => {
        const isExistMenu = courseMap[currentLen][menu];

        if (isExistMenu === undefined) courseMap[currentLen][menu] = 1;
        else courseMap[currentLen][menu]++;
      });
    }
  });
  let sortArr;
  course.forEach((len) => {
    sortArr = [];
    const current = courseMap[len];
    for (const menu in current) {
      sortArr.push([current[menu], menu]);
    }
    sortArr.sort((a, b) => b[0] - a[0]);
    let maxCount = 0;
    for (let i = 0; i < sortArr.length; i++) {
      const [count, menu] = sortArr[i];
      if (maxCount === 0) {
        if (count === 1) break;
        maxCount = count;
        answer.push(menu);
      } else {
        if (maxCount === count) answer.push(menu);
        else break;
      }
    }
  });
  answer.sort();

  return answer;
}

function getCourses(arr, selectNumber) {
  const results = [];
  if (selectNumber === 1) return arr.map((el) => [el]);
  // n개중에서 1개 선택할 때(nC1), 바로 모든 배열의 원소 return

  arr.forEach((fixed, index, origin) => {
    const rest = origin.slice(index + 1);
    // 해당하는 fixed를 제외한 나머지 뒤
    const combinations = getCourses(rest, selectNumber - 1);
    // 나머지에 대해서 조합을 구한다.
    const attached = combinations.map((el) => [fixed, ...el].sort().join(""));
    //  돌아온 조합에 떼 놓은(fixed) 값 붙이기
    results.push(...attached);
    // 배열 spread syntax 로 모두다 push
  });
  return results; // 결과 담긴 results return
}
