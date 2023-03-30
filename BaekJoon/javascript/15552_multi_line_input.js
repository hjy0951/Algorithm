//여러 줄 입력

let fs = require("fs");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");
let input = fs.readFileSync("./ex.txt").toString().split("\n");

const answers = [];

for (let i = 1; i < input.length; i++) {
  if (input[i] !== "") {
    const [a, b] = input[i].split(" ").map(Number);
    answers.push(a + b);
  }
}

console.log(answers.join("\n"));
