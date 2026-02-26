#include <bits/stdc++.h>

using namespace std;

int n, k;

int visited[100005][3];

queue<int> qu;
stack<int> st;
int main() {
  cin >> n >> k;

  qu.push(n);
  visited[n][0] = 1;

  while (qu.size()) {
    int cur = qu.front();
    qu.pop();
    if (cur == k) break;
    int next_pos[3] = {cur + 1, cur - 1, cur * 2};

    for(int i = 0; i < 3; i++) {
      int next = next_pos[i];
      if (next >= 0 && next <= 100000 && !visited[next][0]) {
        qu.push(next);
        visited[next][0] = visited[cur][0] + 1;
        visited[next][1] = cur;
        visited[cur][2] = next;
      }
    }
  }

  int i = k;
  while (visited[i][1] && visited[i][1] != n) {
    st.push(visited[i][1]);
    i = visited[i][1];
  }

  cout << visited[k][0] - 1 << '\n';
  
  cout << n << ' ';

  while (st.size()) {
    cout << st.top() << ' ';
    st.pop();
  }

  if (n != k) cout << k;
}