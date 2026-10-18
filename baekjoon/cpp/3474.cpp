#include <bits/stdc++.h>

using namespace std;

int t, n;
int cnt;

int main() {
  cin >> t;

  for(int i = 0; i < t; i++) {
    // 시간 초과를 해서 아래 두 문장을 코드로 초과했는데 넉넉하게 통과했다? 왜 그럴까?
    ios_base::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cnt = 0;
    for(int j = 5; j <= n; j *= 5) {
      cnt = cnt + n / j;
    }
    cout << cnt << '\n';
  }

  return 0;
}