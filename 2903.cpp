#include <bits/stdc++.h>

using namespace std;

int n, ret, a[20];
int main() {
  cin >> n;

  a[0] = 4;
  for(int i = 1; i <= n; i++) {
    int rect = pow(4, i - 1);
    a[i] = a[i - 1] + 2 * sqrt(rect) * (sqrt(rect) + 1) + rect;
  }
  
  cout << a[n];

  return 0;
}