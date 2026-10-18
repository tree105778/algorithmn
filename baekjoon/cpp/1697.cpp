#include <bits/stdc++.h>

using namespace std;

queue<int> q;
int n, k;
int dist[100005];

// 인덱스 아웃 오브 조심
int main() {
  cin >> n >> k;

  q.push(n);

  while (q.size() && q.front() != k) {
    int num = q.front();
    q.pop();

    if (num - 1 >= 0 && !dist[num - 1]) {
      dist[num - 1] = dist[num] + 1;
      q.push(num - 1);
    }

    if (num + 1 <= 100000 && !dist[num + 1]) {
      dist[num + 1] = dist[num] + 1;
      q.push(num + 1);
    }

    if (num * 2 <= 100000 && !dist[num * 2]) {
      dist[num * 2] = dist[num] + 1;
      q.push(num * 2);
    }
  }

  cout << dist[k];
}