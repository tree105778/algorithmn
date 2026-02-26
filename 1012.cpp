#include <bits/stdc++.h>

using namespace std;

int T;
int m, n, k, a, b, ret;
int mp[60][60], visited[60][60];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void DFS(int y, int x) {
  visited[y][x] = 1;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= m || nx < 0 || nx > n) continue;
    if (!visited[ny][nx] && mp[ny][nx]) DFS(ny, nx);
  }
}

int main() {
  cin >> T;

  while (T--) {
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++) {
      cin >> a >> b;
      mp[a][b] = 1;
    }
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if (!visited[i][j] && mp[i][j]) {
          ret++; DFS(i, j);
        }
      }
    }
    cout << ret << '\n';
    ret = 0;
    memset(mp, 0, sizeof(mp));
    memset(visited, 0, sizeof(visited));
  }
}