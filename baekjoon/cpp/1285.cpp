#include <bits/stdc++.h>

using namespace std;

int n;
int a[20];
int min_ret = INT_MAX;
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int value = 0;
    for(int j = 0; j < n; j++) {
      if (s[j] == 'T') {
        value |= (1 << j);
      }
    }
    a[i] = value;
  }

  for(int i = 0; i < (1 << n); i++) {
    int sum = 0;
    for(int j = 0; j < n; j++) {
      int t_cnt = 0;

      for(int k = 0; k < n; k++) {
        int current_coin = (a[k] & (1 << j)) ? 1 : 0;

        if (i & (1 << k)) {
          current_coin ^= 1;
        }

        if (current_coin == 1) t_cnt++;
      }

      sum += min(t_cnt, n - t_cnt);
    }

    min_ret = min(min_ret, sum);
  }

  cout << min_ret;
}