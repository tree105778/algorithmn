#include <bits/stdc++.h>

using namespace std;

int n;
string s_i;
int main() {
  cin >> n;
  for(int i = 666, j = 1; j <= n; i++) {
    s_i = to_string(i);
    if (s_i.find("666") != string::npos) j++;
  }

  cout << s_i;
}