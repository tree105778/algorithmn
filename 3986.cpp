#include <bits/stdc++.h>

using namespace std;

// 뭐가 틀린 지 잘 모르겠다 맞왜틀!!

// 틀린 이유 : 스택 사이즈를 2로 제한했기 때문에

int n, cnt;
string s;

bool is_good_word(string& s) {
  stack<char> st;
  for(char ch : s) {
    if (st.empty()) st.push(ch);
    else if (!st.empty() && st.top() != ch) st.push(ch);
    else if (st.top() == ch) st.pop();
  }
  return st.empty();
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s;
    if (is_good_word(s)) {
      cnt++;
    }
  }
  cout << cnt;
}