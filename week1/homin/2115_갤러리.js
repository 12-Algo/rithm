const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const [nm, ...inputs] = input;
  const [n, m] = nm.split(" ").map(Number);

  console.log(solution(n, m, inputs));
});

const solution = (n, m, inputs) => {
  // xx/.. 와 .x / .x 와  x. / x. 와 ../xx 얘네 네바퀴 순차탐색
  const 왼쪽위 = ["X", ".", "X", "."];
  const 오른쪽위 = ["X", "X", ".", "."];
  const 왼쪽아래 = [".", ".", "X", "X"];
  const 오른쪽아래 = [".", "X", ".", "X"];

  const graph = inputs.map((e) => e.split(""));

  let count = 0;

  for (let i = 0; i < 4; i++) {
    const visited = Array.from({ length: n + 1 }, () =>
      new Array(m + 1).fill(false)
    );
    // (1,1) 부터 (n,m) 탐색
    for (let x = 1; x < n; x++) {
      for (let y = 1; y < m; y++) {
        if (
          graph[x - 1][y - 1] === 왼쪽위[i] &&
          graph[x][y - 1] === 왼쪽아래[i] &&
          graph[x - 1][y] === 오른쪽위[i] &&
          graph[x][y] === 오른쪽아래[i] &&
          visited[x][y - 1] === false &&
          visited[x][y] === false &&
          visited[x - 1][y] === false &&
          visited[x - 1][y - 1] === false
        ) {
          visited[x][y - 1] = true;
          visited[x][y] = true;
          visited[x - 1][y] = true;
          visited[x - 1][y - 1] = true;
          count += 1;
        }
      }
    }
  }
  return count;
};
