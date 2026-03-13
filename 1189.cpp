#include <bits/stdc++.h>

using namespace std;

int r, c, k, ret;
int mp[10][10];
int visited[10][10];

string s;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
  if (y == 0 && x == c - 1) {
    if (visited[y][x] == k) ret++;
    return;
  }  
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
    if (!visited[ny][nx] && mp[ny][nx]) {
      visited[ny][nx] = visited[y][x] + 1;
      dfs(ny, nx);
      visited[ny][nx] = 0;
    }
  }
}
int main() {
  cin >> r >> c >> k;

  for(int i = 0; i < r; i++) {
    cin >> s;
    for(int j = 0; j < c; j++) {
      if (s[j] == '.') mp[i][j] = 1;
      if (s[j] == 'T') mp[i][j] = 0;
    }
  }

  visited[r - 1][0] = 1;
  dfs(r - 1, 0);

  cout << ret;
}