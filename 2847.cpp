#include <bits/stdc++.h>

using namespace std;

int n, lev[105], ret;
int main() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> lev[i];
  }

  for(int i = n - 2; i >= 0; i--) {
    if (lev[i] >= lev[i + 1]) {
      ret += (lev[i] - lev[i + 1] + 1);
      lev[i] = lev[i + 1] - 1;
    }
  }

  cout << ret;
}