#include <bits/stdc++.h>

using namespace std;

int n, k, t = 0;
int visited[2][500005]; 
queue<int> qu;

int main() {
  cin >> n >> k;

  if (n == k) {
    cout << 0;
    return 0;
  }

  qu.push(n);
  visited[0][n] = 1;

  while (qu.size()) {
    k += t;
    
    if (k > 500000) break;
    
    if (visited[t % 2][k]) {
      cout << t;
      return 0;
    }

    int q_size = qu.size();
    while (q_size--) {
      int cur = qu.front();
      qu.pop();

      int next_position[] = {cur - 1, cur + 1, cur * 2};
      for(int i = 0; i < 3; i++) {
        int next_pos = next_position[i];
        
        if (next_pos >= 0 && next_pos <= 500000 && !visited[(t + 1) % 2][next_pos]) {
          visited[(t + 1) % 2][next_pos] = 1;
          qu.push(next_pos);
        }
      }
    }
    t++;
  }

  cout << -1;
}