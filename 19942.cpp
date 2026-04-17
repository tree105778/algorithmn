#include <bits/stdc++.h>

using namespace std;


int n, min_price = INT_MAX;
int cond[4];
int a[20][5];
int temp[5];
bool flag;
vector<int> v, ret;
int main() {
  cin >> n;

  for(int i = 0; i < 4; i++) {
    cin >> cond[i];
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < (1 << n); i++) {
    for(int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        for(int k = 0; k < 5; k++) {
          temp[k] += a[j][k];
        }
        v.push_back(j);
      }
    }
    flag = true;
    for(int j = 0; j < 4; j++) {
      if (temp[j] < cond[j]) flag = false;
    }
    if (flag) {
      if (temp[4] < min_price) {
        min_price = temp[4];
        ret = v;
      } else if (temp[4] == min_price) {
        if (v < ret) {
          ret = v;
        }
      }
    }
    memset(temp, 0, sizeof(temp));
    v.clear();
  }

  if (ret.empty()) cout << -1;
  else {
    cout << min_price << '\n';

    for(auto i: ret) {
      cout << i + 1 << ' ';
    }
  }
}