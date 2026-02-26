#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> v;

void combi(int n) {
  if (v.size() == M) {
    for(auto& i: v) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i = n; i <= N; i++) {
    v.push_back(i);
    combi(i + 1);
    v.pop_back();
  }
}
int main() {
  cin >> N >> M;

  combi(1);
}