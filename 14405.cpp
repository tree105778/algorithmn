#include <bits/stdc++.h>

using namespace std;

string s;
bool ret = true;
int main() {
  cin >> s;

  while (s.size()) {
    if (s.substr(0, 2) == "pi" || s.substr(0, 2) == "ka") {
      s.erase(0, 2);
    } else if (s.substr(0, 3) == "chu") {
      s.erase(0, 3);
    } else {
      ret = false;
      break;
    }
  }
  if (ret) cout << "YES";
  else cout << "NO";
}