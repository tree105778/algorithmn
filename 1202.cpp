#include <bits/stdc++.h>

using namespace std;

int n, k, a, b, ret;
vector<int> v;
vector<pair<int, int>> v2;
priority_queue<int> pq;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  v2.reserve(n);
  v.reserve(k);
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v2.push_back({a, b});
  }

  for(int i = 0; i < k; i++) {
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());
  sort(v2.begin(), v2.end());

  int j = 0;
  for(int i = 0; i < k; i++) {
    while (j < n && v2[j].first <= v[i]) {
      // cout << v2[j].first << ' ' << v2[j].second << '\n';
      pq.push(v2[j].second);
      j++;
    }
    if (pq.size()) {
      ret += pq.top();
      pq.pop();
    }
    // cout << "ret: " << ret << '\n';
  }

  cout << ret;

  return 0;
}