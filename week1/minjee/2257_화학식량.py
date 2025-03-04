WEIGHT = {"H": 1, "C": 12, "O": 16}

formula = input()
idx = 0
stack = []

while idx < len(formula):
    # 현재 문자가 CHO 중 하나
    if formula[idx] in WEIGHT:
        stack.append(WEIGHT[formula[idx]])
    # 현재 문자가 숫자 (앞에 소괄호 있으면 여기서 처리 안함)라면 직전 원자량에 곱셈 처리
    elif formula[idx].isdigit():
        stack[-1] *= int(formula[idx])
    # 현재 문자가 여는 소괄호
    elif formula[idx] == "(":
        stack.append("(")
    # 현재 문자가 닫는 소괄호호
    elif formula[idx] == ")":
        # ( 만나기 전까지 소괄호 내부 총합 temp에 담으면서 stack에서 pop
        temp = 0
        while stack and stack[-1] != "(":
            temp += stack.pop()
        if stack and stack[-1] == "(":
            stack.pop()
        # ) 뒤에 숫자값이 있을 경우 소괄호 내부 합의 곱셈 처리값
        multiple = 1
        if idx < len(formula) - 1 and formula[idx + 1].isdigit():
            multiple = int(formula[idx + 1])
            idx += 1
        stack.append(temp * multiple)
    idx += 1

print(sum(stack))