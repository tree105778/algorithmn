#include <bits/stdc++.h>

using namespace std;

int k;
char op[10];
int selected[10];
string s, max_ret = "0000000000", min_ret = "9999999999";

void dfs(int n, int cur) {
  selected[cur] = 1;
  s += (cur + '0');
  if (n == k) {
    max_ret = max(max_ret, s);
    min_ret = min(min_ret, s);
    s.pop_back();
    selected[cur] = 0;
    return;
  }

  for(int i = 0; i < 10; i++) {
    if (op[n] == '<') {
      if (!selected[i] && (cur < i)) {
        dfs(n + 1, i);
      }
    } else if (op[n] == '>') {
      if (!selected[i] && (cur > i)) {
        dfs(n + 1, i);
      }
    }
  }
  selected[cur] = 0;
  s.pop_back();
}

int main() {
  cin >> k;

  for(int i = 0; i < k; i++) {
    cin >> op[i];
  }


  for(int i = 0; i < 10; i++) {
    dfs(0, i);
  }
  cout << max_ret << '\n' << min_ret;
}