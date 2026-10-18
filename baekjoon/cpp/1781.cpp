#include <bits/stdc++.h>

using namespace std;

int n, a, b, ret;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());

  for(auto& i: v) {
    pq.push(i.second);
    if (pq.size() > i.first) pq.pop();
  }

  while (!pq.empty()) {
    ret += pq.top();
    pq.pop();
  }

  cout << ret;
  return 0;
}