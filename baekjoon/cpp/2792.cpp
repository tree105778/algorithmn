#include <bits/stdc++.h>

using namespace std;

int n, m, v[300005], low, high, cnt, ans;
int main() {
  cin >> n >> m;

  for(int i = 0; i < m; i++) {
    cin >> v[i];
  }

  sort(v, v + m);

  low = 1; high = v[m - 1];
  while (low <= high) {
    int mid = (low + high) / 2;
    
    for(int i = 0; i < m; i++) {
      cnt += v[i] / mid;
      if (v[i] % mid) cnt++;
    }

    if (cnt <= n) {
      high = mid - 1;
      ans = mid;
    } else {
      low = mid + 1;
    }
  }

  cout << ans;

  return 0;
}