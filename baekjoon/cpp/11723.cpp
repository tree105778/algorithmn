#include <bits/stdc++.h>

using namespace std;

int m, s, temp;
string cmd;
int main() {
  ios::sync_with_stdio(false);
	cin.tie(0);
  
  cin >> m;

  for(int i = 0; i < m; i++) {
    cin >> cmd;
    if (cmd == "add") {
      cin >> temp;
      s |= (1 << temp);
    } else if (cmd == "remove") {
      cin >> temp;
      s &= ~(1 << temp);
    } else if (cmd == "check") {
      cin >> temp;
      if (s & (1 << temp)) cout << 1;
      else cout << 0;
      cout << '\n';
    } else if (cmd == "toggle") {
      cin >> temp;
      s ^= (1 << temp);
    } else if (cmd == "all") {
      s = (1 << 22) - 1;
    } else if (cmd == "empty") {
      s = 0;
    }
  }
}