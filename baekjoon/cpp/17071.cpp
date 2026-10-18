#include <bits/stdc++.h>

using namespace std;

int n, k, t = 1;
int visited[500005][3];
queue<int> qu;

int main() {
  cin >> n >> k;

  qu.push(n);
  visited[n][0] = 1;
  visited[n][1] = k;
  visited[n][2] = t;

  while (qu.size()) {
    int cur = qu.front();
    qu.pop();
    if (cur == visited[cur][1]) {
      k = visited[cur][1];
      break;
    }
    int next_position[] = {cur - 1, cur + 1, cur * 2};
    for(int i = 0; i < 3; i++) {
      int next_pos = next_position[i];
      if (next_pos >= 0 && next_pos <= 500000 && !visited[next_pos][0]) {
        visited[next_pos][0] = visited[cur][0] + 1;
        visited[next_pos][1] = visited[cur][1] + visited[cur][2];
        visited[next_pos][2] = visited[cur][2] + 1;
        qu.push(next_pos);
      }
    }
  }

  if (visited[k][1] <= 500000 && visited[k][0]) cout << visited[k][0] - 1;
  else cout << -1;
}