#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> v;
  vector<int> d; // 간격이 x인 배 배열
  
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    v.push_back(x);    
  }
  
  int k = v[1] - v[0];
  d.push_back(k);
  
  // d 배열에 없는 간격의 배가 나타나면 d 배열에 추가
  for(int i : v){
    bool flag = true;
    for(int j : d){
      if((i-1) % j == 0){
        flag = false;
        break;
      }
    }
    if(flag){
      d.push_back(i-1);
    }
  }
  
  cout << d.size() << '\n';
  
}