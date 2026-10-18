#include <bits/stdc++.h>

using namespace std;

int N, cnt;

vector<pair<int, int>> v;

bool check() {
  for(auto& i: v) {
    cout << i.first << ' ' << i.second << '\n';
  }
  cout << '\n';
  for(auto& i : v) {
    for(auto& j : v) {
      int ny = i.first - j.first;
      int nx = i.second - j.second;

      if (ny == 0 && nx == 0) continue;
      if (ny == 0 || nx == 0) return false;
      if (abs(ny) == abs(nx)) return false;
    }
  }

  return true;
}

void search(int n) {
  if (v.size() > 1 && !check()) return;
  if (v.size() == N) {
    cnt++;
    return;
  }

  for(int i = n; i < N * N; i++) {
    v.push_back({i / N, i % N});
    search(i + 1);
    v.pop_back();
  }
}
int main() {
  cin >> N;
  search(0);
  cout << cnt << '\n';
}