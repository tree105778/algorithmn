#include <bits/stdc++.h>

using namespace std;

int visited[1000005];
queue<int> q;
int f, s, g, u, d, num, up, down;
int main() {
  cin >> f >> s >> g >> u >> d;

  q.push(s);
  visited[s] = 1;

  while (q.size()) {
    num = q.front();
    q.pop();
    up = num + u;
    down = num - d;
    if (up > 0 && up <= f && !visited[up]) {
      visited[up] = visited[num] + 1;
      if (up == g) break;
      q.push(up);
    }

    if (down > 0 && down <= f && !visited[down]) {
      visited[down] = visited[num] + 1;
      if (down == g) break;
      q.push(down);
    }
  }

  if (visited[g]) cout << visited[g] - 1;
  else cout << "use the stairs";

  return 0;
}