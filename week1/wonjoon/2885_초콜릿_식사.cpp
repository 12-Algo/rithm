#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int t = 1;
  while(t < N){
    t *= 2;
  }
  
  int a = t;
  int b = 0;
  
  if(t == N){ // N이 2의 제곱수와 일치하는 경우
    cout << a << " " << b << '\n';
    return 0;
  }
  
  t /= 2;
  
  // 큰 초콜릿 부터 처리한 후 2로 나누면서 N이 0이 될때까지 반복
  while(N > 0){
    if(N >= t){
      N -= t;
    }
    b++;
    t /= 2;
  }
  
  cout << a << " " << b << '\n';
  
  return 0;
}