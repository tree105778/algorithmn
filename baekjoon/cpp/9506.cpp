#include <bits/stdc++.h>

using namespace std;

int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    int sum = 0;
    vector<int> v;

    cin >> n;

    if (n == -1) break;
    for(int i = 1; i <= n / 2; i++) {
      if (n % i == 0) {
        v.push_back(i);
        sum += i;
      }
    }

    if (sum == n) {
      cout << n << " = ";
      for(int i = 0; i < v.size(); i++) {
        if (i != v.size() - 1) cout << v[i] << " + ";
        else cout << v[i];
      }
      cout << '\n';
    } else {
      cout << n << " is NOT perfect." << '\n';
    }
  }
}