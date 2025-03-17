#include <bits/stdc++.h>

using namespace std;

//  너무 어렵다 별표다!! 맵을 활용할 생각을 못한 게 폐인인듯 하다.
int n, m;
unordered_map<string, int> um;
vector<string> pocketmon;
string s;
bool isNumeric(const string& str) {
  for (char c: str) {
    if (isdigit(c) == 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  um.reserve(n);
  pocketmon.reserve(n);
  for(int i = 0; i < n; i++) {
    cin >> s;
    um[s] = i + 1;
    pocketmon.push_back(s);
  }
  for(int i = 0; i < m; i++) {
    cin >> s;
    if (isdigit(s.front())) {
      int num = stoi(s);
      cout << pocketmon[num - 1] << '\n';
    } else {
      cout << um[s] << '\n';
    }
  }
}