#include <bits/stdc++.h>

using namespace std;

string s;
int t;
int main() {
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> s;
    cout << s.front() << s.back() << '\n';
  }
  
  return 0;
}