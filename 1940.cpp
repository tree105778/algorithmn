#include <bits/stdc++.h>

using namespace std;

int n, m, a[15004], cnt;
vector<int> v;
void combi(int start, vector<int>& v) {
  if (v.size() == 2) {
    if (v[0] + v[1] == m){ 
      cnt++;
      cout << v[0] << ' ' << v[1] << '\n';
    }
    return;
  }
  for(int i = start + 1; i < n; i++) {
    v.push_back(a[i]);
    combi(i, v);
    v.pop_back();
  }
}
int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
  combi(-1 , v);
  cout << cnt;
  return 0;
}