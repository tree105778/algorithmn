#include <bits/stdc++.h>

using namespace std;

string s, new_str, result;
map<char, int> m;
vector<char> vs;
int cnt;
int main() {
  cin >> s;
  for(char ch : s) {
    m[ch]++;
  }
  for(auto p : m) {
    cnt = p.second / 2;
    m[p.first] = p.second - 2 * cnt;
    for(int i = 0; i < cnt; i++) new_str += p.first;
  }
  cnt = 0;
  for(auto p : m) {
    if (p.second == 1) {
      vs.push_back(p.first);
      cnt++;
    }
  }
  if (cnt % 2 == 1) {
    for(char c : vs) new_str += c;
  }
  if (s.size() % 2 == 0 && (new_str.size() == s.size() / 2)) {
    result += new_str;
    reverse(new_str.begin(), new_str.end());
    result += new_str;
  } else if (s.size() % 2 == 1 && (new_str.size() == s.size() / 2 + 1)) {
    result += new_str;
    new_str = new_str.substr(0, new_str.size() - 1);
    reverse(new_str.begin(), new_str.end());
    result += new_str;
  } else {
    result += "I'm Sorry Hansoo";
  }
  cout << result;

  return 0;
}