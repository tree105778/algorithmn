#include <bits/stdc++.h>

using namespace std;

int N, M, a, b, ret, MAX = -1;
int visited[10005];
int cache[10005];
vector<vector<int>> v;
void dfs(int n) {
  ret++;
  visited[n] = 1;
  for(auto& i :  v[n]) {
    if (!visited[i]) dfs(i);
  }
}

int main() {
  cin >> N >> M;
  v.reserve(N + 1);
  for(int i = 0; i < M; i++) {
    cin >> a >> b;
    v[b].push_back(a);
  }

  for(int i = 1; i <= N; i++) {
    ret = 0;
    dfs(i);
    cache[i] = ret;
    memset(visited, 0, sizeof(visited));
    if (MAX < ret) MAX = ret;
  }

  for(int i = 1; i <= N; i++) {
    if (MAX == cache[i]) cout << i << ' ';
  }
}