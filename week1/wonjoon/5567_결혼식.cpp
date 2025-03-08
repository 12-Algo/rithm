#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

vector<vector<int>> v(501); // ArrayList와 똑같음
bool visited[501];
int ans = 0;

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    // BFS로 Depth가 2인 친구까지 탐색
    queue<pair<int, int>> q;
    q.push({1, 0});

    while(!q.empty()){
        int x = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(visited[x] || depth == 3){
            continue;
        }

        visited[x] = true;
        ans++;

        for(int y : v[x]){
            if(!visited[y]){
                q.push({y, depth+1});
            }
        }
    }

    cout << ans-1 << '\n';
}