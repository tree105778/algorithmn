#include <bits/stdc++.h>

using namespace std;

int n, start;
int main() {
  while (cin >> n) {
    int result = 1;
    start = 1;
    while (1) {
      if (start % n == 0) break;
      start = start * 10 + 1;
      start = start % n;
      result++;
    }
    cout << result << '\n';
  }
}