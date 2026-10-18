#include <bits/stdc++.h>

using namespace std;

string s;
int idx, result, num, start;
vector<int> v;
vector<char> op;
int main() {
  cin >> s;

  while (idx < s.size()) {
    if (s[idx] == '+' || s[idx] == '-') {
      v.push_back(stoi(s.substr(start, idx - start)));
      start = idx + 1;
      op.push_back(s[idx]);
    }
    idx++;
  }

  v.push_back(stoi(s.substr(start)));
  
  result = v[0];
  bool flag = false;
  for(int i = 0; i < op.size(); i++) {
    if (op[i] == '+') {
      if (flag) result -= v[i + 1];
      else result += v[i + 1];
    } else if (op[i] == '-') {
      result -= v[i + 1];
      flag = true;
    }
  }
  cout << result;
}