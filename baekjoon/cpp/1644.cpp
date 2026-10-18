#include <bits/stdc++.h>

using namespace std;

int n, ret, l, r, sum;
int a[4000005];
vector<int> v;
int main() {
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  a[1] = 1;
  for(int i = 2; i * i <= n; i++) {
    for(int j = i * i; j <= n; j += i) {
      a[j] = 1;
    }
  }

  for(int i = 2; i <= n; i++) {
    if (!a[i]) v.push_back(i);
  }

  // for(auto&i : v) cout << i << ' ';
  while (1) {
    cout << l << ' ' << r << ' ' << sum << '\n';
    if (sum >= n) sum -= v[l++];
    else if (sum < n) sum += v[r++];
    if (sum == n) ret++;
    if (l == r) break;
  }

  cout << ret;

  return 0;
}