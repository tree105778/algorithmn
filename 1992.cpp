#include <bits/stdc++.h>

using namespace std;

// 너무 어렵게 생각한 듯 하다 4개 단위에서 처리하고 괄호 처리도 어렵게 생각한 듯 하다.

int n;
int mp[100][100];
string s;

void compress(int x, int y, int size) {
  if (size == 1) {
    cout << mp[x][y];
    return;
  }
  bool sameFlag = true;
  for(int i = x; i < x + size; i++) {
    for(int j = y; j < y + size; j++) {
      if (mp[i][j] != mp[x][y]) {
        sameFlag = false;
        break;
      }
    }
  }

  if (sameFlag) {
    cout << mp[x][y];
    return;
  }
  cout << '(';
  compress(x, y, size / 2);
  compress(x, y + size / 2, size / 2);
  compress(x + size / 2, y, size / 2);
  compress(x + size / 2, y + size / 2, size / 2);
  cout << ')';
}

int main() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> s;
    for(int j = 0; j < n; j++) {
      mp[i][j] = s[j] - '0';
    }
  }

  compress(0, 0, n);
}