#include <bits/stdc++.h>

using namespace std;

int n, idx;
string s, ret;
int alphabet[26];
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s;
    int idx = s.front() - 'a';
    alphabet[idx]++;
  }
  for(int i = 0; i < 26; i++) {
    if (alphabet[i] >= 5) ret += alphabet[i];
  }
  if (ret.size()) cout << ret << '\n';
  else cout << "PREDAJA" << '\n';
}