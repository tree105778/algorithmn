#include <bits/stdc++.h>

using namespace std;

int mp[55][55], MAX, N, M;
int visited[55][55];
queue<pair<int,int>> qu;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};

void bfs(int y, int x) {
  qu.push({y, x});
  visited[y][x] = 1;

  while (qu.size()) {
    int y, x;
    tie(y, x) = qu.front();
    qu.pop();
    for(int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if (!visited[ny][nx] && mp[ny][nx] == 1) {
        qu.push({ny, nx});
        visited[ny][nx] = visited[y][x] + 1;
      }
    }
  }
}

void findMax() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if (visited[i][j] > MAX) MAX = visited[i][j];
    }
  }
}

int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      char ch;
      cin >> ch;
      if (ch == 'W') {
        mp[i][j] = 0;
      } else if (ch == 'L') {
        mp[i][j] = 1;
      }
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      memset(visited, 0, sizeof(visited));
      if (mp[i][j] == 1) bfs(i, j);
      findMax();
    }
  }
  cout << MAX - 1;
}