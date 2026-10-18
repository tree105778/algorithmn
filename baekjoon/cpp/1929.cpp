#include <bits/stdc++.h>

using namespace std;

int n, m;
bool che[1000000];
int main() {
  cin >> n >> m;

  int range = (int)sqrt(m);
  che[1] = 1;
  for(int i = 2; i <= range; i++) {
    if (!che[i]) {
      for(int j = i * 2; j <= m; j+=i) {
        if (che[j]) continue;
        else che[j] = 1;
      }
    }
  }
  
  for (int i = n; i <= m; i++) {
    if (!che[i]) cout << i << '\n';
  }
}