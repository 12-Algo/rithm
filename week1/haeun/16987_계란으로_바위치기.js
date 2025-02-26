const fs = require("fs");
const [[N], ...eggs] = fs
  .readFileSync("./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((line) => line.split(" ").map(Number));

let max = 0;
backtracking(0);
console.log(max);

function backtracking(start) {
  let flag = 0;

  if (start >= N) {
    let count = 0;
    for (const [s, w] of eggs) {
      if (s <= 0) count++;
    }

    max = Math.max(count, max);
    return;
  }

  if (eggs[start][0] <= 0) {
    backtracking(start + 1);
    return;
  }

  for (let i = 0; i < N; i++) {
    if (start === i || eggs[i][0] <= 0) continue;

    flag = 1;

    eggs[start][0] -= eggs[i][1];
    eggs[i][0] -= eggs[start][1];

    backtracking(start + 1);

    eggs[start][0] += eggs[i][1];
    eggs[i][0] += eggs[start][1];
  }

  if (!flag) backtracking(N);
}
