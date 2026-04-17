#include <bits/stdc++.h>

using namespace std;

int t, n, temp, a, b, ret;
int mp[1005][1005];
int visited[1005];

void dfs(int start) {
  visited[start] = 1;
  ret++;
  for(int i = 1; i <= n; i++) {
    if (mp[start][i] && !visited[i]) dfs(i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  for(int i = 0; i < t; i++) {
    cin >> n >> temp;
    ret = 0;
    memset(mp, 0, sizeof(mp));
    memset(visited, 0, sizeof(visited));
    for(int j = 0; j < temp; j++) {
      cin >> a >> b;
      mp[a][b] = 1;
      mp[b][a] = 1;
    }

    if (temp + 1 != n) {
      cout << "graph" << '\n';
      continue;
    }
    dfs(1);
    if (ret == n) cout << "tree" << '\n';
    else cout << "graph" << '\n';
  }
}