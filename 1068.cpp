#include <bits/stdc++.h>

using namespace std;

int n, num, root, del, ret;
vector<vector<int>> tree;
int visited[60];
void dfs(int n) {
  visited[n] = 1;
  if (n == del) return;
  if (!tree[n].size()) {
    ret++;
    return;
  }

  for(auto& i : tree[n]) {
    if (tree[n].size() == 1 && i == del) {
      ret++;
      return;
    }
    if (!visited[i]) {
      dfs(i);
    }
  }
}
int main() {
  cin >> n;

  tree.reserve(n);

  for(int i = 0; i < n; i++) {
    cin >> num;
    if (num == -1) {
      root = i;
      continue;
    }

    tree[num].push_back(i);
  }

  cin >> del;

  dfs(root);

  cout << ret;
}