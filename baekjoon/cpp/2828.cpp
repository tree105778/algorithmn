#include <bits/stdc++.h>

using namespace std;

int n, m, p, num;
queue<int> q;
pair<int, int> pa;
int ret;
int main() {
  cin >> n >> m;
  cin >> p;

  for(int i = 0; i < p; i++) {
    cin >> num;
    q.push(num);
  }

  pa.first = 1; pa.second = m;
  while (q.size()) {
    if (pa.first <= q.front() && (pa.first + pa.second - 1) >= q.front()) {
      q.pop();
    } else {
      pa.first + pa.second - 1 < q.front() ? pa.first++ : pa.first--;
      ret++;
    }
  }

  cout << ret;
  return 0;
}