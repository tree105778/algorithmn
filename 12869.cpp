#include <bits/stdc++.h>

using namespace std;

int dp[61][61][61], n, input[3];

int p[6][3] = {
  {9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}
};
int solve(int x, int y, int z) {
  if (x == 0 && y == 0 && z == 0) return 0;

  int& ret = dp[x][y][z];
  if (ret != 0) return ret;

  dp[x][y][z] = 1e9;
  for(int i = 0; i < 6; i++) {
    int nx = max(0, x - p[i][0]);
    int ny = max(0, y - p[i][1]);
    int nz = max(0, z - p[i][2]);

    dp[x][y][z] = min(dp[x][y][z], solve(nx, ny, nz) + 1);
  }

  return dp[x][y][z];
}
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input[i];
  }

  cout << solve(input[0], input[1], input[2]);

}