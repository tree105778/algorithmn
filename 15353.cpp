#include <bits/stdc++.h>

using namespace std;

stack<int> a, b;
stack<int> st;
bool carried;
int main() {
  string s1, s2;
  cin >> s1 >> s2;

  for(auto& ch: s1) a.push(ch - '0');
  for(auto& ch: s2) b.push(ch - '0');

  while (!a.empty() && !b.empty()) {
    int ret = a.top() + b.top() + carried;
    a.pop(); b.pop();
    if (ret >= 10) carried = 1;
    else carried = 0;
    st.push(ret % 10);
  }

  while (!a.empty()) {
    int ret = a.top() + carried;
    if (ret >= 10) carried = 1;
    else carried = 0;
    st.push(ret % 10);
    a.pop();
  }

  while (!b.empty()) {
    int ret = b.top() + carried;
    if (ret >= 10) carried = 1;
    else carried = 0;
    st.push(ret % 10);
    b.pop();
  }

  if (carried) cout << '1';
  while (!st.empty()) {
    cout << st.top();
    st.pop();
  }
}