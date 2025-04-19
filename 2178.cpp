#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
int mp[104][104];
int visited[104][104];
string s;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int main() {
  visited[1][1] = 1;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> s;
    for(int j = 1; j <= m; j++) {
      mp[i][j] = s[j - 1] - '0';
    }
  }

  queue<pair<int, int>> q;
  q.push({1, 1});

  while (!q.empty()) {
    tie(y, x) = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 1 || ny > n || nx < 1 || nx > m) continue;
      if (!visited[ny][nx] && mp[ny][nx]) {
        q.push({ny, nx});
        visited[ny][nx] = visited[y][x] + 1;
      }
    }
  }

  cout << visited[n][m];

  return 0;

}