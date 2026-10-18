#include <bits/stdc++.h>

using namespace std;

int dp[305][5];
int s[305];
int n;
int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> s[i];

  dp[1][0] = 0; dp[1][1] = s[1];
  dp[2][0] = s[1]; dp[2][1] = s[2]; dp[2][2] = s[1] + s[2];

  for(int i = 3; i <= n; i++) {
    dp[i][0] = max(dp[i - 1][2], dp[i - 1][1]);
    dp[i][1] = dp[i - 1][0] + s[i];
    dp[i][2] = dp[i - 1][1] + s[i];
  }

  cout << max(dp[n][1], dp[n][2]);
}