#include <bits/stdc++.h>

using namespace std;

int n, max_len;
string s;
stack<int> st;
int main() {
  cin >> n >> s;

  st.push(-1);
  for(int i = 0; i < n; i++) {
    if (s[i] == '(') st.push(i);
    else {
      st.pop();
      if (st.empty()) st.push(i);
      else max_len = max(max_len, i - st.top());
    }
  }

  cout << max_len;
}