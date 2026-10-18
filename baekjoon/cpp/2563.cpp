#include <bits/stdc++.h>

using namespace std;

int n, rec[105][105], ret;

int main() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for(int j = a; j < a + 10; j++) {
      for(int k = b; k < b + 10; k++) rec[j][k] = 1;
    }
  }

  for(int i = 1; i < 100; i++) {
    for(int j = 1; j < 100; j++) {
      if (rec[i][j] == 1) ret++;
    }
  }

  cout << ret;

  return 0;
}