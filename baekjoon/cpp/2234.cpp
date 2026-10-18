#include <bits/stdc++.h>

using namespace std;

int n, m, ret, first, second, third;
int mp[55][55];
int visited[55][55];
map<int, int> cached;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};

void dfs(int y, int x) {
  ret++;
  visited[y][x] = first;

  for(int i = 0; i < 4; i++) {
    if (!(mp[y][x] & (1 << i))) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
      if (!visited[ny][nx]) dfs(ny, nx);
    }
  }
}

int main() {
  cin >> n >> m;

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      cin >> mp[i][j];
    }
  }

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      ret = 0;
      if (!visited[i][j]) {
        first++;
        dfs(i, j);
        cached[first] = ret;
        if (ret > second) second = ret;
      }
    }
  }

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      int ny, nx;
      for(int k = 0; k < 4; k++) {
        ny = i + dy[k];
        nx = j + dx[k];
        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if (visited[i][j] != visited[ny][nx]) {
          int temp = cached[visited[i][j]] + cached[visited[ny][nx]];
          if (temp > third) third = temp;
        }
      }
    }
  }  

  cout << first << '\n' << second << '\n' << third;

  return 0;
}