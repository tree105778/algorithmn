#include <bits/stdc++.h>

using namespace std;

int dp[35], n;
int main() {
  cin >> n;

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 3;

  for(int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] * 2;
  }

  if (n % 2 == 1) cout << (dp[n] + dp[n / 2]) / 2; 
  else cout << (dp[n] + (dp[n / 2] + dp[n / 2 - 1] * 2)) / 2;

  return 0;
}