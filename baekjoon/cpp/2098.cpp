#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int w[20][20];
int dp[20][1 << 16];
int n;

int solve(int curr, int visited) {
  if (visited == (1 << (n + 1)) - 2) {
    if (w[curr][1]) return w[curr][1];
    return INF;
  }

  int& temp = dp[curr][visited];

  if (temp != -1) return temp;
  
  temp = INF;

  for(int i = 1; i <= n; i++) {
    if (visited & (1 << i)) continue;
    if (!w[curr][i]) continue;
    temp = min(temp, solve(i, visited | (1 << i)) + w[curr][i]);
  }

  return temp;
}

int main() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> w[i + 1][j + 1];
    }
  }

  memset(dp, -1, sizeof(dp));
  cout << solve(1, 1 << 1);

  return 0; 
}