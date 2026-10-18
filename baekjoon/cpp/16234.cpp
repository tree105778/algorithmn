#include <bits/stdc++.h>

using namespace std;

int N, L, R, cnt, cnt_sum, ret, flag;
int m[55][55];
int visited[55][55];
vector<pair<int, int>> v;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};
void dfs(int y, int x) {
  visited[y][x] = 1;
  v.push_back({y, x});
  cnt_sum += m[y][x];
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
    if (abs(m[ny][nx] - m[y][x]) < L || abs(m[ny][nx] - m[y][x]) > R) continue;
    if (!visited[ny][nx]) {
      cnt++;
      dfs(ny, nx);
    }
  }
  
}

int check() {
  flag = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cnt = 1; cnt_sum = 0;
      v.clear();
      if (!visited[i][j]) dfs(i, j);
      if (cnt == 1) continue;
      for(auto& k : v) {
        m[k.first][k.second] = cnt_sum / cnt;
      }
      flag = 1;
    }
  }
  if (!flag) return 0;

  return 1;
}

int main() {
  cin >> N >> L >> R;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> m[i][j];
    }
  }

  while (true) {
    memset(visited, 0, sizeof(visited));
    if (!check()) break;
    ret++;
  }
  cout << ret;
}