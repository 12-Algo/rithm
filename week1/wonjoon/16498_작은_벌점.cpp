#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bs(int minNum, int maxNum, vector<int> &v){
  int left = 0;
  int right = v.size() - 1;
  
  while(left < right){
    int mid = (left + right) / 2;
    
    if(v[mid] < maxNum){
      left = mid+1;
    }else{
      right = mid;
    }
  }
  
  if(v[right] > maxNum){
    if(right == 0){
      return false;
    }else{
      right--;
    }
  }
  
  if(v[right] >= minNum){
    return true;
  }else{
    return false;
  }
}

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int ans = 200000000;
  
  vector<int> v1, v2, v3;
  
  for(int i=0; i<A; i++){
    int x;
    cin >> x;
    v1.push_back(x);
  }
  
  for(int i=0; i<B; i++){
    int x;
    cin >> x;
    v2.push_back(x);
  }
  
  for(int i=0; i<C; i++){
    int x;
    cin >> x;
    v3.push_back(x);
  }
  
  // A, B, C 카드 배열 오름차순 정렬
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  sort(v3.begin(), v3.end());
  
  // 두 값을 완전 탐색으로 정하고 나머지 배열에서 그 사이 값이 존재하는지 확인한 후 최소값 구하기
  for(int i : v1){
    for(int j : v2){
      int maxNum = max(i, j);
      int minNum = min(i, j);
      
      if(maxNum - minNum >= ans){
        continue;
      }
      
      if(bs(minNum, maxNum, v3)){
        ans = min(ans, maxNum - minNum);
      }
    }
  }
  
  for(int i : v2){
    for(int j : v3){
      int maxNum = max(i, j);
      int minNum = min(i, j);
      
      if(maxNum - minNum >= ans){
        continue;
      }
      
      if(bs(minNum, maxNum, v1)){
        ans = min(ans, maxNum - minNum);
      }
    }
  }
  
  for(int i : v1){
    for(int j : v3){
      int maxNum = max(i, j);
      int minNum = min(i, j);
      
      if(maxNum - minNum >= ans){
        continue;
      }
      
      if(bs(minNum, maxNum, v2)){
        ans = min(ans, maxNum - minNum);
      }
    }
  }
  
  cout << ans << '\n';
  
  return 0;
}