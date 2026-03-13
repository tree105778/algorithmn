#include <bits/stdc++.h>

using namespace std;

int r, c, ret, max_ret;

string s;
int mp[25][25];
int visited[25][25];
int alpha[26];

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
void dfs(int y, int x) {
  alpha[mp[y][x]] = 1;
  visited[y][x] = 1;
  ret++;

  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;

    if (!visited[ny][nx] && !alpha[mp[ny][nx]]) {
      dfs(ny, nx);
    }
  }
  if (max_ret < ret) max_ret = ret;
  visited[y][x] = 0;
  alpha[mp[y][x]] = 0;
  ret--;
}

int main() {
  cin >> r >> c;

  for(int i = 0; i < r; i++) {
    cin >> s;
    for(int j = 0; j < c; j++) {
      mp[i][j] = s[j] - 'A';
    }
  }

  dfs(0, 0);

  cout << max_ret;
}