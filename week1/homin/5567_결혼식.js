const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const [a, b, ...inputs] = input;
  console.log(
    solution(
      Number(a),
      Number(b),
      inputs.map((e) => e.split(" ").map(Number))
    )
  );
});

const solution = (a, b, inputs) => {
  const arr = Array.from({ length: a + 1 }, () => new Array());
  inputs.forEach((e) => {
    const [from, to] = e;
    arr[from].push(to);
    arr[to].push(from);
  });

  const participant = Array.from({ length: a + 1 }).fill(0);
  participant[1] = 1;

  arr[1].forEach((e) => {
    participant[e] = 1;

    arr[e].forEach((i) => {
      participant[i] = 1;
    });
  });

  return participant.filter((e) => e).length - 1;
};
