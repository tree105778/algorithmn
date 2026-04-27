#include <bits/stdc++.h>

using namespace std;

int a[9][9], max_ret, ret_x, ret_y;
int main() {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cin >> a[i][j];
      if (a[i][j] > max_ret) {
        max_ret = a[i][j];
        ret_x = i;
        ret_y = j;
      }
    }
  }

  cout << max_ret << '\n' << ret_x + 1 << ' ' << ret_y + 1;

  return 0;
}