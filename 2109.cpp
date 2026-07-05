#include <bits/stdc++.h>

using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({b, a});
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++) {
    pq.push(v[i].second);
    if (v[i].first < pq.size()) pq.pop();
  }

  while (!pq.empty()) {
    ret += pq.top();
    pq.pop();
  }

  cout << ret;

  return 0;
}