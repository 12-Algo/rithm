# 입력값 처리, 친구 관계 연결 리스트
N = int(input())
M = int(input())
rels = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    rels[a].append(b)
    rels[b].append(a)
# print("관계도", *rels, "-----", sep="\n")
# 상근이(1)의 친구와 친구의 친구 찾기
# 친구 친구가 친구일 경우 중복 있을 수 있으니 set 자료구조 이용
# 친구의 친구 목록에는 상근이가 반드시 있으니까 상근이 미리 깔고 감감
visitors = set()
visitors.add(1)
for friend in rels[1]:
    visitors.add(friend)
    for f_freiend in rels[friend]:
        visitors.add(f_freiend)
# 상근이 뺀 결과 확인
print(len(visitors) - 1)
