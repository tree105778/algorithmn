#include <bits/stdc++.h>

using namespace std;

int n, ret;
string s;
int main() {
  cin >> s >> n;

  for(int i = 0; i < s.size(); i++) {
    int check = s[s.size() - i - 1] - '0';
    if (check >= 0 && check < 10) {
      ret += (check * pow(n, i));
    } else {
      ret += (((s[s.size() - i - 1] - 'A') + 10) * pow(n, i));
    }
  }

  cout << ret;

  return 0;
}