#include <bits/stdc++.h>

using namespace std;

int sd[10][10];
bool flag;
vector<pair<int, int>> v;

bool check(int y, int x, int n) {
  for(int i = 0; i < 9; i++) {
    if (sd[y][i] == sd[y][x] && x != i) return false;
    if (sd[i][x] == sd[y][x] && y != i) return false;
  }
  int start_y = y / 3 * 3;
  int start_x = x / 3 * 3;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      int ny = start_y + i;
      int nx = start_x + j;
      if (sd[ny][nx] == sd[y][x] && y != ny && x != nx) return false;
    }
  }

  return true;
}

void backtracking(int n) {
  if (n >= v.size()) {
    flag = true;
    return;
  }

  int y = v[n].first;
  int x = v[n].second;
  for(int i = 1; i <= 9; i++) {
    sd[y][x] = i;
    if (check(y, x, i)) {
      backtracking(n + 1);
    }
    if (flag) return;
    sd[y][x] = 0;
  }
}

int main() {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cin >> sd[i][j];
      if (sd[i][j] == 0) {
        v.push_back({i, j});
      }
    }
  }

  backtracking(0);

  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cout << sd[i][j] << ' ';
    }
    cout << '\n';
  }
}