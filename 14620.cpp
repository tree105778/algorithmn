#include <bits/stdc++.h>

using namespace std;

bool flag;
int n, ret, min_ret = INT_MAX;
int mp[15][15], visited[15][15];
vector<int> v;
queue<pair<int, int>> qu;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs() {
  int y, x;
  flag = true;
  while (qu.size()) {
    tie(y, x) = qu.front();
    qu.pop();
    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
        flag = false;
        break;
      }

      if (visited[ny][nx]) {
        flag = false;
        break;
      }

      visited[ny][nx] = 1;
      ret += mp[ny][nx];
    }
  }
}

void dfs(int x) {
  if (v.size() == 3) {
    for(auto& i : v) {
      int y = i / n, x = i % n;
      qu.push({y, x});
      ret += mp[y][x];
      visited[y][x] = 1;
    }
    bfs();
    if (flag && ret < min_ret) {
      min_ret = ret;
    }
    ret = 0;
    memset(visited, 0, sizeof(visited));
    return;
  }
  for(int i = x; i < n * n; i++) {
    v.push_back(i);
    dfs(i + 1);
    v.pop_back();
  }
}
int main() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> mp[i][j];
    }
  }

  dfs(0);
  cout << min_ret;
}