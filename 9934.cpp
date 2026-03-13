#include <bits/stdc++.h>

using namespace std;

int k, level;
int ret[1030];
vector<int> v[10];

void make_tree(int start, int end, int depth) {
  if (start > end) return;

  int mid = (start + end) / 2;
  v[depth].push_back(ret[mid]);
  make_tree(start, mid - 1, depth + 1);
  make_tree(mid + 1, end, depth + 1);
}
int main() {
  cin >> k;

  level = pow(2, k) - 1;

  for(int i = 0; i < level; i++) {
    cin >> ret[i];
  }

  make_tree(0, level - 1, 0);

  for(int i = 0; i < k; i++) {
    for(auto& j: v[i]) {
      cout << j << ' ';
    }
    cout << '\n';
  }
  
}