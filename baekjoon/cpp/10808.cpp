#include <bits/stdc++.h>
using namespace std;
int a[26], idx;
string s;
int main() {
  cin >> s;
  for(char c : s) {
    idx = c - 'a';
    a[idx]++;
  }
  for(int i : a) cout << i << " ";
  return 0;
}