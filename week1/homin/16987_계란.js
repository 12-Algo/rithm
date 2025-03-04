const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const [a, ...inputs] = input;
  console.log(
    solution(
      Number(a),
      inputs.map((e) => e.split(" ").map(Number))
    )
  );
});

const solution = (a, inputs) => {
  let max = 0;

  const dfs = (i) => {
    // 가장 오른쪽이면 중단

    if (i === a) {
      max = Math.max(max, inputs.filter((e) => e[0] <= 0).length);
      return;
    }

    let hasIntactEgg = false;

    for (let item = 0; item < a; item++) {
      if (i !== item && inputs[i][0] > 0) {
        const [오른손내구도, 오른손무게] = inputs[item];
        const [왼손내구도, 왼손무게] = inputs[i];

        if (왼손내구도 <= 0) {
          dfs(i + 1);
          return;
        }

        if (오른손내구도 <= 0) {
          continue;
        }

        hasIntactEgg = true;

        inputs[i] = [왼손내구도 - 오른손무게, 왼손무게];
        inputs[item] = [오른손내구도 - 왼손무게, 오른손무게];

        dfs(i + 1);

        // item 원복
        inputs[i] = [왼손내구도, 왼손무게];
        inputs[item] = [오른손내구도, 오른손무게];
      }
    }

    if (!hasIntactEgg) {
      dfs(i + 1);
    }
  };

  dfs(0);

  return max;
};
