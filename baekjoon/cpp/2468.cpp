#include <bits/stdc++.h>

using namespace std;

int mp[104][104], visited[104][104];
int n, max_height, ret, max_ret;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
void dfs(int y, int x, int crit) {
  visited[y][x] = 1;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
    if (!visited[ny][nx] && mp[ny][nx] > crit) {
      dfs(ny, nx, crit);
    }
  }
}
int main() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> mp[i][j];
      if (mp[i][j] >= max_height) max_height = mp[i][j];
    }
  }
  for(int i = 0; i <= max_height; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        if (!visited[j][k] && mp[j][k] > i) {
          ret++; dfs(j, k, i);
        }
      }
    }
    if (ret >= max_ret) max_ret = ret;
    memset(visited, 0, sizeof(visited));
    ret = 0;
  }

  cout << max_ret;
}