#include <bits/stdc++.h>

using namespace std;

int N, M, path_stx, path_sty, ans;
bool flag = false;
char tmp;
int mp[1005][1005];
int fire[1005][1005];

queue<pair<int, int>> qu;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
void fireSimul() {
  while (qu.size()) {
    int y, x;
    tie(y, x) = qu.front();
    qu.pop();
    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if (fire[ny][nx] == 0) {
        fire[ny][nx] = fire[y][x] + 1;
        qu.push({ny, nx});
      }
    }
  }
}

void findPath() {
  while (qu.size()) {
    int y, x;
    tie(y, x) = qu.front();
    qu.pop();
    if (y == 0 || y == N - 1 || x == 0 || x == M - 1) {
        ans = mp[y][x];
        flag = true;
        return;
    }
    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if (mp[ny][nx] == 0 && fire[ny][nx] == 0) {
        qu.push({ny, nx});
        mp[ny][nx] = mp[y][x] + 1;
      }
      if (mp[ny][nx] == 0 && ((mp[ny][nx] = mp[y][x] + 1) < fire[ny][nx])) {
        qu.push({ny, nx});
      }
    }
  }
}

int main() {
  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> tmp;
      if (tmp == '#') {
        mp[i][j] = -1;
        fire[i][j] = -1;
      }
      if (tmp == '.') {
        mp[i][j] = 0;
        fire[i][j] = 0;
      }
      if (tmp == 'J') {
        mp[i][j] = 1;
        path_sty = i;
        path_stx = j;
      }
      if (tmp == 'F') {
        fire[i][j] = 1;
        qu.push({i, j});
      }
    }
  }

  fireSimul();
  qu.push({path_sty, path_stx});
  findPath();
  if (flag) cout << ans;
  else cout << "IMPOSSIBLE";
}