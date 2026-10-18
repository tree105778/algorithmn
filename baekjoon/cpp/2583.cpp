#include <bits/stdc++.h>

using namespace std;

int m, n, k;
int x1, x2, y_1, y_2, ret, width;
int mp[105][105], visited[105][105];
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
vector<int> v;

void dfs(int y, int x) {
  visited[y][x] = 1;
  width++;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
    if (!visited[ny][nx] && !mp[ny][nx]) dfs(ny, nx);
  }
}

int main() {
  cin >> m >> n >> k;

  for(int i = 0; i < k; i++) {
    cin >> x1 >> y_1 >> x2 >> y_2;
    for(int i = y_1; i < y_2; i++) {
      for(int j = x1; j < x2; j++) {
        mp[i][j] = 1;
      }
    }
  }

  for(int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j] && !mp[i][j]) {
        ret++;
        dfs(i, j);
        v.push_back(width);
        width = 0;
      }
    }
  }
  sort(v.begin(), v.end());
  cout << v.size() << '\n';
  for(int i : v) cout << i << " ";

  return 0;
}