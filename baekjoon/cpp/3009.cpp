#include <bits/stdc++.h>

using namespace std;

int a1, a2, b1, b2, c1, c2;
int main() {
  cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

  int nx = a1 - b1;
  int ny = a2 - b2;

  cout << c1 + nx << ' ' << c2 + ny;

  return 0;
}