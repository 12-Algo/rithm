#include <iostream>
using namespace std;

char arr[1000][1000];
int ans = 0;
int N, M;

void countGallery(bool isRow){
  /*
  현재 줄과 아래줄을 비교하면서 값이 서로 다르다면 
  얼마나 연속적인지 계산 후 cnt 값 증가
  */
  for(int i=0; i< (isRow ? N-1 : M-1); i++){
    pair<char, char> prev = {' ' ,' '};
    int cnt = 0;
    for (int j = 0; j < (isRow ? M : N); j++) {
      char a = isRow ? arr[i][j] : arr[j][i];
      char b = isRow ? arr[i+1][j] : arr[j][i+1];
      
      if(a == b){
        ans += cnt/2;
        cnt = 0;
        prev = {' ', ' '};
      }else{ // 값이 달라도 'X.', '.X' 인 경우 판단 필요
        if(prev.first == a && prev.second == b){
          cnt++;
        }else{
          ans += cnt/2;
          cnt = 1;
          prev = {a, b};
        }
      }
      
    }
  }
}

int main() {
  cin >> N >> M;
  
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> arr[i][j];
    }
  }
  
  countGallery(true);
  countGallery(false);
  
  cout << ans << '\n';
  
  return 0;
}