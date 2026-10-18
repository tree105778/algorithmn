#include <bits/stdc++.h>

using namespace std;

int n;
string s;
bool flag;
int main() {
  cin.tie(NULL); //입출력 묶음 해제
  ios_base::sync_with_stdio(false);

  cin >> n;
  for(int i = 0; i < n; i++) {
    stack<char> st;
    cin >> s;

    flag = true;
    for(auto ch : s) {
      if (ch == '(') st.push(ch);
      else if (ch == ')') {
        if (st.empty()) {
          flag = false;
          break;
        } else st.pop();
      }
    }
    if (st.size()) flag = false;
    if (flag) {
      cout << "YES" << '\n';
    } else cout << "NO" << '\n';
  }
}