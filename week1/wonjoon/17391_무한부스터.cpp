#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[300][300];
bool visited[300][300];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
bool flag = false;

int main() {
    cin >> N >> M;
    int ans = 0;
    
    // 격자 입력
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        cin >> arr[i][j];
      }
    }
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    
    // 큐를 이용한 BFS 수행
    while(!q.empty()){
      int p = q.size();
      ans++;
      for(int n=0; n<p; n++){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(visited[x][y]){
          continue;
        }
        
        if(x == N-1 && y == M-1){
          flag = true;
          break;
        }
        
        visited[x][y] = true;
        
        for(int i=0; i<2; i++){
          for(int t=1; t<=arr[x][y]; t++){
            int ax = x + dx[i] * t;
            int ay = y + dy[i] * t;
            
            if(ax < 0 || ax >= N || ay < 0 || ay >= M || visited[ax][ay]){
              continue;
            }
            
            q.push({ax, ay});
          }
        }
      }
      if(flag){
        break;
      }
    }
    
    cout << ans-1 << '\n';

    return 0;
}