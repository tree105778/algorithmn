#include <bits/stdc++.h>

using namespace std;

char mp[10][10];
vector<pair<int, int>> sp;
vector<int> com;
int ret;
const int dy[] = {1, 0, -1 ,0};
const int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> qu;
int visited[10][10];
void solve() {
  int cnt = 0;
  for(auto& i : com) {
    for(auto& s : sp) {
      if (s.first == i / 5 && s.second == i % 5) cnt++;
    }
  }
  if (cnt < 4) return;
  qu.push({com[0] / 5, com[0] % 5});
  visited[com[0] / 5][com[0] % 5] = 1;
  cnt = 1;
  while (qu.size()) {
    int y, x;
    tie(y, x) = qu.front();
    qu.pop();
    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
      if (find(com.begin(), com.end(), ny * 5 + nx) != com.end() && !visited[ny][nx]) {
        cnt++;
        qu.push({ny, nx});
        visited[ny][nx] = 1;
      }
    }
  }
  if (cnt == 7) ret++;
}

void combi(int n) {
  if (com.size() == 7) {
    solve();
    memset(visited, 0, sizeof(visited));
    return;
  }
  for(int i = n + 1; i < 25; i++) {
    com.push_back(i);
    combi(i);
    com.pop_back();
  }
}
int main() {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      cin >> mp[i][j];
      if (mp[i][j] == 'S') sp.push_back({i, j});
    }
  }
  combi(-1);

  cout << ret;

}