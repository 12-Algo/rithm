const fs = require("fs");
const [n, ...input] = fs
  .readFileSync("./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map(Number);

// 행은 포도주 개수, 열은 몇개 건너 마셨는지 각각 체크 위해 4개 생성

// 0: 전거랑 현재 포도주 모두 마신 경우
// 1: 하나 건너 마신 경우
// 2: 두개 건너 마신 경우
// 3: 세개 건너 마신 경우

const dp = Array.from({ length: n }, () => new Array(4).fill(0));

console.log(main());

function main() {
  let max = 0;

  // 초기값 선언 위해 n이 초기값 선언할 값들 보다 작은 경우 리턴

  if (n === 1) return input[0];
  if (n === 2) return input[0] + input[1];
  if (n === 3) return Math.max(input[0] + input[1], input[2]);

  // 0~3 초기값 선언

  dp[0][0] = input[0];
  dp[0][1] = input[0];
  dp[0][2] = input[0];
  dp[0][3] = input[0];

  dp[1][0] = input[0] + input[1];
  dp[1][1] = input[1];
  dp[1][2] = input[1];
  dp[1][3] = input[1];

  dp[2][0] = input[1] + input[2];
  dp[2][1] = input[0] + input[2];
  dp[2][2] = input[2];
  dp[2][3] = input[2];

  dp[3][0] = input[0] + input[2] + input[3];
  dp[3][1] = input[0] + input[1] + input[3];
  dp[3][2] = input[0] + input[3];
  dp[3][3] = input[3];

  // 하나, 두개, 세개 건너 마신 경우는 전체 경우 모두 후보가 될 수 있음 => 전체 중 Max + 현재
  // 건너뛰지 않고 마신 경우 3개가 연속되지 않도록 해야함  => 그 전 포도주를 마신 경우 제외하고 Max + 현재

  for (let i = 4; i < n; i++) {
    dp[i][0] = Math.max(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]) + input[i];
    dp[i][1] = Math.max(...dp[i - 2]) + input[i];
    dp[i][2] = Math.max(...dp[i - 3]) + input[i];
    dp[i][3] = Math.max(...dp[i - 4]) + input[i];
  }

  // 전체 중 가장 큰 값 찾기
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < 4; j++) {
      max = Math.max(max, dp[i][j]);
    }
  }

  return max;
}
