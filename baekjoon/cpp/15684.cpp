#include <bits/stdc++.h>

using namespace std;

int n, m, h, ret;
int board[35][35];
bool found_ans;

bool check() {
  for(int i = 1; i <= n; i++) {
    int pos = i;
    for(int j = 1; j <= h; j++) {
      if (board[j][pos] == 1) {
        pos++;
      } else if (pos > 1 && board[j][pos - 1] == 1) {
        pos--;
      }
    }

    if (pos != i) return false;
  }

  return true;
}

void dfs(int cnt, int y, int x) {
  if (found_ans) return;

  if (cnt == ret) {
    if (check()) found_ans = true;
    return;
  }

  for(int i = y; i <= h; i++) {
    for(int j = (i == y ? x : 1); j < n; j++) {
      if (board[i][j] == 0 && board[i][j - 1] == 0 && board[i][j + 1] == 0) {
        board[i][j] = 1;

        dfs(cnt + 1, i, j + 2);

        board[i][j] = 0;
      }
    }
  }
}
int main() {
  cin >> n >> m >> h;

  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    board[a][b] = 1;
  }

  for(int i = 0; i <= 3; i++) {
    ret = i;
    dfs(0, 1, 1);

    if (found_ans) {
      cout << i << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';

  return 0;
}