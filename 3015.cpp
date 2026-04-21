#include <bits/stdc++.h>

using namespace std;

int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  stack<pair<int, int>> st;
  long long total_pairs = 0;

  for(int i = 0; i < n; i++) {
    int height;
    cin >> height;

    int same_height_cnt = 1;

    while (!st.empty() && st.top().first <= height) {
      total_pairs += st.top().second;

      if (st.top().first == height) same_height_cnt += st.top().second;

      st.pop();
    }

    if (!st.empty()) {
      total_pairs++;
    }

    st.push({height, same_height_cnt});
  }

  cout << total_pairs;

  return 0;
}