#include <iostream>
using namespace std;

int N;
int s[8];
int w[8];
int ans = 0;

void dfs(int i, int cnt){
    if(i == N){ // 계란을 더 집을 수 없을 때 종료
        ans = max(ans, cnt);
        return;
    }
    if(s[i] <= 0){ // 집은 계란이 이미 깨진 계란인 경우
        dfs(i+1, cnt);
    }else{
        bool ch = true;
        for(int j=0; j<N; j++){
            if(s[j] <= 0 || i==j){ // 다른 계란이 이미 깨져있는 경우 다른 계란 탐색
                continue;
            }
            ch = false;
            s[i] -= w[j];
            s[j] -= w[i];

            // 깨진 계란 수 만큼 cnt 증가
            if(s[i] <= 0 && s[j] <= 0){
                dfs(i+1, cnt+2);
            }else if(s[i] > 0 && s[j] > 0){
                dfs(i+1, cnt);
            }else{
                dfs(i+1, cnt+1);
            }
            
            s[i] += w[j];
            s[j] += w[i];
        }
        if(ch){ // 계란을 집었을때 때릴 계란이 없을 경우
            dfs(i+1, cnt);
        }
    }
}

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> s[i] >> w[i];
    }

    dfs(0, 0);
    cout << ans << '\n';
}