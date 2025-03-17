#include <bits/stdc++.h>

using namespace std;

int n, idx;
string s;
int alphabet[26];
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s;
    int idx = s.front() - 'a';
    alphabet[idx]++;
  }
  auto idx = find_if(alphabet, alphabet + 26, [](int n) { return n >= 5; });
  if (idx == end(alphabet)) cout << "PREDAJA" << '\n';
  else {
    for(int i = 0; i < 26; i++) {
      if (alphabet[i] >= 5) cout << (char) (i + 'a');
    }
  }
}