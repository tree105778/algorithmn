#include <bits/stdc++.h>

using namespace std;

int dp[1000004], n;
int main() {

  cin >> n;
  for(int i = 2; i <= 1000000; i++) {
    if (i % 6 == 0)
      dp[i] = min(min(dp[i - 1] + 1, dp[i / 2] + 1), dp[i / 3] + 1);
    else if (i % 3 == 0)
      dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
    else if (i % 2 == 0)
      dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
    else dp[i] = dp[i - 1] + 1;
  }

  cout << dp[n];
}