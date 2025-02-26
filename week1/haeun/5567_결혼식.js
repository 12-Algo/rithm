const fs = require("fs");
const [[N], [M], ...input] = fs
  .readFileSync("./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((line) => line.split(" ").map(Number));

const edges = Array.from({ length: N + 1 }, () => []);
for (const [from, to] of input) {
  edges[from].push(to);
  edges[to].push(from);
}
console.log(bfs(1));

function bfs(me) {
  const visited = new Array(N + 1).fill(0);
  const queue = [[me, 1]];

  let head = 0;
  let count = 0;

  visited[me] = 1;

  while (queue.length > head) {
    const [n, depth] = queue[head++];
    if (depth > 2) break;

    for (const nn of edges[n]) {
      if (!visited[nn]) {
        visited[nn] = 1;
        count++;
        queue.push([nn, depth + 1]);
      }
    }
  }

  return count;
}
