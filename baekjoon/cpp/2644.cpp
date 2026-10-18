#include <bits/stdc++.h>

using namespace std;

int fm[105][105];
int calc[105];
int visited[105];
int n, x, y, m, a, b;

void dfs(int start) {
  visited[start] = 1;

  for(int i = 1; i <= n; i++) {
    if (!visited[i] && fm[start][i] == 1) {
      calc[i] = calc[start] + fm[start][i];
      dfs(i);
    }
  }

  for(int i = 1; i <= n; i++) {
    if (!visited[i] && fm[start][i] == -1) {
      calc[i] = calc[start] + fm[i][start];
      dfs(i);
    }
  }
}

int main() {
  int result;

  cin >> n;

  cin >> x >> y;

  cin >> m;

  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    fm[a][b] = -1;
    fm[b][a] = 1;
  }

  dfs(x);

  if (!visited[y]) {
    cout << -1;
  } else {
    result = calc[y] < 0 ? -calc[y] : calc[y];
    cout << result;
  }
}