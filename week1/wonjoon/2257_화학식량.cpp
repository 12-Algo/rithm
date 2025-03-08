#include <iostream>
#include <map>
#include <stack>
using namespace std;

int main() {
  string s;
  cin >> s;
  char c;
  int ans = 0;
  
  stack<int> st;
  
  // map 자료구조를 통해 미리 값 할당
  map<char, int> m;
  m['H'] = 1;
  m['C'] = 12;
  m['O'] = 16;
  
  for(int i=0; i<s.length(); i++){
    c = s[i];
    if(c == '('){ // stack 에 -1 푸쉬
      st.push(-1);
    }else if(c == ')'){ // stack 에서 -1을 만날때까지 값 더하기
      int s = 0;
      while(st.top() != -1){
        s += st.top();
        st.pop();
      }
      st.pop();
      st.push(s);
    }else if(c >= '2' && c <= '9'){ // stack 가장 최근 값에 곱하기
      st.top() *= c - '0';
    }else{
      st.push(m[c]);
    }
  }
  
  
  while(!st.empty()){
    ans += st.top();
    st.pop();
  }
  
  cout << ans << '\n';
  
  return 0;
}