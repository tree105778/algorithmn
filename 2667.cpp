#include <bits/stdc++.h>

using namespace std;

int n, ret, cnt;
int mp[30][30];
string s;
int visited[30][30];

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

vector<int> v;
void dfs(int y, int x) {
  visited[y][x] = 1;
  ret++;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
    if (!visited[ny][nx] && mp[ny][nx]) dfs(ny, nx);
  }
}
int main() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> s;
    for(int j = 0; j < n; j++) {
      mp[i][j] = s[j] - '0';
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if (!visited[i][j] && mp[i][j]) {
        ret = 0; cnt++;
        dfs(i, j);
        v.push_back(ret);
      }
    }
  }

  sort(v.begin(), v.end());
  cout << cnt << '\n';
  for(auto it = v.begin(); it != v.end(); it++) cout << *it << '\n';

}