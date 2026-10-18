#include <bits/stdc++.h>

using namespace std;

string s;
string first_slice, last_slice;
int main() {
  cin >> s;
  if (s.size() % 2 == 0) {
    first_slice = s.substr(0, s.size() / 2);
    last_slice = s.substr(s.size() / 2);
  } else {
    first_slice = s.substr(0, s.size() / 2 + 1);
    last_slice = s.substr(s.size() / 2);
  }
  reverse(last_slice.begin(), last_slice.end());
  if (first_slice == last_slice) cout << 1;
  else cout << 0;

  return 0;
}