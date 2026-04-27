#include <bits/stdc++.h>

using namespace std;

int x, y, w, h;
int main() {
  cin >> x >> y >> w >> h;

  cout << min({x, y, w - x, h - y});
}