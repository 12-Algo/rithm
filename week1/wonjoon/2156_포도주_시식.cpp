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

    for(int i=1; i<=N; i++){
        dp[i][0] = max(max(dp[i-1][2], dp[i-1][0]), dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + arr[i];
        dp[i][2] = dp[i-1][1] + arr[i];
    }
    
    cout << max(max(dp[N][0], dp[N][1]), dp[N][2]) << '\n';
}
