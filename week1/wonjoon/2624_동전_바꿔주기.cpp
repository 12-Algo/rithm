#include <iostream>
using namespace std;

int T, K;
int p[100];
int c[100];
int dp[10001];

int main(){
    cin >> T >> K;
    for(int i=0; i<K; i++){
        cin >> p[i] >> c[i];
    }

    dp[0] = 1;

    for(int i=0; i<K; i++){
        for(int j=T; j>=0; j--){
            for(int t=1; t<=c[i]; t++){
                if(j - p[i] * t >= 0){
                    dp[j] += dp[j-p[i]*t];
                }
            }
        }
    }

    cout << dp[T];
}
