#include <bits/stdc++.h>

using namespace std;

int n, k, min_time, ret;
int visited[100005];
queue<int> qu;
int main() {
  cin >> n >> k;

  qu.push(n);
  visited[n] = 1;
  while (qu.size()) {
    int cur_pos = qu.front();
    qu.pop();

    int cur_time = visited[cur_pos];

    if (cur_pos == k) {
      if (!min_time) min_time = cur_time;
      if (cur_time == min_time) ret++;
      continue;
    }

    int next_position[3] = {cur_pos - 1, cur_pos + 1, cur_pos * 2};
    for(int i = 0; i < 3; i++) {
      int next_pos = next_position[i];
      if (next_pos >= 0 && next_pos <= 100000) {
        if (!visited[next_pos] || visited[next_pos] == cur_time + 1) {
          visited[next_pos] = cur_time + 1;
          qu.push(next_pos);
        }
      }
    }
  }

  cout << visited[k] - 1 << '\n' << ret;
}