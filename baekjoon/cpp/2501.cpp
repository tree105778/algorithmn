#include <bits/stdc++.h>

using namespace std;

int n, k, cnt, ret;
int main() {
  cin >> n >> k;

  for(int i = 1; i <= n; i++) {
    if (n % i == 0) cnt++;
    if (cnt == k) {
      ret = i;
      break;
    }
  }

  cout << ret;

  return 0;
}