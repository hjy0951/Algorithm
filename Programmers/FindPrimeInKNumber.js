/*
2022 KAKAO BLIND RECRUITMENT
k진수에서 소수 개수 구하기
: 조건으로 주어진 소수의 규칙을 만족하는 수가 몇개 존재하는지 구하라

- 에라토스테네스의 체를 이용했더니 1번만 실패.
- 바킹독 블로그를 통해 알아보니 n = 797161, k = 3인 경우, 부분 수 1111111111111(≓ 2^40) 케이스 존재
- 따라서 에라토스테네스의 체를 이용할 경우 시간초과가 남
*/

function solution(n, k) {
  var answer = 0;
  const splits = n.toString(k).split("0");
  for (let i = 0; i < splits.length; i++) {
    const current = splits[i];
    if (current.length === 0) continue;

    answer += isPrime(current);
  }
  return answer;
}

function isPrime(number) {
  if (number <= 1) return 0;
  for (let i = 2; i * i <= number; i++) {
    if (number % i === 0) return 0;
  }
  return 1;
}

// function makePrimes() {
//     const maxNum = 1000001;
//     const primes = new Array(maxNum).fill(1);
//     primes[0] = 0;
//     primes[1] = 0;

//     for(let i = 2 ; i < maxNum ; i++) {
//         if (primes[i] !== 1) continue;

//         let cur = i;
//         while (cur < maxNum) {
//             cur += i;
//             primes[cur] = 0;
//         }
//     }
//     return primes;
// }
