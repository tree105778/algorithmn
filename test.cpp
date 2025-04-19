#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<string> v;

bool compare(string& s1, string& s2) {
  if (s1.size() != s2.size()) return s1.size() - s2.size();
  return s1 < s2;
}

int main() {
  char c;
  string s = "";
  for(int i = 0; i < 5; i++) {
    cin >> c;
    s += c;
  }

  cout << s;
}