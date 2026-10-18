#include <bits/stdc++.h>

using namespace std;

int bascket[104];
int n, m, i, j, k;
int main() {
  cin >> n >> m;
  for(int a = 0; a < m; a++) {
    cin >> i >> j >> k;
    for(int b = i - 1; b <= j - 1; b++) {
      bascket[b] = k;
    }
  }

  for(int a = 0; a < n; a++) cout << bascket[a] << " ";
}
