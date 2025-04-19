#include <bits/stdc++.h>  

using namespace std;

int y, x;
char c;
int mp[105][105];
int main() {
  cin >> y >> x;

  for(int i = 0; i < y; i++) {
    for(int j = 0; j < x; j++) {
      cin >> c;
      if (c == 'c') mp[i][j] = 0;
      else if (c == '.') mp[i][j] = -1;
    }
  }
  int i = 0, j = 0;
  while (i < y) {
    j = 0;
    while (j < x) {
      if (mp[i][j] == 0) {
        while (mp[i][++j] != 0 && j < x) {
          mp[i][j] = mp[i][j - 1] + 1;
        }
      } else j++;
    }
    i++;
  }

  for(int i = 0; i < y; i++) {
    for(int j = 0; j < x; j++) {
      cout << mp[i][j] << ' ';
    }
    cout << '\n';
  }
}