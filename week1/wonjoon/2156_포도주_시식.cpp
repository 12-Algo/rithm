#include <iostream>
using namespace std;

int arr[10000];
int dp[10001][3];

int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    dp[0][1] = arr[0];

    // dp[n][k] -> n번째일때 k개 연속중일 경우 최대값
    for(int i=1; i<=N; i++){
        // 현재 포도주를 선택안할 경우 n-1번째 최대 경우값과 같음
        dp[i][0] = max(max(dp[i-1][2], dp[i-1][0]), dp[i-1][1]);

        // 1개 혹은 2개를 연속 선택할 경우 n-1번째에서 0개, 1개가 연속된 경우 값에 현재 포도주 양을 추가
        dp[i][1] = dp[i-1][0] + arr[i];
        dp[i][2] = dp[i-1][1] + arr[i];
    }
    
    cout << max(max(dp[N][0], dp[N][1]), dp[N][2]) << '\n';
}
