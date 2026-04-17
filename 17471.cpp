#include <bits/stdc++.h>

using namespace std;

int n, temp, temp2, min_ret = INT_MAX;
int member[15], team[15];
vector<vector<int>> v;
vector<int> group1, group2;
int visited[15];
bool flag;

void dfs(int k, int team_num) {
  temp++;
  if (temp == temp2) {
    flag = true;
    return;
  }
  visited[k] = 1;
  for(auto i: v[k]) {
    if (!visited[i] && team[i] == team_num) dfs(i, team_num);
  }
}

bool isConnected(vector<int>& a, int team_num) {
  flag = false;
  temp = 0;
  temp2 = a.size();
  dfs(a[0], team_num);
  memset(visited, 0, sizeof(visited));
  return flag;
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> member[i];
  }

  v.reserve(n);
  v.push_back({0});
  for(int i = 0; i < n; i++) {
    vector<int> v2;
    cin >> temp;
    for(int j = 0; j < temp; j++) {
      cin >> temp2;
      v2.push_back(temp2);
    }
    v.push_back(v2);
  }

  for(int i = 1; i < (1 << n) - 1; i++) {
    for(int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        group1.push_back(j + 1);
        team[j + 1] = 1;
      }
      else {
        group2.push_back(j + 1);
        team[j + 1] = 2;
      }
    }
    if (isConnected(group1, 1) && isConnected(group2, 2)) {
      int sum1 = 0, sum2 = 0;
      for(auto g1: group1) sum1 += member[g1];
      for(auto g2: group2) sum2 += member[g2];
      temp = abs(sum1 - sum2);
      if (temp < min_ret) min_ret = temp;
    }
    group1.clear();
    group2.clear();
    memset(team, 0, sizeof(team));
  }

  if (min_ret != INT_MAX) cout << min_ret;
  else cout << -1;
}