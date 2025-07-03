#include <bits/stdc++.h>

using namespace std;

int n, cnt, num;
int dp[50005];

int go(int x) {
  vector<int> v;
  if (x == 0) return 0;
  int& ret = dp[x];
  if (dp[x] != 0) return dp[x];

  for(int i = sqrt(x); i >= 1; i--) {
    v.push_back(dp[i * i] + go(x - i * i));
  }

  return ret = *min_element(v.begin(), v.end());
}

int main() {
  cin >> n;

  for(int i = 1; i <= sqrt(n); i++) {
    dp[i * i] = 1;
  }

  cnt = go(n);

  cout << cnt;
}