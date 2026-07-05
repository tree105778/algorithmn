#include <bits/stdc++.h>

using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({b, a});
  }

  sort(v.begin(), v.end());
  
  a = v[0].first;
  b = v[0].second;

  for(int i = 1; i < n; i++) {
    if (v[i].second < a) continue;
    ret++; a = v[i].first; b = v[i].second;
  }

  cout << ret + 1;

  return 0;
}