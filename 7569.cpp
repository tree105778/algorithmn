#include <bits/stdc++.h>

using namespace std;

int m, n, h, max_lvl;
int box[105][105][105];
int visited[105][105][105];
const int dz[] = {0, 0, 0, 0, 1, -1};
const int dy[] = {-1, 0, 1, 0, 0, 0};
const int dx[] = {0, 1, 0, -1, 0, 0};
queue<tuple<int, int, int>> q;
int main() {
  cin >> m >> n >> h;

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < m; k++) {
        cin >> box[i][j][k];
        if (box[i][j][k] == 1) q.push({i, j, k});
        if (box[i][j][k] == -1) {
          visited[i][j][k] = -1;
        }
      }
    }
  }

  while (q.size()) {
    int x, y, z;
    tie(z, y, x) = q.front();
    q.pop();
    if (visited[z][y][x] == 0) visited[z][y][x] = 1;
    for (int i = 0; i < 6; i++) {
      int nz = z + dz[i];
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
      if (!visited[nz][ny][nx] && box[nz][ny][nx] == 0) {
        visited[nz][ny][nx] = visited[z][y][x] + 1;
        q.push({nz, ny, nx});
        box[nz][ny][nx] = 1;
        if (visited[nz][ny][nx] > max_lvl) max_lvl = visited[nz][ny][nx];
      }
    }
  }

  // box가 0인 경우 제외
  bool flag = true;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < m; k++) {
        if (box[i][j][k] == 0) {
          flag = false;
          break;
        }
      }
    }
  }

  if (flag) {
    // 하루만에 다 익은 경우 제외
    if (max_lvl == 0) cout << max_lvl; 
    // visited = 1로 시작해서 계산해나갔기 때문에 -1을 해주어야 함
    else cout << max_lvl - 1;
  }
  else cout << -1;
}