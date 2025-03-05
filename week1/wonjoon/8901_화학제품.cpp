#include <iostream>
using namespace std;

int main() {
  int T;
  int A, B, C, AB, BC, CA;
  
  cin >> T;
  
  for(int tc=0; tc<T; tc++){
    int ans = 0;
    cin >> A >> B >> C >> AB >> BC >> CA;
    
    // A,B를 사용할 개수가 결정이 되면 자동으로 C를 몇개 사용할지 확정됨
    for(int i=0; i<=min(A, B); i++){
      int cnt = i * AB;
      int a = A - i;
      int b = B - i;
      int c = C;
      
      // 가격이 큰 것 부터 처리
      if(CA > BC){
        while(a > 0 && c > 0){
          cnt += CA;
          a--;
          c--;
        }
        while(b > 0 && c > 0){
          cnt += BC;
          b--;
          c--;
        }
      }else{
        while(b > 0 && c > 0){
          cnt += BC;
          b--;
          c--;
        }
        while(a > 0 && c > 0){
          cnt += CA;
          a--;
          c--;
        }
      }
      
      ans = max(ans, cnt);
    }
    
    cout << ans << '\n';
  }
  
  return 0;
}