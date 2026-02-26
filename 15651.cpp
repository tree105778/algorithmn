#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> v;
void search() {
  if (v.size() == M) {
    for(auto& i: v) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i = 1; i <= N; i++) {
    v.push_back(i);
    search();
    v.pop_back();
  }
 }

int main() {
  cin >> N >> M;

  search();
}