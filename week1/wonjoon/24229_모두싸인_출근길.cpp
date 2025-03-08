#include <iostream>
#include <queue>
using namespace std;

int N;

int main() {
  cin >> N;
  
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<pair<int, int>> v;
  
  for(int i=0; i<N; i++){
    int L, R;
    cin >> L >> R;
    
    pq.push({L, R});
  }
  
  int ind = -1;
  
  // 우선 순위큐로 좌표 오름차순 정렬 후 인접해 있는 구간이 있으면 합치기
  while(!pq.empty()){
    int a = pq.top().first;
    int b = pq.top().second;
    pq.pop();
    
    if(v.empty()){
      v.push_back({a, b});
      ind++;
    }else{
      if(v[ind].second >= a){
        v[ind].second = max(v[ind].second, b);
      }else{
        v.push_back({a, b});
        ind++;
      }
    }
  }
  
  // 구간을 순회할때 마다 갈 수 있는 최대 거리 k를 계산
  int ans = v[0].second;
  int k = v[0].second * 2 - v[0].first;
  
  for(int i=1; i<v.size(); i++){
    int a = v[i].first;
    int b = v[i].second;
    
    if(k >= a){
      k = max(k, 2*b-a);
      ans = b;
    }else{
      break;
    }
  }
  
  cout << ans << '\n';
}