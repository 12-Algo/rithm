const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const [result, inputNumber, ...inputs] = input;
  console.log(solution(Number(result), Number(inputNumber), inputs));
});

const solution = (result, inputnumber, inputs) => {
  const coinTable = inputs.map((e) => e.split(" ").map(Number));
  const dp = Array.from({ length: result + 1 }).fill(0);
  dp[0] = 1;
  for (let i = 0; i < inputnumber; i++) {
    const coin = coinTable[i][0];
    const coinCount = coinTable[i][1];

    const tempDP = Array.from({ length: result + 1 }).fill(0);

    for (let j = 0; j < result + 1; j++) {
      // dp테이블 채우는 용도

      // 코인 갯수 (?) + 금액이랑 합쳤을 때 총액보다 낮을때만 증명
      for (let q = 0; j + q * coin < result + 1 && q <= coinCount; q += 1) {
        tempDP[j + q * coin] += dp[j];
      }
    }

    for (let j = 0; j < result + 1; j++) {
      dp[j] = tempDP[j];
    }
  }

  return dp[result];
};
