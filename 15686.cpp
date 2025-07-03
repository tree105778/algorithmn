#include <bits/stdc++.h>

using namespace std;

int n, m, min_result = 1e9;
int mp[55][55];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<int> v;

void solve(vector<int>& a) {
  int chicken_dist = 0;
  for(auto& i : house) {
    int local_min = 1e9;
    for(auto& j : a) {
      int local_result = abs(i.first - chicken[j].first) + abs(i.second - chicken[j].second);
      if (local_min > local_result) local_min = local_result;
    }
    chicken_dist += local_min;
  }
  if (min_result > chicken_dist) min_result = chicken_dist;
}

void combi(int n) {
  if (v.size() == m) {
    solve(v);
    return;
  }

  for(int i = n + 1; i < chicken.size(); i++) {
    v.push_back(i);
    combi(i);
    v.pop_back();
  }
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> mp[i][j];
      if (mp[i][j] == 1) house.push_back({i, j});
      else if(mp[i][j] == 2) chicken.push_back({i, j});
    }
  }

  combi(-1);
  cout << min_result;

  return 0;
}