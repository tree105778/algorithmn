#include <bits/stdc++.h>

using namespace std;

// 1차 시도
/*
int a[9];
vector<int> v;
void solve() {
  for(int i = 0; i < 9; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  int totalSum = accumulate(v.begin(), v.end(), 0);
  for(int i = 1; i < 9; i++) {
    for(int j = 0; j < i; j++) {
      if (totalSum - v[i] - v[j] == 100) {
        v.erase(v.begin() + j);
        v.erase(v.begin() + i);
      }
    }
  }
  for(int i : v) cout << i << '\n';
  
}

int main() {
  solve();
  return 0;
}
*/

int a[9];
vector<int> v;
void solve() {
  for(int i = 0; i < 9; i++) {
    cin >> a[i];
  }
  sort(a, a + 9);
  int totalSum = accumulate(a, a + 9, 0);
  for(int i = 1; i < 9; i++) {
    for(int j = 0; j < i; j++) {
      if (totalSum - a[i] - a[j] == 100) {
        for(int k = 0; k < 9; k++) {
          if (k != j && k != i) {
            v.push_back(a[k]);
          }
        }
        for(int i : v) cout << i << '\n';
        return;
      }
    }
  }
}

int main() {
  solve();
  return 0;
}