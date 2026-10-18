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

int a[9], totalSum;
vector<int> v;
pair<int, int> ret;

void print() {
  for(int i = 0; i < 9; i++) cout << a[i] << " ";
  cout << '\n';
}

void makePermutaion(int n, int r, int depth) {
  if (depth == r) {
    print();
    return;
  }
  for(int i = depth; i < n; i++) {
    swap(a[i], a[depth]);
    makePermutaion(n, r, depth + 1);
    swap(a[i], a[depth]);
  }
}

void solve() {
  for(int i = 0; i < 9; i++) {
    cin >> a[i]; totalSum += a[i];
  }
  sort(a, a + 9);
  for(int i = 1; i < 9; i++) {
    for(int j = 0; j < i; j++) {
      if (totalSum - a[i] - a[j] == 100) {
        ret = {i, j};
        for(int i : v) cout << i << '\n';
        return;
      }
    }
  }
}

int main() {
  for(int i = 0; i < 9; i++) cin >> a[i];
  makePermutaion(9, 7, 0);
  return 0;
}