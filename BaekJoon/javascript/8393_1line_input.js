//한 줄 입력

let fs = require("fs");
// 백준에서 /dev/stdin을 사용하여 확인
let input = fs.readFileSync("/dev/stdin").toString().split(" ");

let num = parseInt(input);
let sum = 0;

for (let i = 1; i <= num; i++) {
  sum += i;
}

console.log(sum);
