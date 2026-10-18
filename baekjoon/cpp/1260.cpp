#include <bits/stdc++.h>

using namespace std;

int n, m, v, a, b;
queue<int> q;
int visited[1004];
int mp[1005][1005];

// 인접 리스트
// vector<set<int>> graph(1004);
// void dfs(int v) {
//   visited[v] = 1;
//   cout << v << ' ';
//   for(auto it = graph[v].begin(); it != graph[v].end(); it++) {
//     if (!visited[*it]) dfs(*it);
//   }
// }

// void bfs(int v) {
//   visited[v] = 1;
//   q.push(v);
//   while (q.size()) {
//     int num = q.front();
//     cout << num << ' ';
//     q.pop();
//     for(auto it = graph[num].begin(); it != graph[num].end(); it++) {
//       if (!visited[*it]) {
//         visited[*it] = 1;
//         q.push(*it);
//       }
//     }
//   }
// }
// int main() {
//   cin >> n >> m >> v;
//   for(int i = 0; i < m; i++) {
//     cin >> a >> b;
//     graph[a].insert(b);
//     graph[b].insert(a);
//   };

//   dfs(v);
//   memset(visited, 0, sizeof(visited));
//   cout << '\n';
//   bfs(v);

//   return 0;
// }

// 인접 행렬
void dfs(int v) {
  visited[v] = 1;
  cout << v << ' ';
  for(int i = 1; i <= n; i++) {
    if(!visited[i] && mp[v][i]) dfs(i);
  }
}

void bfs(int v) {
  visited[v] = 1;
  q.push(v);
  while (q.size()) {
    int num = q.front();
    q.pop();
    cout << num << ' ';
    for(int i = 1; i <= n; i++) {
      if (!visited[i] && mp[num][i]) {
        q.push(i);
        visited[i] = 1;
      }
    }
  }
}
int main() {
  cin >> n >> m >> v;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    mp[a][b] = 1;
    mp[b][a] = 1;
  }

  dfs(v);
  cout << '\n';
  memset(visited, 0, sizeof(visited));
  bfs(v);
}