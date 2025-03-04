const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  console.log(solution(input[0]));
});

const obj = {
  H: 1,
  O: 16,
  C: 12,
};

const number = [2, 3, 4, 5, 6, 7, 8, 9];

const solution = (str) => {
  const stack = [];

  const arr = str.split("");

  arr.forEach((e) => {
    if (e === "(") {
      stack.push(e);
    } else if (e === ")") {
      let temp = 0;
      while (stack.length) {
        const now = stack.pop();
        if (now === "(") break;
        temp += now;
      }
      stack.push(temp);
    } else if (obj[e]) {
      stack.push(obj[e]);
    } else {
      stack.push(stack.pop() * e);
    }
  });

  return stack.reduce((acc, cur) => acc + cur, 0);
};
