#include <bits/stdc++.h>

using namespace std;

int n, m, start_x, end_x, start_y, end_y, level;
int mp[305][305];
int visited[305][305];
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
deque<pair<pair<int, int>, int>> qu;
string s;
int main() {
  cin >> n >> m;
  cin >> start_y >> start_x >> end_y >> end_x;
  start_x--; start_y--; end_x--; end_y--;
  for(int i = 0; i < n; i++) {
    cin >> s;
    for(int j = 0; j < m; j++) {
      if (s[j] == '*') mp[i][j] = -1;
      else if (s[j] == '#') mp[i][j] = 2;
      else mp[i][j] = s[j] - '0';
    }
  }

  qu.push_back({{start_y, start_x}, 0});
  visited[start_y][start_x] = 1;

  while (qu.size()) {
    int x, y;
    tie(y, x) = qu.front().first;
    level = qu.front().second;
    qu.pop_front();
    if (x == end_x && y == end_y) break;
    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (!visited[ny][nx]) {
        visited[ny][nx] = 1;
        if (mp[ny][nx] == 0) {
          qu.push_front({{ny, nx}, level});
        } else if (mp[ny][nx]) {
          qu.push_back({{ny, nx}, level + 1});
        }
      }
    }
  }
  
  cout << level;
}