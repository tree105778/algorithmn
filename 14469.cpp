#include <bits/stdc++.h>

using namespace std;

int n, a, b, result;
vector<pair<int, int>> v;

bool comp(pair<int, int>& p, pair<int, int>& p2) {
  if (p.first == p2.first) return p.second < p2.second;
  return p.first < p2.first;
}

int main() {
  cin >> n;
  v.reserve(n);
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end(), comp);

  for(auto &i: v) {
    if (result < i.first) result = i.first;
    result += i.second;
  }

  cout << result;
}