#include <bits/stdc++.h>

using namespace std;

int t, n, result;
string s, category;
unordered_map<string, int> um;
int main() {
  cin >> t;
  for(int i = 0; i < t; i++) {
    result = 1;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++) {
      getline(cin, s);
      int idx = s.find_last_of(" ");
      if (idx == string::npos) category = s;
      else category = s.substr(idx + 1);
      um[category]++;
    }
    for(pair<string, int> e : um) {
      result *= (e.second + 1);
    }
    cout << result - 1 << '\n';
    um.clear();
  }
}