## 📌 스터디 규칙

- 매일 1시~4시 스터디 시작
- 주석 달기 권장

<br>

## 📌 진행 방식

- 매일 2문제 선정
- 2시간 내 문제 풀고 PR 올리기!
- 2시간 내 풀지 못할 경우 추가 시간 30분 

<br>

<br>

## ✅ PR 방법

### 1. main branch에서 pull

![image](https://github.com/user-attachments/assets/45469213-33a5-40e2-86e7-7836df248ecb)

- `main` branch에서 `git pull` 명령 실행하여 `main` branch와 local 동기화

<br>

### 2. 자신의 branch로 변경

![image](https://github.com/user-attachments/assets/f52240d8-13dd-46e3-b496-c74c4c384ce4)

- `git switch -c name` 명령으로 자신의 브랜치 생성

<br>

### 3. directory 및 file 생성

![image](https://github.com/user-attachments/assets/24fd9f4d-12e3-45a6-aa22-14ff4bf383f2)

- local repository의 최상위 경로에 `스터디 날짜`/`자신의 브랜치 이름`으로 directory 생성 후,<br>`문제번호_문제이름` 파일에 자신의 코드를 저장합니다.

<br>

### 4. remote repository에 push

- `git add .`

- `git commit -m '스터디날짜 자기이름'` 👉 ex) `git commit -m '0723 최수현'`

- `git push origin 자기브랜치` 👉 ex) `git push origin suhyun`

‼️ 중간중간 `git status` 명령으로 자신이 수정/추가한 파일이 올라가는지 확인해주세요!

<br>

### 5. PR 남기기

![image](https://github.com/user-attachments/assets/66448a9b-820d-4047-9299-c74378411825)

- GitHub에서 PR 생성

![image](https://github.com/user-attachments/assets/745844d1-08c7-4457-a430-ebe13be6b6fc)

- PR title은 커밋 메세지 그대로 합니다.

<br>

![image](https://github.com/user-attachments/assets/8a93af9e-9506-4f1a-bd45-963faf3e2ac2)

PR 생성 완료~✨

<br>

### 6. branch 삭제

![image](https://github.com/user-attachments/assets/daac5a92-e50a-419b-bf52-1fcfa5e40805)

- PR merge한 후에 자신의 branch 삭제해주세요~!

![image](https://github.com/user-attachments/assets/2e2d1d1c-5438-4f01-ad41-42b19cd5611e)

- 로컬에서도 main branch로 이동(`git switch main`) 후 자신의 branch 삭제해주세요.






