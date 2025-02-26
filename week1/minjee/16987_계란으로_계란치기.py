# 입력값 처리 (N 최대 8 / 내구도 최대 300 / 무게 최대 300)
N = int(input())
eggs = [list(map(int, input().split())) for i in range(N)]

# 1. 정렬 진행 (내구도 내림 차순, 무게 내림 차순, 순서 오름 차순)
# 2. 현 배열 중 인덱스 값이 가장 작은 것과 가장 끝 요소 깨기 진행 -> 끝 요소 pop
# 3. 현 배열 중 인덱스 값이 가장 작은 것이 가장 끝일 경우 끝에서 두번째 계란이랑 깨기 진행
# ...? 계란 들고 도장 깨기가 아니라면 이거 아님
# sorted_eggs = sorted(eggs, key=lambda x: (-x[1], -x[0], x[2]))


# print(eggs, sorted_eggs)
