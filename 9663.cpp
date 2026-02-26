#include <bits/stdc++.h>

using namespace std;

int N, cnt;

vector<pair<int, int>> v;

bool check(int n) {
  for(int i = 0; i < n; i++) {
    int ny = v[n].first - v[i].first;
    int nx = v[n].second - v[i].second;
    if (ny == 0 || nx == 0) return false;
    if (abs(ny) == abs(nx)) return false;
  }

  return true;
}

void search(int n) {
  if (v.size() == N) {
    cnt++;
    return;
  }

  for(int i = 0; i < N; i++) {
    v.push_back({n, i});
    if (v.size() > 1 && !check(n)) {
      v.pop_back();
      continue;
    }
    search(n + 1);
    v.pop_back();
  }
}
int main() {
  cin >> N;
  search(0);
  cout << cnt;
}