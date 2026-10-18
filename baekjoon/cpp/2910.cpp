#include <bits/stdc++.h>

using namespace std;

int n, m, num;
map<int, int> mp;
map<int, int> q;
bool compare(pair<int, int>& a, pair<int, int>& b) {
  if (a.second == b.second) return q[a.first] < q[b.first];
  return b.second < a.second;
}
int main() {
  cin >> n >> m;
  
  for(int i = 0; i < n; i++) {
    cin >> num;
    mp[num]++;
    if (q[num] == 0) q[num] = i + 1;
  }

  vector<pair<int, int>> v(mp.begin(), mp.end());

  sort(v.begin(), v.end(), compare);

  for(auto p : v) {
    for(int i = 0; i < p.second; i++) cout << p.first << ' ';
  }
}