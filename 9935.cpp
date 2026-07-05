#include <bits/stdc++.h>

using namespace std;

string s, bomb;

void bombStr(string& input, string delimeter) {
  auto start = 0;
  auto end = input.find(delimeter);
  while (end != string::npos) {
    input.replace(end, delimeter.length(), "");
    start = end;
    end = input.find(delimeter, start);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s >> bomb;

  while (s.find(bomb) != string::npos) bombStr(s, bomb);

  if (s.size()) cout << s;
  else cout << "FRULA";

  return 0;
}