#include <bits/stdc++.h>

using namespace std;

string s;
int main() {
  for(int i = 0; i < 100; i++) {
    if (!getline(cin, s)) break;
    if (s.empty()) break;
    cout << s << endl;
  }

  return 0;
}