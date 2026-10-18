#include <bits/stdc++.h>

using namespace std;

// 짱 어려웠따 ㅠㅠ
// long long calc(int n, int m, int mod) {
//   int B;
//   if (m == 0) return 1;
//   if (m == 1) return n % mod;
//   B = calc(n, m / 2, mod) % mod;
//   if (m % 2 == 1) {
//     return (B * B * n) % mod;
//   } else {
//     return (B * B) % mod;
//   }
// }

long long calc(int n, int m, int mod) {
  long long B;
  if (m == 1) return n % mod;
  B = calc(n, m / 2, mod);
  return m % 2 ? (B * B % mod) * n % mod : (B * B) % mod;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << calc(a, b, c);
}