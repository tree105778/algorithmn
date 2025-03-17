#include <bits/stdc++.h>

using namespace std;

int n, m, num, result;
vector<int> v;
int main() {
  cin >> n >> m;
  v.reserve(n);
  for(int i = 0; i < n; i++) {
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());
  for(int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (v[i] + v[j] == m) result++;
    }
  }
  cout << result;

  return 0;
}