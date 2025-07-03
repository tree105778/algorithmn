#include <bits/stdc++.h>

using namespace std;

int n, m;
int mp[105][105];
int visited[105][105];

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

queue<pair<int, int>> qu;
int cheeze_cnt, last_cheeze, result_cnt;
void dfs(int y, int x) {
  visited[y][x] = 1;

  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
    if (mp[ny][nx] == 1 && !visited[ny][nx]) {
      visited[ny][nx] = 1;
      qu.push({ny, nx});
    }
    if (mp[ny][nx] == 0 && !visited[ny][nx]) {
      dfs(ny, nx);
    }
  }
} 

int main() {
  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> mp[i][j];
      if (mp[i][j] == 1) cheeze_cnt++;
    }
  }

  while (cheeze_cnt > 0) {
    int curr_cnt = 0;
    dfs(0, 0);
    while (qu.size()) {
      int x, y;
      tie(y, x) = qu.front();
      qu.pop();
      mp[y][x] = 0;
      curr_cnt++;
    }
    if (cheeze_cnt == curr_cnt) {
      last_cheeze = curr_cnt;
    }
    cheeze_cnt -= curr_cnt;
    result_cnt++;
    memset(visited, 0, sizeof(visited));
  }

  cout << result_cnt << '\n';
  cout << last_cheeze << '\n';

  return 0;
}