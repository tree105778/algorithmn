#include <bits/stdc++.h>

using namespace std;

int N, M;

int visited[10];
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
    if (!visited[i]) {
      v.push_back(i);
      visited[i] = 1;
      search();
      v.pop_back();
      visited[i] = 0;
    }
  }
}
int main() {
  cin >> N >> M;

  search();
}