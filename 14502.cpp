#include <bits/stdc++.h>

using namespace std;

int n, m, max_area;
int mp[20][20];
int sub_mp[20][20];
vector<pair<int, int>> virus;
vector<pair<int, int>> zero;
vector<int> wall;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

// 왜 중간에 멈추지? -> combi 함수에 return문 추가
void dfs(int y, int x) {
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
    if (sub_mp[ny][nx] == 0) {
      sub_mp[ny][nx] = 2;
      dfs(ny, nx);
    }
  }
}

void get_size() {
  int result = 0;
  for(size_t i = 0; i < virus.size(); i++) {
    int y, x;
    tie(y, x) = virus[i];
    dfs(y, x);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (sub_mp[i][j] == 0) result++;
    }
  }

  if (max_area <= result) max_area = result;
}

void combi(int s) {
  if (wall.size() == 3) {
    memcpy(sub_mp, mp, sizeof(mp));
    for(size_t i = 0; i < wall.size(); i++) {
      int x, y;
      tie(y, x) = zero[wall[i]];
      sub_mp[y][x] = 1;
    }
    
    get_size();
    return;
  }
  for(size_t i = s + 1; i < zero.size(); i++) {
    wall.push_back(i);
    combi(i);
    wall.pop_back();
  }
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> mp[i][j];
      if (mp[i][j] == 2) virus.push_back({i, j});
      if (mp[i][j] == 0) zero.push_back({i, j});
    }
  }
  combi(-1);

  cout << max_area;
}