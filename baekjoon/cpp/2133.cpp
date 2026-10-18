#include <bits/stdc++.h>

using namespace std;

int dp[35], n;
int main() {
  cin >> n;
  dp[0] = 1;
  dp[2] = 3;
  for(int i = 4; i <= 30; i+=2) {
    dp[i] = dp[i - 2] * 3;
    for(int j = i - 4; j >= 0; j-=2) {
      dp[i] += dp[j] * 2;
    }
  }

  cout << dp[n];
}