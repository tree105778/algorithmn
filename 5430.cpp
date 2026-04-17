#include <bits/stdc++.h>

using namespace std;

int t, n;
string p, s;
deque<string> dq;
bool rev, error;

void split(string input, string delimiter) {
  if (input.empty()) return;
  int start = 0, pos = 0;
  string token = "";
  while ((pos = input.find(delimiter, start)) != string::npos) {
    token = input.substr(start, pos - start);
    dq.push_back(token);
    start = pos + delimiter.size();
  }
  dq.push_back(input.substr(start));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  for(int i = 0; i < t; i++) {
    error = false;
    rev = false;
    cin >> p >> n >> s;
    s.pop_back();
    split(s.substr(1), ",");
    for(auto& ch: p) {
      if (ch == 'R') rev^=1;
      else if (ch == 'D') {
        if (dq.empty()) {
          cout << "error" << '\n';
          error = true;
          break;
        }
        if (rev) dq.pop_back();
        else dq.pop_front();
      }
    }
    if (error) continue;
    cout << '[';
    while (!dq.empty()) {
      if (rev) {
        cout << dq.back();
        dq.pop_back();
      } else {
        cout << dq.front();
        dq.pop_front();
      }
      if (!dq.empty()) cout << ',';
    }
    cout << ']' << '\n';
  }
}