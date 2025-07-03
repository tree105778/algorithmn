#include <bits/stdc++.h>

using namespace std;

string s;
int main() {
  getline(cin, s);
  while (s != ".") {
    bool flag = true;
    stack<char> st;

    for(auto c : s) {
      switch (c) {
        case '(' :
          st.push(c);
          break;
        case '[':
          st.push(c);
          break;
        case ')' :
          if (st.empty() || st.top() != '(') {
            flag = false;
            break;
          }
          st.pop();
          break;
        case ']' :
          if (st.empty() || st.top() != '[') {
            flag = false;
            break;
          }
          st.pop();
          break;
      }
      if (!flag) break;
    }
    if (flag && st.empty()) cout << "yes" << '\n';
    else cout << "no" << '\n';
    getline(cin, s);
  }

  return 0;  
}