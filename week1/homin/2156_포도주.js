const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const [num, ...inputs] = input;
  console.log(solution(inputs.map(Number)));
});

const solution = (arr) => {
  let zero = 0;
  let first = 0;
  let second = 0;

  // [3,6,7,8] 인 경우
  // [3, 0] , [6, 0] , [7, 0] , [8, 0]
  // 이라고 가정한다.

  // 첫번째 에서 두번째로 내려갈 때
  // 2번 선택된 경우는 [3, 6] , 1번 선택된 경우는 [0, 6] , 다시 초기화 된 경우는 [3, 0] 일 것이다.

  // 이런 과정을 반복한다고 생각했을 떄 입력받은 e와 0을 기존의 최대값에 더해주면 된다.

  // 0을 더해주는 이유는 다시 2번을 선택하며 나아갈 수 있는 상태로 만드는 과정으로 만드는것이다.

  arr.forEach((e) => {
    // zero : 0으로 초기화 된 직후 , first : 한번 사용된 애 , second : 두번 사용된 애
    const tempZero = zero;
    const tempFirst = first;
    const tempSecond = second;

    zero = Math.max(tempFirst + 0, tempSecond + 0);
    first = Math.max(tempFirst, tempZero + e);
    second = Math.max(tempSecond, tempFirst + e);
  });

  return Math.max(...[zero, first, second]);
};
