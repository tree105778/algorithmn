#include <bits/stdc++.h>

using namespace std;

int n, k, learned, ret;
string s;
int words[55];
void dfs(int idx, int cnt) {
  if (cnt == k) {
    int cur = 0;
    for(int i = 0; i < n; i++) {
      if ((words[i] & learned) == words[i]) cur++;
    }
    ret = max(ret, cur);
    return;
  }

  for(int i = idx; i < 26; i++) {
    if (learned & (1 << i)) continue;
    learned |= (1 << i);
    dfs(i + 1, cnt + 1);
    learned &= ~(1 << i);
  }
}
int main() {
  cin >> n >> k;

  for(int i = 0; i < n; i++) {
    cin >> s;
    for(auto ch: s) {
      words[i] |= (1 << (ch - 'a'));
    }
  }

  if (k < 5) {
    cout << 0 << '\n';
    return 0;
  }


  learned |= (1 << ('a' - 'a'));
  learned |= (1 << ('n' - 'a'));
  learned |= (1 << ('t' - 'a'));
  learned |= (1 << ('i' - 'a'));
  learned |= (1 << ('c' - 'a'));

  dfs(0, 5);
  cout << ret;
}