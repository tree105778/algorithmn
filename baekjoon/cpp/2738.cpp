#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[105][105];
int b[105][105];
int ret[105][105];
int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> b[i][j];
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      ret[i][j] = a[i][j] + b[i][j];
      cout << ret[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}