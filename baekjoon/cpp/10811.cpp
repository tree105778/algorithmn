#include <bits/stdc++.h>

using namespace std;

int bracket[104];
int n, m, a, b;
int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) bracket[i] = i;
  for(int i = 0; i < m; i++) {
    cin >> a >> b; 
    reverse(bracket + a, bracket + b + 1);
  }
  for(int i = 1; i <= n; i++) cout << bracket[i] << " ";

  return 0;
}